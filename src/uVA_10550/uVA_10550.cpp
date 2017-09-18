#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits>

namespace uVA_10550
{
    int distance(int *alpha, int *beta, bool clockwise) {                       

        int correct = 360;
        if (*alpha > *beta && clockwise) {
            correct = 0;
        } else if (*alpha < *beta && !clockwise) {
            correct = 0;
        }

        if (clockwise) {
            return abs(correct - abs(*alpha - *beta));
        } else {
            return abs(correct - abs(*beta - *alpha));
        }
    }

    int calculateDegreesFor(int *start, int *first, int *second, int *third) {
        int startDegree = *start * 9;
        int firstDegree = *first * 9;
        int secondDegree = *second * 9;
        int thirdDegree = *third * 9;

        int firstTurn = distance(&startDegree, &firstDegree, true);
        // printf("first turn: %d\n", firstTurn);
        int secondTurn = distance(&firstDegree, &secondDegree, false);
        // printf("second turn: %d\n", secondTurn);
        int thirdTurn = distance(&secondDegree, &thirdDegree, true);
        // printf("third turn: %d\n", thirdTurn);
        

        return 360 + 360 + firstTurn + 360 + secondTurn + thirdTurn;
    }
}