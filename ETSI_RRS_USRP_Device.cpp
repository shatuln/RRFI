//
// Global USRP device parameters implementation
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
    this->min_tx_gain = usrp->get_tx_gain_range().start();
    this->max_tx_gain = usrp->get_tx_gain_range().stop();
    cout << "RX gain is: " << usrp->get_rx_gain_range().to_pp_string() << endl;
    this->min_rx_gain = usrp->get_rx_gain_range().start();
    this->max_rx_gain = usrp->get_rx_gain_range().stop();

    cout << "TX bandwidth is" << usrp->get_tx_bandwidth_range().to_pp_string() << endl;
    this->min_tx_bandwidth = usrp->get_tx_bandwidth_range().start();
    this->max_tx_bandwidth = usrp->get_tx_bandwidth_range().stop();
    cout << "RX bandwidth is" << usrp->get_rx_bandwidth_range().to_pp_string() << endl;
    this->max_rx_bandwidth = usrp->get_rx_bandwidth_range().start();
    this->max_rx_bandwidth = usrp->get_rx_bandwidth_range().stop();

    cout << "TX frequency is" << usrp->get_tx_freq_range().to_pp_string() << endl;
    this->min_tx_frequency = usrp->get_tx_freq_range().start();
    this->max_tx_frequency = usrp->get_tx_freq_range().stop();
    cout << "RX frequency is" << usrp->get_rx_freq_range().to_pp_string() << endl;
    this->min_rx_frequency = usrp->get_rx_freq_range().start();
    this->max_rx_frequency = usrp->get_rx_freq_range().stop();

    cout << "TX Sapling rate is" << usrp->get_tx_rates().to_pp_string() << endl;
    this->min_tx_rate = usrp->get_tx_rates().start();
    this->max_tx_rate = usrp->get_tx_rates().stop();
    cout << "RX Sapling rate is" << usrp->get_rx_rates().to_pp_string() << endl;
    this->min_rx_rate = usrp->get_rx_rates().start();
    this->max_rx_rate = usrp->get_rx_rates().stop();

    tx_stream_args.cpu_format = "sc16";
    tx_stream_args.otw_format = "sc16";
    rx_stream_args.cpu_format = "sc16";
    rx_stream_args.otw_format = "sc16";
    tx_stream = usrp->get_tx_stream(tx_stream_args);
    rx_stream = usrp->get_rx_stream(rx_stream_args);
    tx_md.start_of_burst = false;
    tx_md.end_of_burst = false;


    cout << "\e[1m" << "USRP device configuration done" << "\e[0m" << endl;

}

void ETSI_RRS_USRP_Device::changeChannel(size_t actualChannel) {
    cout << "\e[1m" << "Channel changing for " << actualChannel << " channel" << "\e[0m" << endl;

    usrp->set_tx_antenna("TX/RX", size_t(actualChannel));
    cout << format("Actual TX Antenna: %s") % usrp->get_tx_antenna(actualChannel) << endl;

    usrp->set_rx_antenna("RX2", actualChannel);
    cout << format("Actual RX Antenna: %s") % usrp->get_rx_antenna(actualChannel) << endl << endl;

    cout << "TX gain is: " << usrp->get_tx_gain_range(actualChannel).to_pp_string() << endl;
    this->min_tx_gain = usrp->get_tx_gain_range(actualChannel).start();
    this->max_tx_gain = usrp->get_tx_gain_range(actualChannel).stop();
    cout << "RX gain is: " << usrp->get_rx_gain_range(actualChannel).to_pp_string() << endl;
    this->min_rx_gain = usrp->get_rx_gain_range(actualChannel).start();
    this->max_rx_gain = usrp->get_rx_gain_range(actualChannel).stop();

    cout << "TX bandwidth is" << usrp->get_tx_bandwidth_range(actualChannel).to_pp_string() << endl;
    this->min_tx_bandwidth = usrp->get_tx_bandwidth_range(actualChannel).start();
    this->max_tx_bandwidth = usrp->get_tx_bandwidth_range(actualChannel).stop();
    cout << "RX bandwidth is" << usrp->get_rx_bandwidth_range(actualChannel).to_pp_string() << endl;
    this->max_rx_bandwidth = usrp->get_rx_bandwidth_range(actualChannel).start();
    this->max_rx_bandwidth = usrp->get_rx_bandwidth_range(actualChannel).stop();

    cout << "TX frequency is" << usrp->get_tx_freq_range(actualChannel).to_pp_string() << endl;
    this->min_tx_frequency = usrp->get_tx_freq_range(actualChannel).start();
    this->max_tx_frequency = usrp->get_tx_freq_range(actualChannel).stop();
    cout << "RX frequency is" << usrp->get_rx_freq_range(actualChannel).to_pp_string() << endl;
    this->min_rx_frequency = usrp->get_rx_freq_range(actualChannel).start();
    this->max_rx_frequency = usrp->get_rx_freq_range(actualChannel).stop();

    cout << "\e[1m" << "Channel changing done" << "\e[0m" << endl;

}