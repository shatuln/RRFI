//
// Tx/Rx Chain Control Services implementation
//

#include <iostream>
#include <fstream>
#include <uhd/usrp/multi_usrp.hpp>
#include "ETSI_RRS_TxRxChainControlServices.h"

using namespace std;

void sig_int_handler(int){stop_signal_called = true;}

ETSI_RRS_TxRxChainControlServices::ETSI_RRS_TxRxChainControlServices(ETSI_RRS_USRP_Device &actualusrpdevice) {
    usrpDevice = &actualusrpdevice;
    cout << "Tx/Rx Chain Control Services created" << endl;
}

bool ETSI_RRS_TxRxChainControlServices::tx_from_buff(std::vector<short> buff, size_t samps_per_buff) {
    usrpDevice->tx_samps_per_buff = samps_per_buff;
    cout << "Sending bytes..." << endl;
    if (usrpDevice->tx_stream->send(&buff.front(), samps_per_buff, usrpDevice->tx_md) != samps_per_buff) {
        return false;
    }
    else {
        cout << "\e[1m" << "Bytes was sent successfully" << "\e[0m" << endl;
        return true;
    }
}

bool ETSI_RRS_TxRxChainControlServices::tx_from_file(string actualfilename, size_t samps_per_buff) {
    cout << "Sending file" << endl;
    usrpDevice->tx_samps_per_buff = samps_per_buff;
    usrpDevice->tx_filename = actualfilename;
    ifstream infile(usrpDevice->tx_filename.c_str(), ifstream::binary);
    if (!infile) {
        cout << "Cannot open file" << endl;
        return false;
    }
    std::vector<short> buff(usrpDevice->tx_samps_per_buff);
    usrpDevice->tx_md.end_of_burst = infile.eof();

    while(not usrpDevice->tx_md.end_of_burst and not stop_signal_called){

        infile.read((char*)&buff.front(), buff.size()*sizeof(short));
        size_t num_tx_samps = infile.gcount()/sizeof(short);

        usrpDevice->tx_md.end_of_burst = infile.eof();

        usrpDevice->tx_stream->send(&buff.front(), num_tx_samps, usrpDevice->tx_md);
        cout << ".";
    }
    infile.close();
    cout << "\e[1m" << "\nFile was sent successfully" << "\e[0m" << endl;
    return true;
}

void ETSI_RRS_TxRxChainControlServices::change_tx_stream_args(string cpu_format, string otw_format) {
    usrpDevice->tx_stream_args.cpu_format = cpu_format;
    usrpDevice->tx_stream_args.otw_format = otw_format;
}

void ETSI_RRS_TxRxChainControlServices::change_rx_stream_args(string cpu_format, string otw_format) {
    usrpDevice->rx_stream_args.cpu_format = cpu_format;
    usrpDevice->rx_stream_args.otw_format = otw_format;
}

std::vector<short> ETSI_RRS_TxRxChainControlServices::rx_to_buff(size_t samps_per_buff, float settling_time, int num_requested_samps) {
    usrpDevice->rx_samps_per_buff = samps_per_buff;
    float timeout = settling_time + 0.1;
    int num_total_samps = 0;
    bool overflow_message = true;
    uhd::stream_cmd_t stream_cmd((num_requested_samps == 0)?
                                 uhd::stream_cmd_t::STREAM_MODE_START_CONTINUOUS:
                                 uhd::stream_cmd_t::STREAM_MODE_NUM_SAMPS_AND_DONE
    );
    stream_cmd.num_samps = num_requested_samps;
    stream_cmd.stream_now = false;
    stream_cmd.time_spec = uhd::time_spec_t(settling_time);
    usrpDevice->rx_stream->issue_stream_cmd(stream_cmd);

    std::vector<short> buff(usrpDevice->rx_samps_per_buff);

    size_t num_rx_samps = usrpDevice->rx_stream->recv(&buff.front(), buff.size(), usrpDevice->rx_md, timeout);
    timeout = 0.1; //small timeout for subsequent recv
    cout << "Received samps = " << num_rx_samps << endl;

    if (usrpDevice->rx_md.error_code == uhd::rx_metadata_t::ERROR_CODE_TIMEOUT) {
        std::cout << boost::format("Timeout while streaming") << std::endl;
        return buff;
    }
    if (usrpDevice->rx_md.error_code == uhd::rx_metadata_t::ERROR_CODE_OVERFLOW){
        if (overflow_message){
            overflow_message = false;
            std::cerr << boost::format(
            "Got an overflow indication. Please consider the following:\n"
            "  Your write medium must sustain a rate of %fMB/s.\n"
            "  Dropped samples will not be written to the file.\n"
            "  Please modify this example for your purposes.\n"
            "  This message will not appear again.\n"
            ); //% (usrpDevice->usrp->get_rx_rate()*sizeof((short)/1e6);
        }
    }
    if (usrpDevice->rx_md.error_code != uhd::rx_metadata_t::ERROR_CODE_NONE){
        throw std::runtime_error(str(boost::format(
        "Receiver error %s"
        ) % usrpDevice->rx_md.strerror()));
    }

    return buff;
}

