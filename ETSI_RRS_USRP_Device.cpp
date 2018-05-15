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
    cout << format("Subdevice set to: %f") % subdev << endl;
    usrp->set_rx_subdev_spec(subdev);
    cout << format("Using Subdevice: %s") % usrp->get_pp_string() << endl;

    cout << "RX channel number = " << usrp->get_rx_num_channels() << endl;
    cout << "TX channel number = " << usrp->get_tx_num_channels() << endl;

    for(int i=0; i<usrp->get_rx_antennas().size(); ++i)
        cout << "RX antenna "<< i << ": " << usrp->get_rx_antennas()[i] << endl;

    for(int i=0; i<usrp->get_tx_antennas().size(); ++i)
        cout << "TX antenna "<< i << ": " << usrp->get_tx_antennas()[i] << endl;

    usrp->set_tx_antenna("TX/RX", size_t(0));
    cout << format("Actual TX Antenna: %s") % usrp->get_tx_antenna(size_t(0)) << ", on channel 0" << endl;

    usrp->set_rx_antenna("RX2", size_t(0));
    cout << format("Actual RX Antenna: %s") % usrp->get_rx_antenna(size_t(0)) << ", on channel 0" << endl << endl;

    cout << "TX gain is: " << usrp->get_tx_gain_range().to_pp_string() << endl;
    cout << "RX gain is: " << usrp->get_rx_gain_range().to_pp_string() << endl;

    cout << "\e[1m" << "USRP device configuration done" << "\e[0m" << endl;

}