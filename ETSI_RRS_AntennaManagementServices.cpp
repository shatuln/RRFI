//
// Antenna Management Services implementation
//

#include <iostream>
#include "ETSI_RRS_AntennaManagementServices.h"
#include "ETSI_RRS_USRP_Device.h"

using namespace std;
using namespace boost;

ETSI_RRS_AntennaManagementServices::ETSI_RRS_AntennaManagementServices(ETSI_RRS_USRP_Device &actualusrpDevice) {

    usrpDevice = &actualusrpDevice;
    cout << "Antenna Management Services created" << endl;
}

void ETSI_RRS_AntennaManagementServices::set_txAntennaPort(int actualTxAntennaPort, int channel) {

    this->txAntennaPort = decode_tx_port_num(actualTxAntennaPort);
    cout << format("Setting TX Antenna: %s") % this->txAntennaPort << endl;
    usrpDevice->tx_ant = this->txAntennaPort;
    usrpDevice->usrp->set_tx_antenna(this->txAntennaPort, size_t(channel));
    cout << format("Actual TX Antenna: %s, on channel %s") % usrpDevice->usrp->get_tx_antenna(size_t(channel)) % channel << endl << endl;

}

string ETSI_RRS_AntennaManagementServices::get_txAntennaPort(int channel) {

    if (this->txAntennaPort == usrpDevice->usrp->get_tx_antenna(size_t(channel))) {
        return txAntennaPort;
    } else {
        cout << "error" << endl;
    }

}

void ETSI_RRS_AntennaManagementServices::set_rxAntennaPort(int actualRxAntennaPort, int channel) {

    this->rxAntennaPort = decode_rx_port_num(actualRxAntennaPort);
    cout << format("Setting RX Antenna: %s") % this->rxAntennaPort << endl;
    usrpDevice->rx_ant = this->rxAntennaPort;
    usrpDevice->usrp->set_rx_antenna(this->rxAntennaPort, size_t(channel));
    cout << format("Actual RX Antenna: %s, on channel %s") % usrpDevice->usrp->get_rx_antenna(size_t(channel)) % channel << endl;
}

string ETSI_RRS_AntennaManagementServices::get_rxAntennaPort(int channel) {

    if (this->rxAntennaPort == usrpDevice->usrp->get_rx_antenna(size_t(channel))) {
        return rxAntennaPort;
    } else {
        cout << "Error" << endl;
    }

}

string ETSI_RRS_AntennaManagementServices::decode_tx_port_num(int num) {

    if (num == 0) {
        return "TX/RX";
    }
}

string ETSI_RRS_AntennaManagementServices::decode_rx_port_num(int num) {

    if (num == 0) {
        return "TX/RX";
    }
    if (num == 1) {
        return "RX2";
    }
}


ETSI_RRS_AntennaManagementServices::~ETSI_RRS_AntennaManagementServices() {

    cout << "Antenna Management Services destroyed" << endl;
}
