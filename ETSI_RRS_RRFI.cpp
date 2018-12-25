//
// General ETSI_RRS_RRFI Implementation
//

#include <uhd/usrp/multi_usrp.hpp>
#include "ETSI_RRS_RRFI.h"
#include "ETSI_RRS_SpectrumControlServices.h"
#include "ETSI_RRS_AntennaManagementServices.h"
#include "ETSI_RRS_PowerControlServices.h"
#include "ETSI_RRS_TxRxChainControlServices.h"

using namespace std;
using namespace boost;

ETSI_RRS_RRFI::ETSI_RRS_RRFI(ETSI_RRS_USRP_Device &actualusrpdevice) {
    spectrumControlServices = new ETSI_RRS_SpectrumControlServices(actualusrpdevice);
    antennaManagementServices = new ETSI_RRS_AntennaManagementServices(actualusrpdevice);
    powerControlServices = new ETSI_RRS_PowerControlServices(actualusrpdevice);
    txRxChainControlServices = new ETSI_RRS_TxRxChainControlServices(actualusrpdevice);
}

//Set parameters functions implementation

void ETSI_RRS_RRFI::set_txAntennaPort(int actualTxAntennaPort, int channel) {
    antennaManagementServices->set_txAntennaPort(actualTxAntennaPort, channel);
    return;
}

void ETSI_RRS_RRFI::set_rxAntennaPort(int actualRxAntennaPort, int channel) {
    antennaManagementServices->set_rxAntennaPort(actualRxAntennaPort, channel);
    return;
}

void ETSI_RRS_RRFI::set_maxTxPowerLevel(float actualMaxTxPowerLevel) {
    powerControlServices->set_maxTxPowerLevel(actualMaxTxPowerLevel);
}

void ETSI_RRS_RRFI::set_txPowerLevel(double actualTxPowerLevel, int channel) {
    powerControlServices->set_txPowerLevel(actualTxPowerLevel, channel);
}

void ETSI_RRS_RRFI::set_rxGain(double actualRxGain, int channel) {
    powerControlServices->set_rxGain(actualRxGain, channel);
}

void ETSI_RRS_RRFI::set_rxCenterFrequency(double actualRxCenterFrequency, int channel) {
    spectrumControlServices->set_rxCenterFrequency(actualRxCenterFrequency, channel);
}

void ETSI_RRS_RRFI::set_txCenterFrequency(double actualTxCenterFrequency, int channel) {
    spectrumControlServices->set_txCenterFrequency(actualTxCenterFrequency, channel);
}

void ETSI_RRS_RRFI::set_rxBandwidth(double actualRxBandwidth, int channel) {
    spectrumControlServices->set_rxBandwidth(actualRxBandwidth, channel);
}

void ETSI_RRS_RRFI::set_txBandwidth(double actualTxBandwidth, int channel) {
    spectrumControlServices->set_txBandwidth(actualTxBandwidth, channel);
}

void ETSI_RRS_RRFI::set_rxSamplingRate(double actualRxRate, int channel) {
    spectrumControlServices->set_rxSamplingRate(actualRxRate, channel);
}

void ETSI_RRS_RRFI::set_txSamplingRate(double actualTxRate, int channel) {
    spectrumControlServices->set_txSamplingRate(actualTxRate, channel);
}


//Get parameters functions implementation

string ETSI_RRS_RRFI::get_txAntennaPort(int channel) {
    return antennaManagementServices->get_txAntennaPort(channel);
}

string ETSI_RRS_RRFI::get_rxAntennaPort(int channel) {
    return antennaManagementServices->get_rxAntennaPort(channel);
}

float ETSI_RRS_RRFI::get_maxTxPowerLevel() {
    return powerControlServices->get_maxTxPowerLevel();
}

double ETSI_RRS_RRFI::get_txPowerLevel(double actualTxGain, int channel) {
    return powerControlServices->get_txPowerLevel(actualTxGain, channel);
}

double ETSI_RRS_RRFI::get_rxGain(int channel) {
    return powerControlServices->get_rxGain(channel);
}

double ETSI_RRS_RRFI::get_rxCenterFrequency(int channel) {
    return spectrumControlServices->get_rxCenterFrequency(channel);
}

double ETSI_RRS_RRFI::get_txCenterFrequency(int channel) {
    return spectrumControlServices->get_txCenterFrequency(channel);
}

double ETSI_RRS_RRFI::get_rxBandwidth(int channel) {
    return spectrumControlServices->get_rxBandwidth(channel);
}

double ETSI_RRS_RRFI::get_txBandwidth(int channel) {
    return spectrumControlServices->get_txBandwidth(channel);
}

double ETSI_RRS_RRFI::get_rxSamplingRate(int channel) {
    return spectrumControlServices->get_rxSamplingRate(channel);
}

double ETSI_RRS_RRFI::get_txSamplingRate(int channel) {
    return spectrumControlServices->get_txSamplingRate(channel);
}

ETSI_RRS_RRFI::~ETSI_RRS_RRFI() {
    delete spectrumControlServices;
    delete antennaManagementServices;
    delete powerControlServices;
    delete txRxChainControlServices;

}
