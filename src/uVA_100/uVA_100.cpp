#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits>

namespace uVA_100
{

int calculateCycleLength(int *number, long *temp, long *cycleLength, long *cache_max)
{
    long nextNum = *number;
    long step = 1;
    long count = 0;
TEST:
    count = count + 1;
    temp[step] = nextNum;
    if (nextNum < *cache_max && cycleLength[nextNum] > 0)
    {
        step = step + cycleLength[nextNum] - 1;
        goto FINISH;
    }
    if (nextNum == 1)
    {
        goto FINISH;
    }
    else
    {
        step = step + 1;
        if (nextNum % 2 == 0)
        {
            nextNum = nextNum / 2;
            goto TEST;
        }
        else
        {
            nextNum = (3 * nextNum) + 1;
            goto TEST;
        }
    }
FINISH:
    for (long i2 = 1; i2 < count; i2++)
    {
        if (temp[i2] < 10000)
        {
            cycleLength[temp[i2]] = step - i2 + 1;
        }
    }
    return step;
}

int calculateMaxCycleLengthForRange(int *start, int *end, long *temp, long *cycleLength, long *cacheMax)
{
    int actualStart = *start;
    int actualEnd = *end;
    if (actualStart > actualEnd)
    {
        actualStart = *end;
        actualEnd = *start;
    }

    int maxLength = 0;
    for (int number = actualStart; number <= actualEnd; number++)
    {
        int currentLength = calculateCycleLength(&number, temp, cycleLength, cacheMax);
        if (currentLength > maxLength)
        {
            maxLength = currentLength;
        }
    }
    return maxLength;
}
}