//
// Antenna Management Services header
//

#ifndef RRS_CLION_ANTENNAMANAGEMENTSERVICES_H
#define RRS_CLION_ANTENNAMANAGEMENTSERVICES_H

#include "ETSI_RRS_USRP_Device.h"

using namespace std;

class ETSI_RRS_AntennaManagementServices {

private:
    string txAntennaPort;
    string rxAntennaPort;
    ETSI_RRS_USRP_Device *usrpDevice;

public:
    ETSI_RRS_AntennaManagementServices(ETSI_RRS_USRP_Device&);
    bool set_txAntennaPort(int, int);
    string get_txAntennaPort(int);
    bool set_rxAntennaPort(int, int);
    string get_rxAntennaPort(int);
    string decode_tx_port_num(int); //decode to string name of antenna
    string decode_rx_port_num(int); //decode to string name of antenna
    ~ETSI_RRS_AntennaManagementServices();

};


#endif //RRS_CLION_ANTENNAMANAGEMENTSERVICES_H
