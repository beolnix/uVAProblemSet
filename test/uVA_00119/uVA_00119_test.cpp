#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE "uVA100TestCase"

// libs
#include <boost/test/unit_test.hpp>
#define BOOST_CHECK_EQUAL_MESSAGE(L, R, M) { BOOST_TEST_INFO(M); BOOST_CHECK_EQUAL(L, R); }

#include "../../src/uVA_00119/uVA_00119.hpp"

void verifyReplaceForGivenString(std::string& input, std::string& expectedResult) {    
    std::string actualResult = uVA_00119::calculate(input);

    char calcDetails[200];
    snprintf(calcDetails, sizeof(calcDetails), "[CALC DETAILS] input:%s; actual result:%s; expected result: %s;", &input, &actualResult, &expectedResult);
    BOOST_CHECK_EQUAL_MESSAGE(actualResult, expectedResult, calcDetails);    
    BOOST_TEST_PASSPOINT();
}

BOOST_AUTO_TEST_CASE(given_test_data)
{
    // smoke test
    std::string input = "3\nliz steve dave\nliz 30 1 steve\nsteve 55 2 liz dave\ndave 0 2 steve liz\n2\ntest1 test2\ntest1 30 1 test2\ntest2 0 1 test1";
    std::string expected = "liz -3\nsteve -24\ndave 27\n\ntest1 -30\ntest2 30\n";
    verifyReplaceForGivenString(input, expected);
}