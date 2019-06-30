//
// Created by leoind on 25.05.19.
//

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE RRFI Tests
#include <boost/test/unit_test.hpp>
#include "ETSI_RRS_USRP_Device.h"
#include "ETSI_RRS_RRFI.h"
#include <fstream>

struct TestFixture {
    ETSI_RRS_USRP_Device usrpDevice;
    ETSI_RRS_RRFI rrfi;
    TestFixture() : rrfi(usrpDevice) {}

    ~TestFixture() = default;
};

BOOST_FIXTURE_TEST_SUITE(TestAntennaManagementServices, TestFixture)

    BOOST_AUTO_TEST_CASE(setTxAntennaPort_true) {
        const int a = 0;
        BOOST_CHECK_EQUAL(rrfi.set_txAntennaPort(a), true);
    }

    BOOST_AUTO_TEST_CASE(setTxAntennaPort_false) {
        const int a = 1;
        BOOST_CHECK_EQUAL(rrfi.set_txAntennaPort(a), false);
    }

    BOOST_AUTO_TEST_CASE(setRxAntennaPort_true) {
        const int a = 1;
        BOOST_CHECK_EQUAL(rrfi.set_rxAntennaPort(a), true);
    }

    BOOST_AUTO_TEST_CASE(setRxAntennaPort_false) {
        const int a = -2;
        BOOST_CHECK_EQUAL(rrfi.set_rxAntennaPort(a), false);
    }

BOOST_AUTO_TEST_SUITE_END()

BOOST_FIXTURE_TEST_SUITE(TestPowerControlServices, TestFixture)

    BOOST_AUTO_TEST_CASE(setTxMaxPowerLevel_true) {
        const int a = 90;
        BOOST_CHECK_EQUAL(rrfi.set_maxTxPowerLevel(a), true);
    }

    BOOST_AUTO_TEST_CASE(setTxPowerLevel) {
        double a = usrpDevice.min_tx_gain;
        BOOST_CHECK_EQUAL(rrfi.set_txPowerLevel(a), true);
        a = a - 1;
        BOOST_CHECK_EQUAL(rrfi.set_txPowerLevel(a), false);
        a = usrpDevice.max_tx_gain;
        BOOST_CHECK_EQUAL(rrfi.set_txPowerLevel(a), true);
        a = a + 1;
        BOOST_CHECK_EQUAL(rrfi.set_txPowerLevel(a), false);
    }

    BOOST_AUTO_TEST_CASE(setRxGain) {
        double a = usrpDevice.min_rx_gain;
        BOOST_CHECK_EQUAL(rrfi.set_rxGain(a), true);
        a = a - 1;
        BOOST_CHECK_EQUAL(rrfi.set_rxGain(a), false);
        a = usrpDevice.max_rx_gain;
        BOOST_CHECK_EQUAL(rrfi.set_rxGain(a), true);
        a = a + 1;
        BOOST_CHECK_EQUAL(rrfi.set_rxGain(a), false);
    }

BOOST_AUTO_TEST_SUITE_END()

