//
// General ETSI_RRS_RRFI Implementation
//

#include "ETSI_RRS_RRFI.h"
#include "ETSI_RRS_SpectrumControlServices.h"
#include "ETSI_RRS_AntennaManagementServices.h"
#include "ETSI_RRS_PowerControlServices.h"
#include "ETSI_RRS_TxRxChainControlServices.h"


ETSI_RRS_RRFI::ETSI_RRS_RRFI() {
    SCS = new ETSI_RRS_SpectrumControlServices();
    AMS = new ETSI_RRS_AntennaManagementServices();
    PCS = new ETSI_RRS_PowerControlServices();
    TRCS = new ETSI_RRS_TxRxChainControlServices();
    
}

ETSI_RRS_RRFI::~ETSI_RRS_RRFI() {
    delete SCS;
    delete AMS;
    delete PCS;
    delete TRCS;

}
