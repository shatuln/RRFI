//
// Class for global USRP device parameters
//

#ifndef RRS_CLION_ETSI_RRS_USRPDEVICE_H
#define RRS_CLION_ETSI_RRS_USRPDEVICE_H
#include <uhd/usrp/multi_usrp.hpp>

using namespace std;

class ETSI_RRS_USRP_Device {

public:
    ETSI_RRS_USRP_Device(); //first config of usrp device
    void changeChannel(size_t);

    string deviceArgs = "";
    string ref = "internal";
    string subdev = "A:B";
    string rx_ant = "TX:RX";
    string tx_ant = "TX:RX";
    double rx_gain = 0;
    double tx_gain = 0;
    double max_rx_gain, min_rx_gain, max_tx_gain, min_tx_gain;
    double max_rx_bandwidth, min_rx_bandwidth, max_tx_bandwidth, min_tx_bandwidth;
    double max_rx_frequency, min_rx_frequency, max_tx_frequency, min_tx_frequency;
    double min_tx_rate, max_tx_rate, min_rx_rate, max_rx_rate;
    uhd::usrp::multi_usrp::sptr usrp;

    uhd::tx_streamer::sptr tx_stream;
    uhd::rx_streamer::sptr rx_stream;
    uhd::tx_metadata_t tx_md;
    uhd::rx_metadata_t rx_md;
    uhd::stream_args_t tx_stream_args;
    uhd::stream_args_t rx_stream_args;
    size_t tx_samps_per_buff;
    size_t rx_samps_per_buff;
    string tx_filename;
    string rx_filename;

};


#endif //RRS_CLION_ETSI_RRS_USRPDEVICE_H
