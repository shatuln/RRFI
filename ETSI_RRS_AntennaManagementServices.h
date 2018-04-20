//
// Antenna Management Services header
//

#ifndef RRS_CLION_ANTENNAMANAGEMENTSERVICES_H
#define RRS_CLION_ANTENNAMANAGEMENTSERVICES_H

using namespace std;

class ETSI_RRS_AntennaManagementServices {

private:
    int txAntennaPort;
    int rxAntennaPort;

public:
    ETSI_RRS_AntennaManagementServices();
    void set_txAntennaPort(int);
    int get_txAntennaPort();
    void set_rxAntennaPort(int);
    int get_rxAntennaPort();
    ~ETSI_RRS_AntennaManagementServices();

};


#endif //RRS_CLION_ANTENNAMANAGEMENTSERVICES_H
