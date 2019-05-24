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
    string chainParameters;

public:
    ETSI_RRS_SpectrumControlServices(ETSI_RRS_USRP_Device&);
    bool set_rxCenterFrequency(double, int);
    bool set_txCenterFrequency(double, int);
    double get_rxCenterFrequency(int);
    double get_txCenterFrequency(int);
    bool set_rxBandwidth(double, int);
    bool set_txBandwidth(double, int);
    double get_rxBandwidth(int);
    double get_txBandwidth(int);
    bool set_rxSamplingRate(double, int);
    bool set_txSamplingRate(double, int);
    double get_rxSamplingRate(int);
    double get_txSamplingRate(int);
    ~ETSI_RRS_SpectrumControlServices();


};


#endif //RRS_CLION_SPECTRUMCONTROLSERVICES_H
