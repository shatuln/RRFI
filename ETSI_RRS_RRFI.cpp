//
// General ETSI_RRS_RRFI Implementation
//

#include <uhd/usrp/multi_usrp.hpp>
#include <fstream>
#include "ETSI_RRS_RRFI.h"
#include "ETSI_RRS_SpectrumControlServices.h"
#include "ETSI_RRS_AntennaManagementServices.h"
#include "ETSI_RRS_PowerControlServices.h"
#include "ETSI_RRS_TxRxChainControlServices.h"

using namespace std;
using namespace boost;

ETSI_RRS_RRFI::ETSI_RRS_RRFI(ETSI_RRS_USRP_Device &actualusrpdevice) {
    spectrumControlServices = new ETSI_RRS_SpectrumControlServices(actualusrpdevice);
    antennaManagementServices = new ETSI_RRS_AntennaManagementServices(actualusrpdevice);
    powerControlServices = new ETSI_RRS_PowerControlServices(actualusrpdevice);
    txRxChainControlServices = new ETSI_RRS_TxRxChainControlServices(actualusrpdevice);
    usrpDevice = &actualusrpdevice;
}

void ETSI_RRS_RRFI::changeChannel(int actualChannel) {
    this->channel = actualChannel;
    usrpDevice->changeChannel(size_t(actualChannel));
}

//Set parameters functions implementation

void ETSI_RRS_RRFI::set_txAntennaPort(int actualTxAntennaPort) {
    antennaManagementServices->set_txAntennaPort(actualTxAntennaPort, this->channel);
    return;
}

void ETSI_RRS_RRFI::set_rxAntennaPort(int actualRxAntennaPort) {
    antennaManagementServices->set_rxAntennaPort(actualRxAntennaPort, this->channel);
    return;
}

bool ETSI_RRS_RRFI::set_maxTxPowerLevel(double actualMaxTxPowerLevel) {
    return powerControlServices->set_maxTxPowerLevel(actualMaxTxPowerLevel);
}

bool ETSI_RRS_RRFI::set_txPowerLevel(double actualTxPowerLevel) {
    return powerControlServices->set_txPowerLevel(actualTxPowerLevel, this->channel);
}

bool ETSI_RRS_RRFI::set_rxGain(double actualRxGain) {
    return powerControlServices->set_rxGain(actualRxGain, this->channel);
}

bool ETSI_RRS_RRFI::set_rxCenterFrequency(double actualRxCenterFrequency) {
    return spectrumControlServices->set_rxCenterFrequency(actualRxCenterFrequency, this->channel);
}

bool ETSI_RRS_RRFI::set_txCenterFrequency(double actualTxCenterFrequency) {
    return spectrumControlServices->set_txCenterFrequency(actualTxCenterFrequency, this->channel);
}

bool ETSI_RRS_RRFI::set_rxBandwidth(double actualRxBandwidth) {
    return spectrumControlServices->set_rxBandwidth(actualRxBandwidth, this->channel);
}

bool ETSI_RRS_RRFI::set_txBandwidth(double actualTxBandwidth) {
    return spectrumControlServices->set_txBandwidth(actualTxBandwidth, this->channel);
}

bool ETSI_RRS_RRFI::set_rxSamplingRate(double actualRxRate) {
    return spectrumControlServices->set_rxSamplingRate(actualRxRate, this->channel);
}

bool ETSI_RRS_RRFI::set_txSamplingRate(double actualTxRate) {
    return spectrumControlServices->set_txSamplingRate(actualTxRate, this->channel);
}


//Get parameters functions implementation

string ETSI_RRS_RRFI::get_txAntennaPort() {
    return antennaManagementServices->get_txAntennaPort(this->channel);
}

string ETSI_RRS_RRFI::get_rxAntennaPort() {
    return antennaManagementServices->get_rxAntennaPort(this->channel);
}

double ETSI_RRS_RRFI::get_maxTxPowerLevel() {
    return powerControlServices->get_maxTxPowerLevel();
}

double ETSI_RRS_RRFI::get_txPowerLevel() {
    return powerControlServices->get_txPowerLevel(this->channel);
}

double ETSI_RRS_RRFI::get_rxGain() {
    return powerControlServices->get_rxGain(this->channel);
}

double ETSI_RRS_RRFI::get_rxCenterFrequency() {
    return spectrumControlServices->get_rxCenterFrequency(this->channel);
}

double ETSI_RRS_RRFI::get_txCenterFrequency() {
    return spectrumControlServices->get_txCenterFrequency(this->channel);
}

double ETSI_RRS_RRFI::get_rxBandwidth() {
    return spectrumControlServices->get_rxBandwidth(this->channel);
}

double ETSI_RRS_RRFI::get_txBandwidth() {
    return spectrumControlServices->get_txBandwidth(this->channel);
}

double ETSI_RRS_RRFI::get_rxSamplingRate() {
    return spectrumControlServices->get_rxSamplingRate(this->channel);
}

double ETSI_RRS_RRFI::get_txSamplingRate() {
    return spectrumControlServices->get_txSamplingRate(this->channel);
}

void ETSI_RRS_RRFI::tx_from_file(string actualfilename, size_t samps_per_buff = 100) {
    txRxChainControlServices->tx_from_file(actualfilename, samps_per_buff);
}

void ETSI_RRS_RRFI::change_tx_stream_args(string cpu_format, string otw_format) {
    txRxChainControlServices->change_tx_stream_args(cpu_format, otw_format);
}

void ETSI_RRS_RRFI::change_rx_stream_args(string cpu_format, string otw_format) {
    txRxChainControlServices->change_rx_stream_args(cpu_format, otw_format);
}

void ETSI_RRS_RRFI::rx_to_file(string actualfilename, size_t samps_per_buff, float settling_time, int num_requested_samps = 0) {
    txRxChainControlServices->rx_to_file(actualfilename, samps_per_buff, settling_time, num_requested_samps);
}

ETSI_RRS_RRFI::~ETSI_RRS_RRFI() {
    delete spectrumControlServices;
    delete antennaManagementServices;
    delete powerControlServices;
    delete txRxChainControlServices;

}
