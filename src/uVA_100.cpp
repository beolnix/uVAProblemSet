#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits>

// #define INT_MAX std::numeric_limits<int>::max()

int calculateCycleLength(int &number)
{
    long nextNum = number;
    long step = 1;
    long count = 0;
TEST:
    count = count + 1;
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
    return step;
}

int calculateMaxCycleLengthForRange(int start, int end)
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
        int currentLength = calculateCycleLength(number);
        if (currentLength > maxLength)
        {
            maxLength = currentLength;
        }
    }
    return maxLength;
}

int main()
{        
    int i, j;        
    while (scanf("%d %d", &i, &j) != EOF)
    {        
        int result = calculateMaxCycleLengthForRange(i, j);
        printf("%d %d %d\n", i, j, result);
    }

    return 0;
}
