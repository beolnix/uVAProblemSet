
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE "uVA_11507TestCase"

// libs
#include <boost/test/unit_test.hpp>
#define BOOST_CHECK_EQUAL_MESSAGE(L, R, M) { BOOST_TEST_INFO(M); BOOST_CHECK_EQUAL(L, R); }

#include "../../src/uVA_11507/uVA_11507.hpp"

void verifyReplaceForGivenString(std::string& input, std::string& expectedResult) {    
    std::string actualResult = uVA_11507::calculate(input);

    char calcDetails[200];
    snprintf(calcDetails, sizeof(calcDetails), "[CALC DETAILS] input:%s; actual result:%s; expected result: %s;", &input, &actualResult, &expectedResult);
    BOOST_CHECK_EQUAL_MESSAGE(actualResult, expectedResult, calcDetails);    
    BOOST_TEST_PASSPOINT();
}

BOOST_AUTO_TEST_CASE(given_test_data)
{

    std::string input1 = "3\n+z -z\n0\n";
    std::string expected1 = "+x\n";
    verifyReplaceForGivenString(input1, expected1);

    std::string input2 = "3\n+z +y\n0\n";
    std::string expected2 = "+z\n";
    verifyReplaceForGivenString(input2, expected2);

    std::string input3 = "2\n+z\n0\n";
    std::string expected3 = "+z\n";
    verifyReplaceForGivenString(input3, expected3);

    std::string input4 = "4\n+z +y +z\n0\n";
    std::string expected4 = "-x\n";
    verifyReplaceForGivenString(input4, expected4);

    std::string input5 = "5\nNo +z No No\n0\n";
    std::string expected5 = "+z\n";
    verifyReplaceForGivenString(input5, expected5);

    // complete smoke test
    std::string input = "3\n+z -z\n3\n+z +y\n2\n+z\n4\n+z +y +z\n5\nNo +z No No\n0\n";
    std::string expected = "+x\n+z\n+z\n-x\n+z\n";
    verifyReplaceForGivenString(input, expected);
}
