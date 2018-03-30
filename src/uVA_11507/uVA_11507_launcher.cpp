
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits>
#include "uVA_11507.hpp"

int main()
{
    std::string line;
    std::string completeInput;
    while (std::getline(std::cin, line))
    {        
        completeInput += line;
        completeInput += '\n';        
    }

    std::string result = uVA_11507::calculate(completeInput);
    printf("%s", result.c_str());

    return 0;
}
