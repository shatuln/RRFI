//
// Main function
//

#include <iostream>
#include <thread>
#include "ETSI_RRS_RRFI.h"

#include <uhd/utils/thread.hpp>
#include <uhd/utils/safe_main.hpp>
#include <uhd/usrp/multi_usrp.hpp>
#include <uhd/exception.hpp>
#include <uhd/types/tune_request.hpp>
#include <boost/program_options.hpp>
#include <boost/format.hpp>
#include <boost/thread.hpp>


using namespace std;

int main() {
    ETSI_RRS_USRP_Device usrpdevice;
    cout << "..........." << endl;
    ETSI_RRS_RRFI rrfi(usrpdevice);

    rrfi.changeChannel(0);
    rrfi.set_rxGain(90);
    cout << rrfi.get_rxGain() << endl;


    rrfi.set_txAntennaPort(0);
    //cout << "Tx Antenna Port is: " << rrfi.get_txAntennaPort(0) << endl << endl;
    rrfi.set_rxCenterFrequency(4.2);
    cout << rrfi.get_rxCenterFrequency() << endl;

    rrfi.set_rxAntennaPort(0);
    //cout << "Rx Antenna Port is: " << rrfi.get_rxAntennaPort(0) << endl << endl;

    thread rx_thread(&ETSI_RRS_RRFI::rx_to_file, &rrfi, "", size_t(100), 10.0, 100);
    rx_thread.join();


    return 0;
}