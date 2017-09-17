#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE "uVA100TestCase"

// libs
#include <boost/test/unit_test.hpp>
#define BOOST_CHECK_EQUAL_MESSAGE(L, R, M) { BOOST_TEST_INFO(M); BOOST_CHECK_EQUAL(L, R); }

#include "../../src/uVA_0272/uVA_0272.hpp"

void verifyReplaceForGivenString(std::string& input, std::string& expectedResult) {    
    std::string actualResult = uVA_0272::replace(input);

    char calcDetails[200];
    snprintf(calcDetails, sizeof(calcDetails), "[CALC DETAILS] input:%s; actual result:%s; expected result: %s;", &input, &actualResult, &expectedResult);
    BOOST_CHECK_EQUAL_MESSAGE(actualResult, expectedResult, calcDetails);    
    BOOST_TEST_PASSPOINT();
}

BOOST_AUTO_TEST_CASE(given_test_data)
{
    // smoke test
    std::string input = "\"To be or not to be,\" quoth the Bard, \"that is the question\".";
    std::string expected = "``To be or not to be,'' quoth the Bard, ``that is the question''.";
    verifyReplaceForGivenString(input, expected);
}