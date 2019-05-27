//
// Created by leoind on 25.05.19.
//

#include "ETSI_RRS_RRFITests.h"
#include "ETSI_RRS_USRP_Device.h"
#include <boost/test/unit_test.hpp>

ETSI_RRS_RRFITests::ETSI_RRS_RRFITests() {

}

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

ETSI_RRS_RRFITests::~ETSI_RRS_RRFITests() {
}
