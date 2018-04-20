//
// Power Control Services implementation
//

#include <iostream>
#include "ETSI_RRS_PowerControlServices.h"

using namespace std;

ETSI_RRS_PowerControlServices::ETSI_RRS_PowerControlServices() {
    cout << "Power Control Services created" << endl;

}

void ETSI_RRS_PowerControlServices::set_maxTxPowerLevel(float actualMaxTxPowerLevel) {
    this->maxTxPowerLevel = actualMaxTxPowerLevel;
}

void ETSI_RRS_PowerControlServices::set_txPowerLevel(float actualTxPowerLevel) {
    this->txPowerLevel = actualTxPowerLevel;
}

void ETSI_RRS_PowerControlServices::set_rxGain(float actualRxGain) {
    this->rxGain = actualRxGain;
}

float ETSI_RRS_PowerControlServices::get_maxTxPowerLevel() {
    return this->maxTxPowerLevel;
}

float ETSI_RRS_PowerControlServices::get_txPowerLevel() {
    return this->txPowerLevel;
}

float ETSI_RRS_PowerControlServices::get_rxGain() {
    return this->rxGain;
}

ETSI_RRS_PowerControlServices::~ETSI_RRS_PowerControlServices() {
    cout << "Power Control Services destroyed" << endl;

}
