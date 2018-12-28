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
    usrpDevice = &actualusrpdevice;
}

void ETSI_RRS_RRFI::changeChannel(int actualChannel) {
    this->channel = actualChannel;
    usrpDevice->changeChannel(size_t(actualChannel));
}

//Set parameters functions implementation

void ETSI_RRS_RRFI::set_txAntennaPort(int actualTxAntennaPort) {
    antennaManagementServices->set_txAntennaPort(actualTxAntennaPort, this->channel);
    return;
}

void ETSI_RRS_RRFI::set_rxAntennaPort(int actualRxAntennaPort) {
    antennaManagementServices->set_rxAntennaPort(actualRxAntennaPort, this->channel);
    return;
}

void ETSI_RRS_RRFI::set_maxTxPowerLevel(double actualMaxTxPowerLevel) {
    powerControlServices->set_maxTxPowerLevel(actualMaxTxPowerLevel);
}

void ETSI_RRS_RRFI::set_txPowerLevel(double actualTxPowerLevel) {
    powerControlServices->set_txPowerLevel(actualTxPowerLevel, this->channel);
}

void ETSI_RRS_RRFI::set_rxGain(double actualRxGain) {
    powerControlServices->set_rxGain(actualRxGain, this->channel);
}

void ETSI_RRS_RRFI::set_rxCenterFrequency(double actualRxCenterFrequency) {
    spectrumControlServices->set_rxCenterFrequency(actualRxCenterFrequency, this->channel);
}

void ETSI_RRS_RRFI::set_txCenterFrequency(double actualTxCenterFrequency) {
    spectrumControlServices->set_txCenterFrequency(actualTxCenterFrequency, this->channel);
}

void ETSI_RRS_RRFI::set_rxBandwidth(double actualRxBandwidth) {
    spectrumControlServices->set_rxBandwidth(actualRxBandwidth, this->channel);
}

void ETSI_RRS_RRFI::set_txBandwidth(double actualTxBandwidth) {
    spectrumControlServices->set_txBandwidth(actualTxBandwidth, this->channel);
}

void ETSI_RRS_RRFI::set_rxSamplingRate(double actualRxRate) {
    spectrumControlServices->set_rxSamplingRate(actualRxRate, this->channel);
}

void ETSI_RRS_RRFI::set_txSamplingRate(double actualTxRate) {
    spectrumControlServices->set_txSamplingRate(actualTxRate, this->channel);
}


//Get parameters functions implementation

string ETSI_RRS_RRFI::get_txAntennaPort() {
    return antennaManagementServices->get_txAntennaPort(this->channel);
}

string ETSI_RRS_RRFI::get_rxAntennaPort() {
    return antennaManagementServices->get_rxAntennaPort(this->channel);
}

double ETSI_RRS_RRFI::get_maxTxPowerLevel() {
    return powerControlServices->get_maxTxPowerLevel();
}

double ETSI_RRS_RRFI::get_txPowerLevel() {
    return powerControlServices->get_txPowerLevel(this->channel);
}

double ETSI_RRS_RRFI::get_rxGain() {
    return powerControlServices->get_rxGain(this->channel);
}

double ETSI_RRS_RRFI::get_rxCenterFrequency() {
    return spectrumControlServices->get_rxCenterFrequency(this->channel);
}

double ETSI_RRS_RRFI::get_txCenterFrequency() {
    return spectrumControlServices->get_txCenterFrequency(this->channel);
}

double ETSI_RRS_RRFI::get_rxBandwidth() {
    return spectrumControlServices->get_rxBandwidth(this->channel);
}

double ETSI_RRS_RRFI::get_txBandwidth() {
    return spectrumControlServices->get_txBandwidth(this->channel);
}

double ETSI_RRS_RRFI::get_rxSamplingRate() {
    return spectrumControlServices->get_rxSamplingRate(this->channel);
}

double ETSI_RRS_RRFI::get_txSamplingRate() {
    return spectrumControlServices->get_txSamplingRate(this->channel);
}

ETSI_RRS_RRFI::~ETSI_RRS_RRFI() {
    delete spectrumControlServices;
    delete antennaManagementServices;
    delete powerControlServices;
    delete txRxChainControlServices;

}
