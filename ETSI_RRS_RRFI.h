//
// General ETSI_RRS_RRFI header
//

#ifndef RRS_CLION_RRFI_H
#define RRS_CLION_RRFI_H


#include "ETSI_RRS_SpectrumControlServices.h"
#include "ETSI_RRS_AntennaManagementServices.h"
#include "ETSI_RRS_PowerControlServices.h"
#include "ETSI_RRS_TxRxChainControlServices.h"

class ETSI_RRS_RRFI {

private:
    ETSI_RRS_SpectrumControlServices *SCS;
    ETSI_RRS_AntennaManagementServices *AMS;
    ETSI_RRS_PowerControlServices *PCS;
    ETSI_RRS_TxRxChainControlServices *TRCS;


public:
    ETSI_RRS_RRFI();
    ~ETSI_RRS_RRFI();

};


#endif //RRS_CLION_RRFI_H
