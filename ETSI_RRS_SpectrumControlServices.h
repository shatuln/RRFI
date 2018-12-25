//
// Spectrum Control Services header
//

#ifndef RRS_CLION_SPECTRUMCONTROLSERVICES_H
#define RRS_CLION_SPECTRUMCONTROLSERVICES_H


#include <iostream>
#include <string>
#include "ETSI_RRS_USRP_Device.h"

using namespace std;

class ETSI_RRS_SpectrumControlServices {

private:
    ETSI_RRS_USRP_Device* usrpDevice;
    double rx_CenterFrequency;
    double tx_CenterFrequency;
    double rx_bandwidth;
    double tx_bandwidth;
    double rx_SamplingRate;
    double tx_SamplingRate;
    float sampleRate;
    string chainParameters;

public:
    ETSI_RRS_SpectrumControlServices(ETSI_RRS_USRP_Device&);
    void set_rxCenterFrequency(double, int);
    void set_txCenterFrequency(double, int);
    double get_rxCenterFrequency(int);
    double get_txCenterFrequency(int);
    void set_rxBandwidth(double, int);
    void set_txBandwidth(double, int);
    double get_rxBandwidth(int);
    double get_txBandwidth(int);
    void set_rxSamplingRate(double, int);
    void set_txSamplingRate(double, int);
    double get_rxSamplingRate(int);
    double get_txSamplingRate(int);
    //TODO chain param
    ~ETSI_RRS_SpectrumControlServices();


};


#endif //RRS_CLION_SPECTRUMCONTROLSERVICES_H
