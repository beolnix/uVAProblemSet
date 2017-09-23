#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE "uVA00573TestCase"

// libs
#include <boost/test/unit_test.hpp>
#define BOOST_CHECK_EQUAL_MESSAGE(L, R, M) { BOOST_TEST_INFO(M); BOOST_CHECK_EQUAL(L, R); }

#include "../../src/uVA_00573/uVA_00573.hpp"

void verifyReplaceForGivenString(int expectedResult, int h, int u, int d, int f) {    
    int actualResult = uVA_00573::smartSimulation(h, u, d, f);

    char calcDetails[200];
    snprintf(calcDetails, sizeof(calcDetails), "[CALC DETAILS] h:%d u:%d d:%d f:%d actual result:%d; expected result: %d;", h, u, d, f, actualResult, expectedResult);
    BOOST_CHECK_EQUAL_MESSAGE(actualResult, expectedResult, calcDetails);    
    BOOST_TEST_PASSPOINT();
}

BOOST_AUTO_TEST_CASE(given_test_data)
{    
    verifyReplaceForGivenString(3, 6, 3, 1, 10);
    verifyReplaceForGivenString(-4, 10, 2, 1, 50);
    verifyReplaceForGivenString(-7, 50, 5, 3, 14);
    verifyReplaceForGivenString(-68, 50, 6, 4, 1);
    verifyReplaceForGivenString(20, 50, 6, 3, 1);
    verifyReplaceForGivenString(-2, 1, 1, 1, 1);
}