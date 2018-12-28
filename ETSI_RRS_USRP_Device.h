//
// Class for global USRP device parameters
//

#ifndef RRS_CLION_ETSI_RRS_USRPDEVICE_H
#define RRS_CLION_ETSI_RRS_USRPDEVICE_H
#include <uhd/usrp/multi_usrp.hpp>

using namespace std;

class ETSI_RRS_USRP_Device {

public:
    //TODO Номер канала загнать в usrp
    ETSI_RRS_USRP_Device(); //first config of usrp device
    void changeChannel(size_t);

    string deviceArgs = "";
    string ref = "internal";
    string subdev = "A:A";
    string rx_ant = "TX:RX";
    string tx_ant = "TX:RX";
    double rx_gain = 0;
    double tx_gain = 0;
    double max_rx_gain;
    double min_rx_gain;
    double max_tx_gain;
    double min_tx_gain;
    double max_rx_bandwidth;
    double min_rx_bandwidth;
    double max_tx_bandwidth;
    double min_tx_bandwidth;
    double max_rx_frequency;
    double min_rx_frequency;
    double max_tx_frequency;
    double min_tx_frequency;
    uhd::usrp::multi_usrp::sptr usrp;

};


#endif //RRS_CLION_ETSI_RRS_USRPDEVICE_H
