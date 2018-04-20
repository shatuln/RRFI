//
// Spectrum Control Services header
//

#ifndef RRS_CLION_SPECTRUMCONTROLSERVICES_H
#define RRS_CLION_SPECTRUMCONTROLSERVICES_H


#include <iostream>
#include <string>

using namespace std;

class ETSI_RRS_SpectrumControlServices {

private:
    float centreFrequency;
    float bandwidth;
    float sampleRate;
    string chainParameters;

public:
    ETSI_RRS_SpectrumControlServices();
    ~ETSI_RRS_SpectrumControlServices();

};


#endif //RRS_CLION_SPECTRUMCONTROLSERVICES_H
