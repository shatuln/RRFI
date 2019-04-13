//
// General ETSI_RRS_RRFI Implementation
//

#include <uhd/usrp/multi_usrp.hpp>
#include <fstream>
#include "ETSI_RRS_RRFI.h"
#include "ETSI_RRS_SpectrumControlServices.h"
#include "ETSI_RRS_AntennaManagementServices.h"
#include "ETSI_RRS_PowerControlServices.h"
#include "ETSI_RRS_TxRxChainControlServices.h"

using namespace std;
using namespace boost;

ETSI_RRS_RRFI::ETSI_RRS_RRFI(ETSI_RRS_USRP_Device &actualusrpdevice) {
    spectrumControlServices = new ETSI_RRS_SpectrumControlServices(actualusrpdevice);
    antennaManagementServices = new ETSI_RRS_AntennaManagementServices(actualusrpdevice);
    powerControlServices = new ETSI_RRS_PowerControlServices(actualusrpdevice);
    txRxChainControlServices = new ETSI_RRS_TxRxChainControlServices(actualusrpdevice);
    usrpDevice = &actualusrpdevice;
}

void sig_int_handler(int){stop_signal_called = true;}

void ETSI_RRS_RRFI::changeChannel(int actualChannel) {
    this->channel = actualChannel;
    usrpDevice->changeChannel(size_t(actualChannel));
}

//Set parameters functions implementation

void ETSI_RRS_RRFI::set_txAntennaPort(int actualTxAntennaPort) {
    antennaManagementServices->set_txAntennaPort(actualTxAntennaPort, this->channel);
    return;
}

void ETSI_RRS_RRFI::set_rxAntennaPort(int actualRxAntennaPort) {
    antennaManagementServices->set_rxAntennaPort(actualRxAntennaPort, this->channel);
    return;
}

bool ETSI_RRS_RRFI::set_maxTxPowerLevel(double actualMaxTxPowerLevel) {
    return powerControlServices->set_maxTxPowerLevel(actualMaxTxPowerLevel);
}

bool ETSI_RRS_RRFI::set_txPowerLevel(double actualTxPowerLevel) {
    return powerControlServices->set_txPowerLevel(actualTxPowerLevel, this->channel);
}

bool ETSI_RRS_RRFI::set_rxGain(double actualRxGain) {
    return powerControlServices->set_rxGain(actualRxGain, this->channel);
}

bool ETSI_RRS_RRFI::set_rxCenterFrequency(double actualRxCenterFrequency) {
    return spectrumControlServices->set_rxCenterFrequency(actualRxCenterFrequency, this->channel);
}

bool ETSI_RRS_RRFI::set_txCenterFrequency(double actualTxCenterFrequency) {
    return spectrumControlServices->set_txCenterFrequency(actualTxCenterFrequency, this->channel);
}

bool ETSI_RRS_RRFI::set_rxBandwidth(double actualRxBandwidth) {
    return spectrumControlServices->set_rxBandwidth(actualRxBandwidth, this->channel);
}

bool ETSI_RRS_RRFI::set_txBandwidth(double actualTxBandwidth) {
    return spectrumControlServices->set_txBandwidth(actualTxBandwidth, this->channel);
}

bool ETSI_RRS_RRFI::set_rxSamplingRate(double actualRxRate) {
    return spectrumControlServices->set_rxSamplingRate(actualRxRate, this->channel);
}

bool ETSI_RRS_RRFI::set_txSamplingRate(double actualTxRate) {
    return spectrumControlServices->set_txSamplingRate(actualTxRate, this->channel);
}


//Get parameters functions implementation

string ETSI_RRS_RRFI::get_txAntennaPort() {
    return antennaManagementServices->get_txAntennaPort(this->channel);
}

string ETSI_RRS_RRFI::get_rxAntennaPort() {
    return antennaManagementServices->get_rxAntennaPort(this->channel);
}

double ETSI_RRS_RRFI::get_maxTxPowerLevel() {
    return powerControlServices->get_maxTxPowerLevel();
}

double ETSI_RRS_RRFI::get_txPowerLevel() {
    return powerControlServices->get_txPowerLevel(this->channel);
}

double ETSI_RRS_RRFI::get_rxGain() {
    return powerControlServices->get_rxGain(this->channel);
}

double ETSI_RRS_RRFI::get_rxCenterFrequency() {
    return spectrumControlServices->get_rxCenterFrequency(this->channel);
}

double ETSI_RRS_RRFI::get_txCenterFrequency() {
    return spectrumControlServices->get_txCenterFrequency(this->channel);
}

double ETSI_RRS_RRFI::get_rxBandwidth() {
    return spectrumControlServices->get_rxBandwidth(this->channel);
}

double ETSI_RRS_RRFI::get_txBandwidth() {
    return spectrumControlServices->get_txBandwidth(this->channel);
}

double ETSI_RRS_RRFI::get_rxSamplingRate() {
    return spectrumControlServices->get_rxSamplingRate(this->channel);
}

double ETSI_RRS_RRFI::get_txSamplingRate() {
    return spectrumControlServices->get_txSamplingRate(this->channel);
}

void ETSI_RRS_RRFI::tx_from_file(string actualfilename, size_t samps_per_buff = 100) {
    usrpDevice->tx_samps_per_buff = samps_per_buff;
    usrpDevice->tx_filename = actualfilename;
    ifstream infile(usrpDevice->tx_filename.c_str(), ifstream::binary);
    std::vector<short> buff(usrpDevice->tx_samps_per_buff);

    while(not usrpDevice->tx_md.end_of_burst and not stop_signal_called){

        infile.read((char*)&buff.front(), buff.size()*sizeof(short));
        size_t num_tx_samps = infile.gcount()/sizeof(short);

        usrpDevice->tx_md.end_of_burst = infile.eof();

        usrpDevice->tx_stream->send(&buff.front(), num_tx_samps, usrpDevice->tx_md);
    }
    infile.close();
}

void ETSI_RRS_RRFI::change_tx_stream_args(string cpu_format, string otw_format) {
    usrpDevice->tx_stream_args.cpu_format = cpu_format;
    usrpDevice->tx_stream_args.otw_format = otw_format;
}

void ETSI_RRS_RRFI::change_rx_stream_args(string cpu_format, string otw_format) {
    usrpDevice->rx_stream_args.cpu_format = cpu_format;
    usrpDevice->rx_stream_args.otw_format = otw_format;
}

void ETSI_RRS_RRFI::rx_to_file(string actualfilename, size_t samps_per_buff, float settling_time, int num_requested_samps = 0) {
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
            break;
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

}

ETSI_RRS_RRFI::~ETSI_RRS_RRFI() {
    delete spectrumControlServices;
    delete antennaManagementServices;
    delete powerControlServices;
    delete txRxChainControlServices;

}
