
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE "uVA_11586TestCase"

// libs
#include <boost/test/unit_test.hpp>
#define BOOST_CHECK_EQUAL_MESSAGE(L, R, M) { BOOST_TEST_INFO(M); BOOST_CHECK_EQUAL(L, R); }

#include "../../src/uVA_11586/uVA_11586.hpp"

void verifyReplaceForGivenString(std::string& input, std::string& expectedResult) {    
    std::string actualResult = uVA_11586::calculate(input);

    char calcDetails[200];
    snprintf(calcDetails, sizeof(calcDetails), "[CALC DETAILS] input:%s; actual result:%s; expected result: %s;", &input, &actualResult, &expectedResult);
    BOOST_CHECK_EQUAL_MESSAGE(actualResult, expectedResult, calcDetails);    
    BOOST_TEST_PASSPOINT();
}

BOOST_AUTO_TEST_CASE(given_test_data)
{

    std::string input1 = "1\nMF MF\n";
    std::string expected1 = "LOOP\n";
    verifyReplaceForGivenString(input1, expected1);

    std::string input2 = "1\nFM FF MF MM\n";
    std::string expected2 = "LOOP\n";
    verifyReplaceForGivenString(input2, expected2);

    std::string input3 = "1\nMM FF\n";
    std::string expected3 = "LOOP\n";
    verifyReplaceForGivenString(input3, expected3);

    std::string input4 = "1\nMF MF MF MF FF\n";
    std::string expected4 = "NO LOOP\n";
    verifyReplaceForGivenString(input4, expected4);

    std::string input5 = "4\nMF MF\nFM FF MF MM\nMM FF\nMF MF MF MF FF\n";
    std::string expected5 = "LOOP\nLOOP\nLOOP\nNO LOOP\n";
    verifyReplaceForGivenString(input5, expected5);
}
