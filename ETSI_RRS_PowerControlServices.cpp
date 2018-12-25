//
// Power Control Services implementation
//

#include <iostream>
#include "ETSI_RRS_PowerControlServices.h"

using namespace std;

ETSI_RRS_PowerControlServices::ETSI_RRS_PowerControlServices(ETSI_RRS_USRP_Device &actualusrpDevice) {
    usrpDevice = &actualusrpDevice;
    cout << "Power Control Services created" << endl;

}

void ETSI_RRS_PowerControlServices::set_maxTxPowerLevel(float actualMaxTxPowerLevel) {
    this->maxTxPowerLevel = actualMaxTxPowerLevel;
}

void ETSI_RRS_PowerControlServices::set_txPowerLevel(double actualTxGain, int channel) {
    if (usrpDevice->min_tx_gain <= actualTxGain <= usrpDevice->max_tx_gain) {
        this->txPowerLevel = actualTxGain;
        usrpDevice->usrp->set_tx_gain(actualTxGain, size_t(channel));
        usrpDevice->tx_gain = this->txPowerLevel;
    } else {
        cout << "Error: tx_gain out in range" << endl;
    }
    //return this->txPowerLevel;
}

void ETSI_RRS_PowerControlServices::set_rxGain(double actualRxGain, int channel) {
    if (usrpDevice->min_rx_gain <= actualRxGain <= usrpDevice->max_rx_gain) {
        this->rxGain = actualRxGain;
        usrpDevice->usrp->set_rx_gain(actualRxGain, size_t(channel));
        usrpDevice->rx_gain = this->rxGain;
    } else {
        cout << "Error: rx_gain out in range" << endl;
    }

}

float ETSI_RRS_PowerControlServices::get_maxTxPowerLevel() {
    return this->maxTxPowerLevel;
}

double ETSI_RRS_PowerControlServices::get_txPowerLevel(double actualTxGain, int channel) {
}

double ETSI_RRS_PowerControlServices::get_rxGain(int channel) {
    if (this->rxGain == usrpDevice->usrp->get_rx_gain(size_t(channel))) {
        return rxGain;
    } else {
        cout << "error" << endl;
    }
}

ETSI_RRS_PowerControlServices::~ETSI_RRS_PowerControlServices() {
    cout << "Power Control Services destroyed" << endl;

}
