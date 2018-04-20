//
// Antenna Management Services implementation
//

#include <iostream>
#include "ETSI_RRS_AntennaManagementServices.h"

using namespace std;

ETSI_RRS_AntennaManagementServices::ETSI_RRS_AntennaManagementServices() {

    cout << "Antenna Management Services created" << endl;
}

void ETSI_RRS_AntennaManagementServices::set_txAntennaPort(int actualTxAntennaPort) {

    this->txAntennaPort = actualTxAntennaPort;
}

int ETSI_RRS_AntennaManagementServices::get_txAntennaPort() {
    return txAntennaPort;
}

void ETSI_RRS_AntennaManagementServices::set_rxAntennaPort(int actualRxAntennaPort) {

    this->rxAntennaPort = actualRxAntennaPort;
}

int ETSI_RRS_AntennaManagementServices::get_rxAntennaPort() {
    return rxAntennaPort;
}


ETSI_RRS_AntennaManagementServices::~ETSI_RRS_AntennaManagementServices() {

    cout << "Antenna Management Services destroyed" << endl;
}