BOOST_FIXTURE_TEST_SUITE(TestSpectrumControlServices, TestFixture)

    BOOST_AUTO_TEST_CASE(setRxCenterFrequency) {
        double a = usrpDevice.min_rx_frequency;
        BOOST_CHECK_EQUAL(rrfi.set_rxCenterFrequency(a), true);
        a = a - 1;
        BOOST_CHECK_EQUAL(rrfi.set_rxCenterFrequency(a), false);
        a = usrpDevice.max_rx_frequency;
        BOOST_CHECK_EQUAL(rrfi.set_rxCenterFrequency(a), true);
        a = a + 1;
        BOOST_CHECK_EQUAL(rrfi.set_rxCenterFrequency(a), false);
    }

    BOOST_AUTO_TEST_CASE(setTxCenterFrequency) {
        double a = usrpDevice.min_tx_frequency;
        BOOST_CHECK_EQUAL(rrfi.set_txCenterFrequency(a), true);
        a = a - 1;
        BOOST_CHECK_EQUAL(rrfi.set_txCenterFrequency(a), false);
        a = usrpDevice.max_tx_frequency;
        BOOST_CHECK_EQUAL(rrfi.set_txCenterFrequency(a), true);
        a = a + 1;
        BOOST_CHECK_EQUAL(rrfi.set_txCenterFrequency(a), false);
    }

    BOOST_AUTO_TEST_CASE(setRxBandwidth) {
        double a = usrpDevice.min_rx_bandwidth;
        BOOST_CHECK_EQUAL(rrfi.set_rxBandwidth(a), true);
        a = a - 1;
        BOOST_CHECK_EQUAL(rrfi.set_rxBandwidth(a), false);
        a = usrpDevice.max_rx_bandwidth;
        BOOST_CHECK_EQUAL(rrfi.set_rxBandwidth(a), true);
        a = a + 1;
        BOOST_CHECK_EQUAL(rrfi.set_rxBandwidth(a), false);
    }

    BOOST_AUTO_TEST_CASE(setTxBandwidth) {
        double a = usrpDevice.min_tx_bandwidth;
        BOOST_CHECK_EQUAL(rrfi.set_txBandwidth(a), true);
        a = a - 1;
        BOOST_CHECK_EQUAL(rrfi.set_txBandwidth(a), false);
        a = usrpDevice.max_tx_bandwidth;
        BOOST_CHECK_EQUAL(rrfi.set_txBandwidth(a), true);
        a = a + 1;
        BOOST_CHECK_EQUAL(rrfi.set_txBandwidth(a), false);
    }

    BOOST_AUTO_TEST_CASE(setRxSamplingRate) {
        double a = usrpDevice.min_rx_rate;
        BOOST_CHECK_EQUAL(rrfi.set_rxSamplingRate(a), true);
        a = a - 1;
        BOOST_CHECK_EQUAL(rrfi.set_rxSamplingRate(a), false);
        a = usrpDevice.max_rx_rate;
        BOOST_CHECK_EQUAL(rrfi.set_rxSamplingRate(a), true);
        a = a + 1;
        BOOST_CHECK_EQUAL(rrfi.set_rxSamplingRate(a), false);
    }

    BOOST_AUTO_TEST_CASE(setTxSamplingRate) {
        double a = usrpDevice.min_tx_rate;
        BOOST_CHECK_EQUAL(rrfi.set_txSamplingRate(a), true);
        a = a - 1;
        BOOST_CHECK_EQUAL(rrfi.set_txSamplingRate(a), false);
        a = usrpDevice.max_tx_rate;
        BOOST_CHECK_EQUAL(rrfi.set_txSamplingRate(a), true);
        a = a + 1;
        BOOST_CHECK_EQUAL(rrfi.set_txSamplingRate(a), false);
    }

BOOST_AUTO_TEST_SUITE_END()

BOOST_FIXTURE_TEST_CASE(Set_WIFI_Parameters, TestFixture) {
    const double freq = 2400000000;
    const double bw = 20000000;
    const double sr = 2000000;
    const double gain = 60;

    BOOST_CHECK_EQUAL(rrfi.set_txAntennaPort(0), true);
    BOOST_CHECK_EQUAL(rrfi.set_txCenterFrequency(freq), true);
    BOOST_CHECK_EQUAL(rrfi.get_txCenterFrequency(), freq);
    BOOST_CHECK_EQUAL(rrfi.set_txBandwidth(bw), true);
    BOOST_CHECK_EQUAL(rrfi.get_txBandwidth(), bw);
    BOOST_CHECK_EQUAL(rrfi.set_txSamplingRate(sr), true);
    BOOST_CHECK_EQUAL(rrfi.get_txSamplingRate(), sr);
    BOOST_CHECK_EQUAL(rrfi.set_txPowerLevel(gain), true);
    BOOST_CHECK_EQUAL(rrfi.get_txPowerLevel(), gain);

    BOOST_CHECK_EQUAL(rrfi.set_rxAntennaPort(1), true);
    BOOST_CHECK_EQUAL(rrfi.set_rxCenterFrequency(freq), true);
    BOOST_CHECK_EQUAL(rrfi.get_rxCenterFrequency(), freq);
    BOOST_CHECK_EQUAL(rrfi.set_rxBandwidth(bw), true);
    BOOST_CHECK_EQUAL(rrfi.get_rxBandwidth(), bw);
    BOOST_CHECK_EQUAL(rrfi.set_rxSamplingRate(sr), true);
    BOOST_CHECK_EQUAL(rrfi.get_rxSamplingRate(), sr);
    BOOST_CHECK_EQUAL(rrfi.set_rxGain(gain), true);
    BOOST_CHECK_EQUAL(rrfi.get_rxGain(), gain);

}

