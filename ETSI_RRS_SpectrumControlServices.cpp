//
// Spectrum Control Services implementation
//

#include "ETSI_RRS_SpectrumControlServices.h"

using namespace std;

ETSI_RRS_SpectrumControlServices::ETSI_RRS_SpectrumControlServices(ETSI_RRS_USRP_Device &actualusrpDevice) {
    usrpDevice = &actualusrpDevice;
    cout << "Spectrum Control Services created" << endl;

}

void ETSI_RRS_SpectrumControlServices::set_rxCenterFrequency(double actualrxCenterFrequency, int channel) {
    if (usrpDevice->min_rx_frequency < actualrxCenterFrequency < usrpDevice->max_rx_frequency) {
        this->rx_CenterFrequency = actualrxCenterFrequency;
        this->usrpDevice->usrp->set_rx_freq(uhd::tune_request_t(actualrxCenterFrequency), size_t(channel));
    } else {
        cout << "Error: rx_Centerfrequency out of range" << endl;
    }
}

void ETSI_RRS_SpectrumControlServices::set_txCenterFrequency(double actualtxCenterFrequency, int channel) {
    if (usrpDevice->min_tx_frequency < actualtxCenterFrequency < usrpDevice->max_tx_frequency) {
        this->tx_CenterFrequency = actualtxCenterFrequency;
        this->usrpDevice->usrp->set_tx_freq(uhd::tune_request_t(actualtxCenterFrequency), size_t(channel));
    } else {
        cout << "Error: tx_Centerfrequency out of range" << endl;
    }
}

void ETSI_RRS_SpectrumControlServices::set_rxBandwidth(double actualrxBandwidth, int channel) {
    if (usrpDevice->min_rx_bandwidth < actualrxBandwidth < usrpDevice->max_rx_bandwidth) {
        this->rx_bandwidth = actualrxBandwidth;
        this->usrpDevice->usrp->set_rx_bandwidth(actualrxBandwidth, size_t(channel));
    } else {
        cout << "Error: rx_bandwidth out of range" << endl;
    }
}

void ETSI_RRS_SpectrumControlServices::set_txBandwidth(double actualtxBandwidth, int channel) {
    if (usrpDevice->min_tx_bandwidth < actualtxBandwidth < usrpDevice->max_tx_bandwidth) {
        this->tx_bandwidth = actualtxBandwidth;
        this->usrpDevice->usrp->set_tx_bandwidth(actualtxBandwidth, size_t(channel));
    } else {
        cout << "Error: tx_bandwidth out of range" << endl;
    }
}

void ETSI_RRS_SpectrumControlServices::set_rxSamplingRate() {

}

void ETSI_RRS_SpectrumControlServices::set_txSamplingRate() {

}

double ETSI_RRS_SpectrumControlServices::get_rxCenterFrequency() {

}

double ETSI_RRS_SpectrumControlServices::get_txCenterFrequency() {

}

double ETSI_RRS_SpectrumControlServices::get_rxBandwidth() {

}

double ETSI_RRS_SpectrumControlServices::get_txBandwidth() {

}

double ETSI_RRS_SpectrumControlServices::get_rxSamplingRate() {

}

double ETSI_RRS_SpectrumControlServices::get_txSamplingRate() {

}

ETSI_RRS_SpectrumControlServices::~ETSI_RRS_SpectrumControlServices() {
    cout << "Spectrum Control Services destroyed" << endl;

}
