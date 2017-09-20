#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits>

namespace uVA_11364
{ 
    int calculateDistance(int shopsArray[], int *numberOfShops) {
        int min = 99;
        int max = 0;

        for (int i = 0; i < *numberOfShops; i++) {
            if (shopsArray[i] < min) {
                min = shopsArray[i];
            }
            if (shopsArray[i] > max) {
                max = shopsArray[i];
            }
        }

        return 2 * (max - min);
    }
}
