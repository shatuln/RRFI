//
// General ETSI_RRS_RRFI header
//

#ifndef RRS_CLION_RRFI_H
#define RRS_CLION_RRFI_H


#include "ETSI_RRS_SpectrumControlServices.h"
#include "ETSI_RRS_AntennaManagementServices.h"
#include "ETSI_RRS_PowerControlServices.h"
#include "ETSI_RRS_TxRxChainControlServices.h"

using namespace std;

class ETSI_RRS_RRFI {

private:
    ETSI_RRS_SpectrumControlServices *spectrumControlServices;
    ETSI_RRS_AntennaManagementServices *antennaManagementServices;
    ETSI_RRS_PowerControlServices *powerControlServices;
    ETSI_RRS_TxRxChainControlServices *txRxChainControlServices;


public:
    ETSI_RRS_RRFI();
    //Set parameters functions
    void set_txAntennaPort(int);
    void set_rxAntennaPort(int);
    void set_maxTxPowerLevel(float);
    void set_txPowerLevel(float);
    void set_rxGain(float);

    //Get parameters functions
    int get_txAntennaPort();
    int get_rxAntennaPort();
    float get_maxTxPowerLevel();
    float get_txPowerLevel();
    float get_rxGain();

    ~ETSI_RRS_RRFI();

};


#endif //RRS_CLION_RRFI_H