BOOST_FIXTURE_TEST_CASE(Set_BlueTooth_Parameters, TestFixture) {
    const double freq = 2480000000;
    const double bw = 35000000;
    const double sr = 2000000;
    const double gain = 50;

    BOOST_CHECK_EQUAL(rrfi.set_txAntennaPort(0), true);
    BOOST_CHECK_EQUAL(rrfi.set_txCenterFrequency(freq), true);
    BOOST_CHECK_EQUAL(rrfi.get_txCenterFrequency(), freq);
    BOOST_CHECK_EQUAL(rrfi.set_txBandwidth(bw), true);
    BOOST_CHECK_EQUAL(rrfi.get_txBandwidth(), bw);
    BOOST_CHECK_EQUAL(rrfi.set_txSamplingRate(sr), true);
    BOOST_CHECK_EQUAL(rrfi.get_txSamplingRate(), sr);
    BOOST_CHECK_EQUAL(rrfi.set_txPowerLevel(gain), true);
    BOOST_CHECK_EQUAL(rrfi.get_txPowerLevel(), gain);

    BOOST_CHECK_EQUAL(rrfi.set_rxAntennaPort(1), true);
    BOOST_CHECK_EQUAL(rrfi.set_rxCenterFrequency(freq), true);
    BOOST_CHECK_EQUAL(rrfi.get_rxCenterFrequency(), freq);
    BOOST_CHECK_EQUAL(rrfi.set_rxBandwidth(bw), true);
    BOOST_CHECK_EQUAL(rrfi.get_rxBandwidth(), bw);
    BOOST_CHECK_EQUAL(rrfi.set_rxSamplingRate(sr), true);
    BOOST_CHECK_EQUAL(rrfi.get_rxSamplingRate(), sr);
    BOOST_CHECK_EQUAL(rrfi.set_rxGain(gain), true);
    BOOST_CHECK_EQUAL(rrfi.get_rxGain(), gain);

}

BOOST_FIXTURE_TEST_CASE(Tx_Test, TestFixture) {
    const double freq = 2480000000;
    const double bw = 35000000;
    const double sr = 2000000;
    const double gain = 50;

    BOOST_CHECK_EQUAL(rrfi.set_txAntennaPort(0), true);
    BOOST_CHECK_EQUAL(rrfi.set_txCenterFrequency(freq), true);
    BOOST_CHECK_EQUAL(rrfi.get_txCenterFrequency(), freq);
    BOOST_CHECK_EQUAL(rrfi.set_txBandwidth(bw), true);
    BOOST_CHECK_EQUAL(rrfi.get_txBandwidth(), bw);
    BOOST_CHECK_EQUAL(rrfi.set_txSamplingRate(sr), true);
    BOOST_CHECK_EQUAL(rrfi.get_txSamplingRate(), sr);
    BOOST_CHECK_EQUAL(rrfi.set_txPowerLevel(gain), true);
    BOOST_CHECK_EQUAL(rrfi.get_txPowerLevel(), gain);

    const std::vector<short> buff(5000);
    for (int i = 0; i < 100; i++) {
        BOOST_CHECK_EQUAL(rrfi.tx_from_buff(buff, 50), true);
    }

    BOOST_CHECK_EQUAL(rrfi.tx_from_file("/home/leoind/Dropbox/RRS_Clion/pic.png", 100), true);
}