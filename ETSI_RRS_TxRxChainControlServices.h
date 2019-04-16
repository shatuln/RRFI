//
// Tx/Rx Chain Control Services header
//

#ifndef RRS_CLION_TXRXCHAINCONTROLSERVICES_H
#define RRS_CLION_TXRXCHAINCONTROLSERVICES_H

#include "ETSI_RRS_USRP_Device.h"

using namespace std;

static bool stop_signal_called = false;

class ETSI_RRS_TxRxChainControlServices {

private:
    ETSI_RRS_USRP_Device *usrpDevice;

    bool txStartTime;
    bool txStopTime;
    bool rxStartTime;
    bool rxStopTime;

public:
    ETSI_RRS_TxRxChainControlServices(ETSI_RRS_USRP_Device&);
    //TX and RX from file functions
    void tx_from_file(string, size_t);
    void change_tx_stream_args(string, string); //fc64 - complex<double> fc32 - complex<float>
    void change_rx_stream_args(string, string); //sc16 - complex<int16_t> sc8 - complex<int8_t>
    void rx_to_file(string, size_t, float, int);
    ~ETSI_RRS_TxRxChainControlServices();

};


#endif //RRS_CLION_TXRXCHAINCONTROLSERVICES_H
