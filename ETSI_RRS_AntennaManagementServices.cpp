//
// Antenna Management Services implementation
//

#include <iostream>
#include "ETSI_RRS_AntennaManagementServices.h"
#include "ETSI_RRS_USRP_Device.h"

using namespace std;
using namespace boost;

ETSI_RRS_AntennaManagementServices::ETSI_RRS_AntennaManagementServices(ETSI_RRS_USRP_Device *actualusrpDevice) {

    usrpDevice = actualusrpDevice;
    cout << "Antenna Management Services created" << endl;
}

void ETSI_RRS_AntennaManagementServices::set_txAntennaPort(string actualTxAntennaPort) {

    this->txAntennaPort = actualTxAntennaPort;
    cout << format("Setting RX Antenna: %s") % usrpDevice->ant << endl;
    usrpDevice->usrp->set_rx_antenna(usrpDevice->ant);
    cout << format("Actual RX Antenna: %s") % usrpDevice->usrp->get_rx_antenna() << endl << endl;

}

string ETSI_RRS_AntennaManagementServices::get_txAntennaPort() {
    return txAntennaPort;
}

void ETSI_RRS_AntennaManagementServices::set_rxAntennaPort(string actualRxAntennaPort) {

    this->rxAntennaPort = actualRxAntennaPort;
}

string ETSI_RRS_AntennaManagementServices::get_rxAntennaPort() {
    return rxAntennaPort;
}


ETSI_RRS_AntennaManagementServices::~ETSI_RRS_AntennaManagementServices() {

    cout << "Antenna Management Services destroyed" << endl;
}
