//
// General ETSI_RRS_RRFI header
//

#ifndef RRS_CLION_RRFI_H
#define RRS_CLION_RRFI_H


#include "ETSI_RRS_SpectrumControlServices.h"
#include "ETSI_RRS_AntennaManagementServices.h"
#include "ETSI_RRS_PowerControlServices.h"
#include "ETSI_RRS_TxRxChainControlServices.h"
#include "ETSI_RRS_USRP_Device.h"

using namespace std;


class ETSI_RRS_RRFI {

private:
    ETSI_RRS_SpectrumControlServices *spectrumControlServices;
    ETSI_RRS_AntennaManagementServices *antennaManagementServices;
    ETSI_RRS_PowerControlServices *powerControlServices;
    ETSI_RRS_TxRxChainControlServices *txRxChainControlServices;
    ETSI_RRS_USRP_Device* usrpDevice;
    int channel;
    //ETSI_RRS_USRP_Device usrpDevice;


public:
    ETSI_RRS_RRFI(ETSI_RRS_USRP_Device&);

    void changeChannel(int);

        //Set parameters functions
        //Antenna management Services
    bool set_txAntennaPort(int);
    bool set_rxAntennaPort(int);
        //Power Control Services
    bool set_maxTxPowerLevel(double);
    bool set_txPowerLevel(double);
    bool set_rxGain(double);
        //Spectrum Control Services
    bool set_rxCenterFrequency(double);
    bool set_txCenterFrequency(double);
    bool set_rxBandwidth(double);
    bool set_txBandwidth(double);
    bool set_rxSamplingRate(double);
    bool set_txSamplingRate(double);

        //Get parameters functions
        // Antenna management Services
    string get_txAntennaPort();
    string get_rxAntennaPort();
        //Power Control Services
    double get_maxTxPowerLevel();
    double get_txPowerLevel();
    double get_rxGain();
        //Spectrum Control Services
    double get_rxCenterFrequency();
    double get_txCenterFrequency();
    double get_rxBandwidth();
    double get_txBandwidth();
    double get_rxSamplingRate();
    double get_txSamplingRate();

        //TX and RX from file functions
    bool tx_from_file(string, size_t);
    bool tx_from_buff(std::vector<short>, size_t);
    void change_tx_stream_args(string, string); //fc64 - complex<double> fc32 - complex<float>
    void change_rx_stream_args(string, string); //sc16 - complex<int16_t> sc8 - complex<int8_t>
    std::vector<short> rx_to_buff(size_t, float, int);
    void rx_to_file(string, size_t, float, int);

    ~ETSI_RRS_RRFI();

};


#endif //RRS_CLION_RRFI_H
