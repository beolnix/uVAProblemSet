import sys
import os

cmakeTemplate = '''
# !problemName! - main
add_executable(!problemName! src/!problemName!/!problemName!_launcher.cpp)
add_library (!problemName!_lib src/!problemName!/!problemName!.cpp src/!problemName!/!problemName!.hpp)
target_link_libraries(!problemName! !problemName!_lib)

# !problemName! - test
add_executable(!problemName!_test test/!problemName!/!problemName!_test.cpp)
target_link_libraries(!problemName!_test ${Boost_LIBRARIES} !problemName!_lib)

set_target_properties(!problemName!_test PROPERTIES 
            RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR}/build)

add_test( NAME !problemName!_test 
          WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build 
          COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/build/!problemName!_test)
'''

descTemplate = '''
# Problem
!problemName!: The 3n + 1 problem
[link to the problem page](https://uva.onlinejudge.org/...)

**TODO** put problem description here

## Input
**TODO** put input description here

## Output
**TODO** put output description here

## Sample Input
```
TODO put sample input here
```

## Sample Output
```
TODO put sample output here
```
'''

headerTeamplate = '''
#include <string>

namespace !problemName!
{ 
    std::string calculate(std::string& str);
}

'''

libTemplate = '''
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits>
#include <unordered_map>
#include <vector>

namespace !problemName! 
{
    std::string calculate(std::string& str) {
        return str;
    }
}
'''

launcherTemplate = '''
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits>
#include "!problemName!.hpp"

int main()
{
    std::string line;
    std::string completeInput;
    while (std::getline(std::cin, line))
    {        
        completeInput += line;
        completeInput += '\\n';        
    }

    std::string result = !problemName!::calculate(completeInput);
    printf("%s", result.c_str());

    return 0;
}
'''

testTemplate = '''
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE "!problemName!TestCase"

// libs
#include <boost/test/unit_test.hpp>
#define BOOST_CHECK_EQUAL_MESSAGE(L, R, M) { BOOST_TEST_INFO(M); BOOST_CHECK_EQUAL(L, R); }

#include "../../src/!problemName!/!problemName!.hpp"

void verifyReplaceForGivenString(std::string& input, std::string& expectedResult) {    
    std::string actualResult = !problemName!::calculate(input);

    char calcDetails[200];
    snprintf(calcDetails, sizeof(calcDetails), "[CALC DETAILS] input:%s; actual result:%s; expected result: %s;", &input, &actualResult, &expectedResult);
    BOOST_CHECK_EQUAL_MESSAGE(actualResult, expectedResult, calcDetails);    
    BOOST_TEST_PASSPOINT();
}

BOOST_AUTO_TEST_CASE(given_test_data)
{
    // smoke test
    std::string input = "test string\ntest string";
    std::string expected = "test string\ntest string";
    verifyReplaceForGivenString(input, expected);   // template just returns input string as it is
}
'''

testInputTemplate = '''
test string
test string
'''

def installCmake(problemName):
    print ("adding cmake instructions for problem: ", problemName)
    with open('./CMakeLists.txt','a') as cmake:
        cmakeInstructions = cmakeTemplate.replace("!problemName!", problemName)
        cmake.write(cmakeInstructions) 

def createDirIfDoesntExist(directory):
    if not os.path.exists(directory):
        os.makedirs(directory)

def installDescriptionFile(problemName):    
    filePath = "src/" + problemName + "/" + problemName + "_description.md"
    print ("Create problem description file: ", filePath)

    with open(filePath,'a') as descFile:
        description = descTemplate.replace("!problemName!", problemName)
        descFile.write(description) 

def installHeaderFile(problemName):    
    filePath = "src/" + problemName + "/" + problemName + ".hpp"
    print ("Create header file: ", filePath)

    with open(filePath,'a') as headerFile:
        headerContent = headerTeamplate.replace("!problemName!", problemName)
        headerFile.write(headerContent) 

def installLibFile(problemName):
    filePath = "src/" + problemName + "/" + problemName + ".cpp"
    print ("Create lib file: ", filePath)

    with open(filePath,'a') as libFile:
        libContent = libTemplate.replace("!problemName!", problemName)
        libFile.write(libContent)

def installLauncherFile(problemName):
    filePath = "src/" + problemName + "/" + problemName + "_launcher.cpp"
    print ("Create launcher file: ", filePath)

    with open(filePath,'a') as launcherFile:
        launcherContent = launcherTemplate.replace("!problemName!", problemName)
        launcherFile.write(launcherContent)

def installTestFile(problemName):
    filePath = "test/" + problemName + "/" + problemName + "_test.cpp"
    print ("Create test file: ", filePath)

    with open(filePath,'a') as testFile:
        testContent = testTemplate.replace("!problemName!", problemName)
        testFile.write(testContent)

def installTestInputFile(problemName):
    filePath = "test/" + problemName + "/" + problemName + "_test_input.txt"
    print ("Create test input file: ", filePath)

    with open(filePath,'a') as testInputFile:
        testInputContent = testInputTemplate.replace("!problemName!", problemName)
        testInputFile.write(testInputContent)        

def installDirectoryLayout(problemName):
    createDirIfDoesntExist("./src/" + problemName)
    createDirIfDoesntExist("./test/" + problemName)

def main():    
    if len(sys.argv) < 2:
        print("Please provide as the only argument problem name to create dummy layout and extend cmake script.")
        return


    problemName = sys.argv[1]
    installCmake(problemName)

    print("Create directory layout")
    installDirectoryLayout(problemName)

    installDescriptionFile(problemName)

    installHeaderFile(problemName)
    installLibFile(problemName)
    installLauncherFile(problemName)

    installTestFile(problemName)
    installTestInputFile(problemName)  

if __name__ == "__main__":
    main()      
