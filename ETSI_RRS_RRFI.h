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
    ETSI_RRS_USRP_Device* usrpDevice;
    int channel;
    //ETSI_RRS_USRP_Device usrpDevice;


public:
    ETSI_RRS_RRFI(ETSI_RRS_USRP_Device&);

    void changeChannel(int);

        //Set parameters functions
        //Antenna management Services
    void set_txAntennaPort(int);
    void set_rxAntennaPort(int);
        //Power Control Services
    void set_maxTxPowerLevel(double);
    void set_txPowerLevel(double);
    void set_rxGain(double);
        //Spectrum Control Services
    void set_rxCenterFrequency(double);
    void set_txCenterFrequency(double);
    void set_rxBandwidth(double);
    void set_txBandwidth(double);
    void set_rxSamplingRate(double);
    void set_txSamplingRate(double);

        //Get parameters functions
        // Antenna management Services
    string get_txAntennaPort();
    string get_rxAntennaPort();
        //Power Control Services
    double get_maxTxPowerLevel();
    double get_txPowerLevel();
    double get_rxGain();
        //Spectrum Control Services
    double get_rxCenterFrequency();
    double get_txCenterFrequency();
    double get_rxBandwidth();
    double get_txBandwidth();
    double get_rxSamplingRate();
    double get_txSamplingRate();

    ~ETSI_RRS_RRFI();

};


#endif //RRS_CLION_RRFI_H
