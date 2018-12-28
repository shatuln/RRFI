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

    if (this->usrpDevice->min_rx_frequency >= actualrxCenterFrequency) {
        usrpDevice->usrp->set_rx_freq(uhd::tune_request_t(actualrxCenterFrequency), size_t(channel));
        cout << "rx_centerfreq is less than min value, rx_centerfreq is min value" << endl;
    } else {
        if (this->usrpDevice->max_rx_frequency <= actualrxCenterFrequency) {
            usrpDevice->usrp->set_rx_freq(uhd::tune_request_t(actualrxCenterFrequency), size_t(channel));
            cout << "rx_centerfreq is larger than max value, rx_centerfreq is max value" << endl;
        } else {
            usrpDevice->usrp->set_rx_freq(uhd::tune_request_t(actualrxCenterFrequency), size_t(channel));
            cout << "rx_centerfreq changed successful" << endl;
        }
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

void ETSI_RRS_SpectrumControlServices::set_rxSamplingRate(double actualrxRate, int channel) {
    this->rx_SamplingRate = actualrxRate;
    this->usrpDevice->usrp->set_rx_rate(actualrxRate, (size_t)channel);
}

void ETSI_RRS_SpectrumControlServices::set_txSamplingRate(double actualtxRate, int channel) {
    this->tx_SamplingRate = actualtxRate;
    this->usrpDevice->usrp->set_tx_rate(actualtxRate, (size_t)channel);
}

double ETSI_RRS_SpectrumControlServices::get_rxCenterFrequency(int channel) {
    return this->usrpDevice->usrp->get_rx_freq((size_t)channel);
}

double ETSI_RRS_SpectrumControlServices::get_txCenterFrequency(int channel) {
    return this->usrpDevice->usrp->get_tx_freq((size_t)channel);
}

double ETSI_RRS_SpectrumControlServices::get_rxBandwidth(int channel) {
    return this->usrpDevice->usrp->get_rx_bandwidth((size_t)channel);
}

double ETSI_RRS_SpectrumControlServices::get_txBandwidth(int channel) {
    return this->usrpDevice->usrp->get_tx_bandwidth((size_t)channel);
}

double ETSI_RRS_SpectrumControlServices::get_rxSamplingRate(int channel) {
    return this->usrpDevice->usrp->get_rx_rate((size_t)channel);
}

double ETSI_RRS_SpectrumControlServices::get_txSamplingRate(int channel) {
    return this->usrpDevice->usrp->get_tx_rate((size_t)channel);
}

ETSI_RRS_SpectrumControlServices::~ETSI_RRS_SpectrumControlServices() {
    cout << "Spectrum Control Services destroyed" << endl;

}
