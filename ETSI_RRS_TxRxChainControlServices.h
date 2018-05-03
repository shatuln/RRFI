//
// Tx/Rx Chain Control Services header
//

#ifndef RRS_CLION_TXRXCHAINCONTROLSERVICES_H
#define RRS_CLION_TXRXCHAINCONTROLSERVICES_H

#include "ETSI_RRS_USRP_Device.h"

using namespace std;

class ETSI_RRS_TxRxChainControlServices {

private:
    int txStartTime;
    int txStopTime;
    int rxStartTime;
    int rxStopTime;

public:
    ETSI_RRS_TxRxChainControlServices(ETSI_RRS_USRP_Device&);
    ~ETSI_RRS_TxRxChainControlServices();

};


#endif //RRS_CLION_TXRXCHAINCONTROLSERVICES_H
