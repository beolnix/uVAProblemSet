#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits>
#include <sstream>
#include <vector>
#include <iterator>

namespace uVA_00119
{
    template<typename Out>
    void split(const std::string &s, char delim, Out result) {
        std::stringstream ss(s);
        std::string item;
        while (std::getline(ss, item, delim)) {
            *(result++) = item;
        }
    }
    std::vector<std::string> split(const std::string &s, char delim) {
        std::vector<std::string> elems;
        split(s, delim, std::back_inserter(elems));
        return elems;
    }

    struct testcase {
        int numberOfParticipants;
        std::vector<std::string> orderedParticipants;
    } ;

    struct person {
        std::string name;
        int order;
        int initialBalance;
        int cash;        

    } ;

    person create(std::string& str) {        
        std::vector<std::string> guys = split(str, ' ');
        // sscanf (str,"%s %*s %d",str,&i);
        
    }
    
    

    std::string calculate(std::string& str) {

        

        std::vector<std::string> input = split(str, '\n');
        for(std::vector<std::string>::size_type i = 0; i != input.size(); i++) {
            std::string currentString = input[i];
        }

        return NULL;
    }



}