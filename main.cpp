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
#include <boost/test/unit_test.hpp>


using namespace std;

int main(int argc, char* argv[]) {

    /*boost::unit_test::init_unit_test_func();

    ETSI_RRS_USRP_Device usrpdevice;
    cout << "..........." << endl;
    ETSI_RRS_RRFI rrfi(usrpdevice);

    //rrfi.set_txAntennaPort(0);
    rrfi.changeChannel(0);
    rrfi.set_txAntennaPort(0);
    rrfi.set_txCenterFrequency(5e+07);
    cout << rrfi.get_txCenterFrequency() << endl;
    rrfi.set_txSamplingRate(1e+06);
    cout << rrfi.get_txSamplingRate() << endl;
    rrfi.set_txBandwidth(500000);
    cout << rrfi.get_txBandwidth() << endl;
    rrfi.set_txPowerLevel(76);
    cout << rrfi.get_txPowerLevel() << endl;

    rrfi.set_rxSamplingRate(1e+06);
    cout << rrfi.get_rxSamplingRate() << endl;
    rrfi.set_rxGain(76);
    cout << rrfi.get_rxGain() << endl;
    rrfi.set_rxBandwidth(500000);
    cout << rrfi.get_rxBandwidth() << endl;
    rrfi.set_rxCenterFrequency(5e+07);
    cout << rrfi.get_rxCenterFrequency() << endl;

    //thread rx_thread(&ETSI_RRS_RRFI::rx_to_file, &rrfi, "/home/leoind/Dropbox/RRS_Clion/rxtest.dat", size_t(100), 10.0, 1000);
    rrfi.tx_from_file("/home/leoind/Dropbox/RRS_Clion/test", size_t(100));
    //rx_thread.join();




    */
    return 0;
}