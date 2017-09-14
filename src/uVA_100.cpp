#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits>

#define INT_MAX std::numeric_limits<int>::max()

namespace uVA_100
{

struct problemInputStruct
{
    int i;
    int j;
} problemInput[INT_MAX];

struct problemOutputStruct
{
    int i;
    int j;
    int cycleLength;
};

int main()
{
    int next_i, next_j;
    int cur = 0;
    while (scanf("%d %d", &next_i, &next_j) != EOF)
    {
        problemInput[cur].i = next_i;
        problemInput[cur].j = next_j;
        cur += 1;
    }
    return 0;
}

problemOutputStruct calculateMaxCycleLengthForAll(problemInputStruct input[], int &size)
{
    problemOutputStruct output[INT_MAX];
    for (int current = 0; current < size; current++)
    {
        output[current].i = input[current].i;
        output[current].j = input[current].j;
        output[current].cycleLength = calculateMaxCycleLengthForRange(input[current].i, input[current].j);
    }
    return &output;
}

int calculateMaxCycleLengthForRange(int &start, int &end)
{
    int actualStart = start;
    int actualEnd = end;
    if (start > end)
    {
        actualStart = end;
        actualEnd = start;
    }

    int maxLength = 0;
    for (int number = actualStart; number <= actualEnd; actualStart++)
    {
        int currentLength = calculateCycleLength(number);
        if (currentLength > maxLength)
        {
            maxLength = currentLength;
        }
    }
    return maxLength;
}

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
}
