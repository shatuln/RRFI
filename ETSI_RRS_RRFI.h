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
        //Antenna management Services
    void set_txAntennaPort(int, int);
    void set_rxAntennaPort(int, int);
        //Power Control Services
    void set_maxTxPowerLevel(float);
    void set_txPowerLevel(double, int);
    void set_rxGain(double, int);
        //Spectrum Control Services
    void set_rxCenterFrequency(double, int);
    void set_txCenterFrequency(double, int);
    void set_rxBandwidth(double, int);
    void set_txBandwidth(double, int);
    void set_rxSamplingRate(double, int);
    void set_txSamplingRate(double, int);

        //Get parameters functions
        // Antenna management Services
    string get_txAntennaPort(int);
    string get_rxAntennaPort(int);
        //Power Control Services
    float get_maxTxPowerLevel();
    double get_txPowerLevel(double, int);
    double get_rxGain(int);
        //Spectrum Control Services
    double get_rxCenterFrequency(int);
    double get_txCenterFrequency(int);
    double get_rxBandwidth(int);
    double get_txBandwidth(int);
    double get_rxSamplingRate(int);
    double get_txSamplingRate(int);

    ~ETSI_RRS_RRFI();

};


#endif //RRS_CLION_RRFI_H
