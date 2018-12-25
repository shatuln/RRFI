//
// Power Control Services header
//

#ifndef RRS_CLION_POWERCONTROLSERVICES_H
#define RRS_CLION_POWERCONTROLSERVICES_H

#include "ETSI_RRS_USRP_Device.h"

using namespace std;

class ETSI_RRS_PowerControlServices {

private:
    float maxTxPowerLevel;
    double txPowerLevel;
    double rxGain;
    ETSI_RRS_USRP_Device *usrpDevice;

public:
    ETSI_RRS_PowerControlServices(ETSI_RRS_USRP_Device&);
    void set_maxTxPowerLevel(float);
    void set_txPowerLevel(double, int);
    void set_rxGain(double, int);
    float get_maxTxPowerLevel();
    double get_txPowerLevel(double, int);
    double get_rxGain(int);
    ~ETSI_RRS_PowerControlServices();


};


#endif //RRS_CLION_POWERCONTROLSERVICES_H
