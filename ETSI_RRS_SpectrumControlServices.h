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
    float sampleRate;
    string chainParameters;

public:
    ETSI_RRS_SpectrumControlServices(ETSI_RRS_USRP_Device&);
    //TODO Функция настройки частоты + проверка на рэнж частоты (freq_range)
    void set_rxCenterFrequency(double, int);
    void set_txCenterFrequency(double, int);
    double get_rxCenterFrequency();
    double get_txCenterFrequency();
    //TODO Функция настройи полосы пропускания + проверка на рэнж (bandwidth_range)
    void set_rxBandwidth(double, int);
    void set_txBandwidth(double, int);
    double get_rxBandwidth();
    double get_txBandwidth();
    //TODO Функция сэмплрейта
    void set_rxSamplingRate();
    void set_txSamplingRate();
    double get_rxSamplingRate();
    double get_txSamplingRate();
    //TODO chain param
    ~ETSI_RRS_SpectrumControlServices();


};


#endif //RRS_CLION_SPECTRUMCONTROLSERVICES_H
