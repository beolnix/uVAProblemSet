#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE "uVA00661TestCase"

// libs
#include <boost/test/unit_test.hpp>
#define BOOST_CHECK_EQUAL_MESSAGE(L, R, M) { BOOST_TEST_INFO(M); BOOST_CHECK_EQUAL(L, R); }

// classes to cover with tests
#include "../../src/uVA_00661/uVA_00661.hpp"

void verifyResultFor(std::string expectedResult, std::string input) {
    std::string actualResult = uVA_00661::calculate(input);
    
    char calcDetails[200];
    snprintf(calcDetails, sizeof(calcDetails), "[CALC DETAILS] input:%s; actual result:%s; expected result: %s;", input.c_str(), actualResult.c_str(), expectedResult.c_str());
    BOOST_CHECK_EQUAL_MESSAGE(actualResult, expectedResult, calcDetails);    
    BOOST_TEST_PASSPOINT();
}

BOOST_AUTO_TEST_SUITE(generic_tests);

BOOST_AUTO_TEST_CASE(given_test_data)
{
    verifyResultFor("Sequence 1\nFuse was blown.\n\n", "2 2 10\n5\n7\n1\n2\n0 0 0");
    verifyResultFor("Sequence 1\nFuse was not blown.\nMaximal power consumption was 9 amperes.\n\n", "3 6 10\n2\n5\n7\n2\n1\n2\n3\n1\n3\n0 0 0");
    verifyResultFor("Sequence 1\nFuse was blown.\n\nSequence 2\nFuse was not blown.\nMaximal power consumption was 9 amperes.\n\n", "2 2 10\n5\n7\n1\n2\n3 6 10\n2\n5\n7\n2\n1\n2\n3\n1\n3\n0 0 0");
}

BOOST_AUTO_TEST_SUITE_END();

