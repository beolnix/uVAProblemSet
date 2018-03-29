
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE "uVA_10141TestCase"

// libs
#include <boost/test/unit_test.hpp>
#define BOOST_CHECK_EQUAL_MESSAGE(L, R, M) { BOOST_TEST_INFO(M); BOOST_CHECK_EQUAL(L, R); }

#include "../../src/uVA_10141/uVA_10141.hpp"

void verifyReplaceForGivenString(std::string& input, std::string& expectedResult) {    
    std::string actualResult = uVA_10141::calculate(input);

    char calcDetails[200];
    snprintf(calcDetails, sizeof(calcDetails), "[CALC DETAILS] input:%s; actual result:%s; expected result: %s;", &input, &actualResult, &expectedResult);
    BOOST_CHECK_EQUAL_MESSAGE(actualResult, expectedResult, calcDetails);    
    BOOST_TEST_PASSPOINT();
}

BOOST_AUTO_TEST_CASE(given_test_data)
{
    // coffee smoke test
    std::string coffeeInput = "1 1\ncoffee\nStarbucks\n1.50 1\ncoffee\n0 0";
    std::string coffeeExpected = "RFP #1\nStarbucks\n";
    verifyReplaceForGivenString(coffeeInput, coffeeExpected);

    // cars smoke test
    std::string carsInput = "6 4\nengine\nbrakes\ntires\nashtray\nvinyl roof\ntrip computer\nChevrolet\n20000.00 3\nengine\ntires\nbrakes\nCadillac\n70000.00 4\nashtray\nvinyl roof\ntrip computer\nengine\nHyundai\n10000.00 3\nengine\ntires\nashtray\nLada\n6000.00 1\ntires\n0 0";
    std::string carsExpected = "RFP #1\nCadillac\n";
    verifyReplaceForGivenString(carsInput, carsExpected);

    // cars price smoke test
    std::string carsPriceInput = "6 4\nengine\nbrakes\ntires\nashtray\nvinyl roof\ntrip computer\nChevrolet\n20000.00 4\nengine\ntires\nbrakes\nashtray\nCadillac\n70000.00 4\nashtray\nvinyl roof\ntrip computer\nengine\nHyundai\n10000.00 3\nengine\ntires\nashtray\nLada\n6000.00 1\ntires\n0 0";
    std::string carsPriceExpected = "RFP #1\nChevrolet\n";
    verifyReplaceForGivenString(carsPriceInput, carsPriceExpected);

    // complete smoke test
    std::string input = "6 4\nengine\nbrakes\ntires\nashtray\nvinyl roof\ntrip computer\nChevrolet\n20000.00 3\nengine\ntires\nbrakes\nCadillac\n70000.00 4\nashtray\nvinyl roof\ntrip computer\nengine\nHyundai\n10000.00 3\nengine\ntires\nashtray\nLada\n6000.00 1\ntires\n1 1\ncoffee\nStarbucks\n1.50 1\ncoffee\n0 0";
    std::string expected = "RFP #1\nCadillac\n\nRFP #2\nStarbucks\n";
    verifyReplaceForGivenString(input, expected);
}
