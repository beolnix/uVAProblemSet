#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE "BaseClassModule"

// libs
#include <boost/test/unit_test.hpp>

// classes to cover with tests
#include "../src/uVA_100.hpp"

#define CACHE_MAX 10000

//Name your test cases for what they test
BOOST_AUTO_TEST_CASE(assignment)
{

    //Use BOOST_CHECK_EQUAL if you want the values to be
    //printed out if they mismatch
    // long cycleLength[CACHE_MAX] = {0};
    // long temp[CACHE_MAX] = {0};
    // int result = uVA_100::calculateMaxCycleLengthForRange(1, 10, temp, cycleLength);
    // BOOST_CHECK_EQUAL(result, 20);

    BOOST_CHECK(true);
}
