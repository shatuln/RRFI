//
// Main function
//

#include <iostream>
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
    ETSI_RRS_RRFI rrfi;

    rrfi.set_rxAntennaPort("TX:RX");
    cout << endl << "Rx Antenna Port is: " << rrfi.get_rxAntennaPort() << endl << endl;

    return 0;
}