void ETSI_RRS_TxRxChainControlServices::rx_to_file(string actualfilename, size_t samps_per_buff, float settling_time, int num_requested_samps) {
    usrpDevice->rx_samps_per_buff = samps_per_buff;
    usrpDevice->rx_filename = actualfilename;
    float timeout = settling_time + 0.1;
    int num_total_samps = 0;
    std::ofstream outfile(usrpDevice->rx_filename.c_str(), std::ofstream::binary);
    bool overflow_message = true;
    uhd::stream_cmd_t stream_cmd((num_requested_samps == 0)?
                                 uhd::stream_cmd_t::STREAM_MODE_START_CONTINUOUS:
                                 uhd::stream_cmd_t::STREAM_MODE_NUM_SAMPS_AND_DONE
    );
    stream_cmd.num_samps = num_requested_samps;
    stream_cmd.stream_now = false;
    stream_cmd.time_spec = uhd::time_spec_t(settling_time);
    usrpDevice->rx_stream->issue_stream_cmd(stream_cmd);

    std::vector<short> buff(usrpDevice->rx_samps_per_buff);

    while(not stop_signal_called and (num_requested_samps != num_total_samps or num_requested_samps == 0)){
        size_t num_rx_samps = usrpDevice->rx_stream->recv(&buff.front(), buff.size(), usrpDevice->rx_md, timeout);
        timeout = 0.1; //small timeout for subsequent recv

        if (usrpDevice->rx_md.error_code == uhd::rx_metadata_t::ERROR_CODE_TIMEOUT) {
            std::cout << boost::format("Timeout while streaming") << std::endl;
            return;
        }
        if (usrpDevice->rx_md.error_code == uhd::rx_metadata_t::ERROR_CODE_OVERFLOW){
            if (overflow_message){
                overflow_message = false;
                std::cerr << boost::format(
                        "Got an overflow indication. Please consider the following:\n"
                        "  Your write medium must sustain a rate of %fMB/s.\n"
                        "  Dropped samples will not be written to the file.\n"
                        "  Please modify this example for your purposes.\n"
                        "  This message will not appear again.\n"
                ); //% (usrpDevice->usrp->get_rx_rate()*sizeof((short)/1e6);
            }
            continue;
        }
        if (usrpDevice->rx_md.error_code != uhd::rx_metadata_t::ERROR_CODE_NONE){
            throw std::runtime_error(str(boost::format(
                    "Receiver error %s"
            ) % usrpDevice->rx_md.strerror()));
        }

        num_total_samps += num_rx_samps;

        outfile.write((const char*)&buff.front(), num_rx_samps*sizeof(short));
    }

    outfile.close();
    return;
}

ETSI_RRS_TxRxChainControlServices::~ETSI_RRS_TxRxChainControlServices() {
    cout << "Tx/Rx Chain Control Services destroyed" << endl;

}
