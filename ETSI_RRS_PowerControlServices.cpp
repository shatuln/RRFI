//
// Power Control Services implementation
//

#include <iostream>
#include "ETSI_RRS_PowerControlServices.h"

using namespace std;

ETSI_RRS_PowerControlServices::ETSI_RRS_PowerControlServices(ETSI_RRS_USRP_Device &actualusrpDevice) {
    usrpDevice = &actualusrpDevice;
}

bool ETSI_RRS_PowerControlServices::set_maxTxPowerLevel(double actualMaxTxPowerLevel) {
    usrpDevice->max_tx_gain = actualMaxTxPowerLevel;
    cout << "Max gain: " << usrpDevice->max_tx_gain << endl;
    return true;
}

bool ETSI_RRS_PowerControlServices::set_txPowerLevel(double actualTxGain, int channel) {
    if (this->usrpDevice->min_tx_gain > actualTxGain) {
        usrpDevice->usrp->set_tx_gain(actualTxGain, size_t(channel));
        cout << "tx_powerlevel is less than min value, tx_powerlevel is min value" << endl;
        return false;
    } else {
        if (this->usrpDevice->max_tx_gain < actualTxGain) {
            usrpDevice->usrp->set_tx_gain(actualTxGain, size_t(channel));
            cout << "tx_powerlevel is larger than max value, tx_powerlevel is max value" << endl;
            return false;
        } else {
            usrpDevice->usrp->set_tx_gain(actualTxGain, size_t(channel));
            cout << "tx_powerlevel changed successful" << endl;
            return true;
        }
    }
}

bool ETSI_RRS_PowerControlServices::set_rxGain(double actualRxGain, int channel) {
    if (this->usrpDevice->min_rx_gain > actualRxGain) {
        usrpDevice->usrp->set_rx_gain(actualRxGain, size_t(channel));
        cout << "rx_gain is less than min value, rx_gain is min value" << endl;
        return false;
    } else {
        if (this->usrpDevice->max_rx_gain < actualRxGain) {
            usrpDevice->usrp->set_rx_gain(actualRxGain, size_t(channel));
            cout << "rx_gain is larger than max value, rx_gain is max value" << endl;
            return false;
        } else {
            usrpDevice->usrp->set_rx_gain(actualRxGain, size_t(channel));
            cout << "rx_gain changed successful" << endl;
            return true;
        }
    }
}

double ETSI_RRS_PowerControlServices::get_maxTxPowerLevel() {
    return usrpDevice->max_tx_gain;
}

double ETSI_RRS_PowerControlServices::get_txPowerLevel(int channel) {
    return usrpDevice->usrp->get_tx_gain(size_t(channel));
}

double ETSI_RRS_PowerControlServices::get_rxGain(int channel) {
    return usrpDevice->usrp->get_rx_gain(size_t(channel));
}

ETSI_RRS_PowerControlServices::~ETSI_RRS_PowerControlServices() {

}
