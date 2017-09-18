#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE "uVA100TestCase"

// libs
#include <boost/test/unit_test.hpp>
#define BOOST_CHECK_EQUAL_MESSAGE(L, R, M) { BOOST_TEST_INFO(M); BOOST_CHECK_EQUAL(L, R); }

// classes to cover with tests
#include "../../src/uVA_10550/uVA_10550.hpp"

void verifyResultFor(int expectedResult, int start, int first, int second, int third) {
    int actualResult = uVA_10550::calculateDegreesFor(&start, &first, &second, &third);
    
    char calcDetails[200];
    snprintf(calcDetails, sizeof(calcDetails), "[CALC DETAILS] start:%d; first:%d; second:%d; third:%d; actual result:%d; expected result: %d;", start, first, second, third, actualResult, expectedResult);
    BOOST_CHECK_EQUAL_MESSAGE(actualResult, expectedResult, calcDetails);    
    BOOST_TEST_PASSPOINT();
}

void verifyDistanceFor(int expectedResult, int start, int end, bool clockwise) {
    int actualResult = uVA_10550::distance(&start, &end, clockwise);
    
    char calcDetails[200];
    snprintf(calcDetails, sizeof(calcDetails), "[CALC DETAILS] start:%d; end:%d; clockwise:%s; actual result:%d; expected result: %d;", start, end, clockwise ? "true" : "false", actualResult, expectedResult);
    BOOST_CHECK_EQUAL_MESSAGE(actualResult, expectedResult, calcDetails);    
    BOOST_TEST_PASSPOINT();
}

BOOST_AUTO_TEST_SUITE(generic_tests);

BOOST_AUTO_TEST_CASE(given_test_data)
{
    verifyDistanceFor(20, 10, 350, true);
    verifyDistanceFor(340, 10, 30, true);
    verifyDistanceFor(90, 0, 270, true);
    verifyDistanceFor(120, 270, 30, false);
    verifyDistanceFor(120, 30, 270, true);

    verifyResultFor(1350, 0, 30, 0, 30);
    verifyResultFor(1350, 5, 35, 5, 35);
    verifyResultFor(1620, 0, 20, 0, 20);
    verifyResultFor(1620, 7, 27, 7, 27);
    verifyResultFor(1890, 0, 10, 0, 10);
    verifyResultFor(1890, 9, 19, 9, 19);

    verifyResultFor(360 * 6, 1, 1, 1, 1);
    verifyResultFor(360 * 3 + 9 * 3, 4, 3, 4, 3);
}

BOOST_AUTO_TEST_SUITE_END();

