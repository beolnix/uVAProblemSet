#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE "uVA100TestCase"

// libs
#include <boost/test/unit_test.hpp>

// classes to cover with tests
#include "../src/uVA_100/uVA_100.hpp"

#define CACHE_MAX 10000

BOOST_AUTO_TEST_SUITE(generic_tests);

long cycleLength[CACHE_MAX] = {0};
long temp[CACHE_MAX] = {0};
long cacheMax = CACHE_MAX;

void verifyResultForRange(int expectedResult, int i, int j) {
    int actualResult = uVA_100::calculateMaxCycleLengthForRange(&i, &j, cycleLength, temp, &cacheMax);
    BOOST_CHECK_EQUAL(actualResult, expectedResult);
    
    char buff[100];
    snprintf(buff, sizeof(buff), "[SUCCESS] i: %d, j:%d, result:%d", i, j, expectedResult);
    BOOST_TEST_MESSAGE(buff);
    BOOST_TEST_PASSPOINT();
}

BOOST_AUTO_TEST_CASE(given_test_data)
{

    // if start of the range is lower then beginning of a range
    verifyResultForRange(20, 1, 10);    

    // if start of the range greater then beginning of a range - result must be valid anyway
    verifyResultForRange(20, 10, 1);

    // other examples of a sample input
    verifyResultForRange(125, 100, 200);
    verifyResultForRange(89, 201, 210);
    verifyResultForRange(174, 900, 1000);
}

BOOST_AUTO_TEST_SUITE_END();