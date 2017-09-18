#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits>
#include "uVA_10550.hpp"

int main()
{
    int start, first, second, third;    
    while (scanf("%d %d %d %d", &start, &first, &second, &third) != EOF)
    {
        // stop on combination 0 0 0 0
        if (start == first && first == second && second == third && third == 0) {
            break;
        }
        int result = uVA_10550::calculateDegreesFor(&start, &first, &second, &third);
        printf("%d\n", result);
    }

    return 0;
}
