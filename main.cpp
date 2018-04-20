//
// Main function
//

#include <iostream>
#include "ETSI_RRS_RRFI.h"

using namespace std;

int main() {
    ETSI_RRS_RRFI rrfi;

    rrfi.set_rxAntennaPort(10);
    cout << endl <<  rrfi.get_rxAntennaPort() << endl << endl;

    return 0;
}