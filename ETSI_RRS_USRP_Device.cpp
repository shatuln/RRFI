//
// Created by leoind on 26.04.18.
//

#include "ETSI_RRS_USRP_Device.h"

using namespace boost;
using namespace std;

ETSI_RRS_USRP_Device::ETSI_RRS_USRP_Device() {

    cout << "\e[1m" << "USRP device configuration started..." << "\e[0m" << endl;

    //Creating connection with USRP device
    cout << format("Creating the usrp device with: USB...") << endl;
    usrp = uhd::usrp::multi_usrp::make(deviceArgs);

    // Lock mboard clocks
    cout << format("Lock mboard clocks: %f") % ref << endl;
    usrp->set_clock_source(ref);

    //always select the subdevice first, the channel mapping affects the other settings
    cout << format("subdev set to: %f") % subdev << endl;
    usrp->set_rx_subdev_spec(subdev);
    cout << format("Using Device: %s") % usrp->get_pp_string() << endl;

    cout << "\e[1m" << "USRP device configuration done" << "\e[0m" << endl;

}