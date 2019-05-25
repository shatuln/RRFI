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

ETSI_RRS_RRFITests::~ETSI_RRS_RRFITests() {
}
