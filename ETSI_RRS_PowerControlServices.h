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
    float txPowerLevel;
    float rxGain;

public:
    ETSI_RRS_PowerControlServices(ETSI_RRS_USRP_Device&);
    void set_maxTxPowerLevel(float);
    void set_txPowerLevel(float);
    void set_rxGain(float);
    float get_maxTxPowerLevel();
    float get_txPowerLevel();
    float get_rxGain();
    ~ETSI_RRS_PowerControlServices();


};


#endif //RRS_CLION_POWERCONTROLSERVICES_H
