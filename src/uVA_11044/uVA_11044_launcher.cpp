#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits>
#include "uVA_11044.hpp"

int main()
{
    int number; 
    scanf("%d", &number);
    for (int i = 0; i < number; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        int result = uVA_11044::calculate(&x, &y);
        printf("%d\n", result);
    }

    return 0;
}
