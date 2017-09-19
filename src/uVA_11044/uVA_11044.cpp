#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits>

namespace uVA_11044
{
    int calculate(int *x, int *y) {
        int realX = *x;
        if (*x > 2) {
            realX = *x - 2;
        } else if (*x > 1) {
            realX = *x - 1;
        }

        int realY = *y;
        if (*y > 2) {
            realY = *y - 2;
        } else if (*y > 1) {
            realY = *y - 1;
        }

        if ((realX * realY) <= 36) {
            return 4;
        }

        int xCor = (realX % 3) > 0 ? 1 : 0;
        int yCor = (realY % 3) > 0 ? 1 : 0;

        return (realX / 3 + xCor) * (realY / 3 + yCor);
    }
}