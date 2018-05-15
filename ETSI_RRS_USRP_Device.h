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
    string deviceArgs = "";
    string ref = "internal";
    string subdev = "A:A";
    string rx_ant = "TX:RX";
    string tx_ant = "TX:RX";
    uhd::usrp::multi_usrp::sptr usrp;

};


#endif //RRS_CLION_ETSI_RRS_USRPDEVICE_H
