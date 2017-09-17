#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits>
#include "uVA_0100.hpp"

#define CACHE_MAX 10000

int main()
{
    int i, j;
    long cycleLength[CACHE_MAX] = {0};
    long temp[CACHE_MAX] = {0};
    long cacheMax = CACHE_MAX;
    while (scanf("%d %d", &i, &j) != EOF)
    {
        int result = uVA_0100::calculateMaxCycleLengthForRange(&i, &j, temp, cycleLength, &cacheMax);
        printf("%d %d %d\n", i, j, result);
    }

    return 0;
}
