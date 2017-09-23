#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits>
#include "uVA_00573.hpp"

int main()
{
    
    while (true)
    {        
        int h, u, d, f;
        scanf("%d", &h);
        if (h == 0) {
            break;
        }

        scanf("%d %d %d", &u, &d, &f);
        int result = uVA_00573::smartSimulation(h, u, d, f);
        if (result > 0) {
            printf("success on day %d\n", result);
        } else {
            int failOnDay = -1 * result;
            printf("failure on day %d\n", failOnDay);
        }

    }

    return 0;
}
