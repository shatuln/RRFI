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

public:
    ETSI_RRS_AntennaManagementServices(ETSI_RRS_USRP_Device&);
    ETSI_RRS_USRP_Device *usrpDevice;
    void set_txAntennaPort(string);
    string get_txAntennaPort();
    void set_rxAntennaPort(string);
    string get_rxAntennaPort();
    ~ETSI_RRS_AntennaManagementServices();

};


#endif //RRS_CLION_ANTENNAMANAGEMENTSERVICES_H
