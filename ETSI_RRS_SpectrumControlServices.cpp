//
// Spectrum Control Services implementation
//

#include "ETSI_RRS_SpectrumControlServices.h"

using namespace std;

ETSI_RRS_SpectrumControlServices::ETSI_RRS_SpectrumControlServices(ETSI_RRS_USRP_Device &actualusrpDevice) {
    usrpDevice = &actualusrpDevice;
}

bool ETSI_RRS_SpectrumControlServices::set_rxCenterFrequency(double actualrxCenterFrequency, int channel) {

    if (this->usrpDevice->min_rx_frequency > actualrxCenterFrequency) {
        usrpDevice->usrp->set_rx_freq(uhd::tune_request_t(actualrxCenterFrequency), size_t(channel));
        cout << "rx_centerfreq is less than min value, rx_centerfreq is min value" << endl;
        return false;
    } else {
        if (this->usrpDevice->max_rx_frequency < actualrxCenterFrequency) {
            usrpDevice->usrp->set_rx_freq(uhd::tune_request_t(actualrxCenterFrequency), size_t(channel));
            cout << "rx_centerfreq is larger than max value, rx_centerfreq is max value" << endl;
            return false;
        } else {
            usrpDevice->usrp->set_rx_freq(uhd::tune_request_t(actualrxCenterFrequency), size_t(channel));
            cout << "rx_centerfreq changed successfully" << endl;
            return true;
        }
    }
}

bool ETSI_RRS_SpectrumControlServices::set_txCenterFrequency(double actualtxCenterFrequency, int channel) {
    if (this->usrpDevice->min_tx_frequency > actualtxCenterFrequency) {
        usrpDevice->usrp->set_tx_freq(uhd::tune_request_t(actualtxCenterFrequency), size_t(channel));
        cout << "tx_centerfreq is less than min value, tx_centerfreq is min value" << endl;
        return false;
    } else {
        if (this->usrpDevice->max_tx_frequency < actualtxCenterFrequency) {
            usrpDevice->usrp->set_tx_freq(uhd::tune_request_t(actualtxCenterFrequency), size_t(channel));
            cout << "tx_centerfreq is larger than max value, tx_centerfreq is max value" << endl;
            return false;
        } else {
            usrpDevice->usrp->set_tx_freq(uhd::tune_request_t(actualtxCenterFrequency), size_t(channel));
            cout << "tx_centerfreq changed successfully" << endl;
            return true;
        }
    }
}

bool ETSI_RRS_SpectrumControlServices::set_rxBandwidth(double actualrxBandwidth, int channel) {
    if (this->usrpDevice->min_rx_bandwidth > actualrxBandwidth) {
        this->usrpDevice->usrp->set_rx_bandwidth(actualrxBandwidth, size_t(channel));
        cout << "rx_bandwidth is less than min value, rx_bandwidth is min value" << endl;
        return false;
    } else {
        if (this->usrpDevice->max_rx_bandwidth < actualrxBandwidth) {
            this->usrpDevice->usrp->set_rx_bandwidth(actualrxBandwidth, size_t(channel));
            cout << "rx_bandwidth is larger than max value, rx_bandwidth is max value" << endl;
            return false;
        } else {
            this->usrpDevice->usrp->set_rx_bandwidth(actualrxBandwidth, size_t(channel));
            cout << "rx_bandwidth changed successfully" << endl;
            return true;
        }
    }
}

bool ETSI_RRS_SpectrumControlServices::set_txBandwidth(double actualtxBandwidth, int channel) {
    if (this->usrpDevice->min_tx_bandwidth > actualtxBandwidth) {
        this->usrpDevice->usrp->set_tx_bandwidth(actualtxBandwidth, size_t(channel));
        cout << "tx_bandwidth is less than min value, tx_bandwidth is min value" << endl;
        return false;
    } else {
        if (this->usrpDevice->max_tx_bandwidth < actualtxBandwidth) {
            this->usrpDevice->usrp->set_tx_bandwidth(actualtxBandwidth, size_t(channel));
            cout << "tx_bandwidth is larger than max value, tx_bandwidth is max value" << endl;
            return false;
        } else {
            this->usrpDevice->usrp->set_tx_bandwidth(actualtxBandwidth, size_t(channel));
            cout << "tx_bandwidth changed successfully" << endl;
            return true;
        }
    }
}

bool ETSI_RRS_SpectrumControlServices::set_rxSamplingRate(double actualrxRate, int channel) {
    if (this->usrpDevice->min_rx_rate > actualrxRate) {
        this->usrpDevice->usrp->set_rx_rate(actualrxRate, size_t(channel));
        cout << "rx_rate is less than min value, rx_rate is min value" << endl;
        return false;
    } else {
        if (this->usrpDevice->max_rx_rate < actualrxRate) {
            this->usrpDevice->usrp->set_rx_rate(actualrxRate, size_t(channel));
            cout << "rx_rate is larger than max value, rx_rate is max value" << endl;
            return false;
        } else {
            this->usrpDevice->usrp->set_rx_rate(actualrxRate, size_t(channel));
            cout << "rx_rate changed successfully" << endl;
            return true;
        }
    }
}

bool ETSI_RRS_SpectrumControlServices::set_txSamplingRate(double actualtxRate, int channel) {
    if (this->usrpDevice->min_tx_rate > actualtxRate) {
        this->usrpDevice->usrp->set_tx_rate(actualtxRate, size_t(channel));
        cout << "tx_rate is less than min value, tx_rate is min value" << endl;
        return false;
    } else {
        if (this->usrpDevice->max_tx_rate < actualtxRate) {
            this->usrpDevice->usrp->set_tx_rate(actualtxRate, size_t(channel));
            cout << "tx_rate is larger than max value, tx_rate is max value" << endl;
            return false;
        } else {
            this->usrpDevice->usrp->set_tx_rate(actualtxRate, size_t(channel));
            cout << "tx_rate changed successfully" << endl;
            return true;
        }
    }
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

}
