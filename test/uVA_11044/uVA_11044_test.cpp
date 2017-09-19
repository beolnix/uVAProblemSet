#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE "uVA100TestCase"

// libs
#include <boost/test/unit_test.hpp>
#define BOOST_CHECK_EQUAL_MESSAGE(L, R, M) { BOOST_TEST_INFO(M); BOOST_CHECK_EQUAL(L, R); }

// classes to cover with tests
#include "../../src/uVA_11044/uVA_11044.hpp"

void verifyResultFor(int expectedResult, int x, int y) {
    int actualResult = uVA_11044::calculate(&x, &y);
    
    char calcDetails[200];
    snprintf(calcDetails, sizeof(calcDetails), "[CALC DETAILS] x:%d; y:%d; actual result:%d; expected result: %d;", x, y, actualResult, expectedResult);
    BOOST_CHECK_EQUAL_MESSAGE(actualResult, expectedResult, calcDetails);    
    BOOST_TEST_PASSPOINT();
}

BOOST_AUTO_TEST_SUITE(generic_tests);

BOOST_AUTO_TEST_CASE(given_test_data)
{
    verifyResultFor(4, 6, 6);
    verifyResultFor(4, 7, 7);
    verifyResultFor(12, 9, 13);
    
}

BOOST_AUTO_TEST_SUITE_END();

