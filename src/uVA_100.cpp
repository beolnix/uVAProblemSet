#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits>

#define CACHE_MAX 10000

namespace uVA_100 
{    

int calculateCycleLength(int &number, long *temp, long *cycleLength)
{
    long nextNum = number;
    long step = 1;
    long count = 0;
TEST:
    count = count + 1;
    temp[step] = nextNum;
    if (nextNum < CACHE_MAX && cycleLength[nextNum] > 0) {
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
    for (long i2 = 1; i2 < count; i2++) {
        if (temp[i2] < 10000){
            cycleLength[temp[i2]] = step - i2 + 1;
        }
    }
    return step;
}

int calculateMaxCycleLengthForRange(int start, int end, long *temp, long *cycleLength)
{    
    int actualStart = start;
    int actualEnd = end;
    if (start > end)
    {
        actualStart = end;
        actualEnd = start;
    }

    int maxLength = 0;
    for (int number = actualStart; number <= actualEnd; number++)
    {    
        int currentLength = calculateCycleLength(number, temp, cycleLength);
        if (currentLength > maxLength)
        {
            maxLength = currentLength;
        }
    }
    return maxLength;
}
}


int main()
{        
    int i, j;        
    long cycleLength[CACHE_MAX] = {0};
    long temp[CACHE_MAX] = {0};
    while (scanf("%d %d", &i, &j) != EOF)
    {        
        int result = uVA_100::calculateMaxCycleLengthForRange(i, j, temp, cycleLength);
        printf("%d %d %d\n", i, j, result);
    }

    return 0;
}
