#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits>

int main()
{
    std::string line;
    while (std::getline(std::cin, line))
    {        
        printf("%s\n", line.c_str());        
    }

    return 0;
}
