//
// General ETSI_RRS_RRFI Implementation
//

#include "ETSI_RRS_RRFI.h"
#include "ETSI_RRS_SpectrumControlServices.h"
#include "ETSI_RRS_AntennaManagementServices.h"
#include "ETSI_RRS_PowerControlServices.h"
#include "ETSI_RRS_TxRxChainControlServices.h"

using namespace std;

ETSI_RRS_RRFI::ETSI_RRS_RRFI() {
    spectrumControlServices = new ETSI_RRS_SpectrumControlServices();
    antennaManagementServices = new ETSI_RRS_AntennaManagementServices();
    powerControlServices = new ETSI_RRS_PowerControlServices();
    txRxChainControlServices = new ETSI_RRS_TxRxChainControlServices();

}

//Set parameters functions implementation

void ETSI_RRS_RRFI::set_txAntennaPort(int actualTxAntennaPort) {
    antennaManagementServices->set_txAntennaPort(actualTxAntennaPort);
    return;
}

void ETSI_RRS_RRFI::set_rxAntennaPort(int actualRxAntennaPort) {
    antennaManagementServices->set_rxAntennaPort(actualRxAntennaPort);
    return;
}

void ETSI_RRS_RRFI::set_maxTxPowerLevel(float actualMaxTxPowerLevel) {
    powerControlServices->set_maxTxPowerLevel(actualMaxTxPowerLevel);
}

void ETSI_RRS_RRFI::set_txPowerLevel(float actualTxPowerLevel) {
    powerControlServices->set_txPowerLevel(actualTxPowerLevel);
}

void ETSI_RRS_RRFI::set_rxGain(float actualRxGain) {
    powerControlServices->set_rxGain(actualRxGain);
}

//Get parameters functions implementation

int ETSI_RRS_RRFI::get_txAntennaPort() {
    return antennaManagementServices->get_txAntennaPort();
}

int ETSI_RRS_RRFI::get_rxAntennaPort() {
    return antennaManagementServices->get_rxAntennaPort();
}

float ETSI_RRS_RRFI::get_maxTxPowerLevel() {
    return powerControlServices->get_maxTxPowerLevel();
}

float ETSI_RRS_RRFI::get_txPowerLevel() {
    return powerControlServices->get_txPowerLevel();
}

float ETSI_RRS_RRFI::get_rxGain() {
    return powerControlServices->get_rxGain();
}


ETSI_RRS_RRFI::~ETSI_RRS_RRFI() {
    delete spectrumControlServices;
    delete antennaManagementServices;
    delete powerControlServices;
    delete txRxChainControlServices;

}
