//
// General ETSI_RRS_RRFI header
//

#ifndef RRS_CLION_RRFI_H
#define RRS_CLION_RRFI_H


#include "ETSI_RRS_SpectrumControlServices.h"
#include "ETSI_RRS_AntennaManagementServices.h"
#include "ETSI_RRS_PowerControlServices.h"
#include "ETSI_RRS_TxRxChainControlServices.h"
#include "ETSI_RRS_USRP_Device.h"

using namespace std;

class ETSI_RRS_RRFI {

private:
    ETSI_RRS_SpectrumControlServices *spectrumControlServices;
    ETSI_RRS_AntennaManagementServices *antennaManagementServices;
    ETSI_RRS_PowerControlServices *powerControlServices;
    ETSI_RRS_TxRxChainControlServices *txRxChainControlServices;
    //ETSI_RRS_USRP_Device usrpDevice;


public:
    ETSI_RRS_RRFI(ETSI_RRS_USRP_Device&);
    //Set parameters functions
    void set_txAntennaPort(string);
    void set_rxAntennaPort(string);
    void set_maxTxPowerLevel(float);
    void set_txPowerLevel(float);
    void set_rxGain(float);

    //Get parameters functions
    string get_txAntennaPort();
    string get_rxAntennaPort();
    float get_maxTxPowerLevel();
    float get_txPowerLevel();
    float get_rxGain();

    ~ETSI_RRS_RRFI();

};


#endif //RRS_CLION_RRFI_H
