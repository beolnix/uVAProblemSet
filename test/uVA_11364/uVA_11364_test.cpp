#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE "uVA100TestCase"

// libs
#include <boost/test/unit_test.hpp>
#define BOOST_CHECK_EQUAL_MESSAGE(L, R, M) { BOOST_TEST_INFO(M); BOOST_CHECK_EQUAL(L, R); }

// classes to cover with tests
#include "../../src/uVA_11364/uVA_11364.hpp"

void verifyResultFor(int expectedResult, int shopArray[], int *numberOfShops) {
    int actualResult = uVA_11364::calculateDistance(shopArray, numberOfShops);
    
    char calcDetails[200];
    snprintf(calcDetails, sizeof(calcDetails), "[CALC DETAILS] actual result:%d; expected result: %d;", actualResult, expectedResult);
    BOOST_CHECK_EQUAL_MESSAGE(actualResult, expectedResult, calcDetails);    
    BOOST_TEST_PASSPOINT();
}

BOOST_AUTO_TEST_SUITE(generic_tests);

BOOST_AUTO_TEST_CASE(given_test_data)
{
    int test[] = {24,13,89,37};
    int numberOfShops = 4;
    verifyResultFor(152, test, &numberOfShops);

    int test2[] = {7,30,41,14,39,42};
    int numberOfShops2 = 6;
    verifyResultFor(70, test2, &numberOfShops2);
}

BOOST_AUTO_TEST_SUITE_END();

