#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits>

namespace uVA_00573
{
    int smartSimulation(int h, int u, int d, int f) {
        int n = 1;
        double currentHeight = 0;
        while (currentHeight >= 0) {
            double currentFatigue = (double)u / 100.0 * (double)f * (n - 1);
            double currentUp = u - currentFatigue;
            if (currentUp > 0) {
                currentHeight = currentHeight + currentUp;
            }
    
            if (currentHeight > h) {
                return n;
            }
    
            currentHeight = currentHeight - d;
            if (currentHeight < 0) {
                return n * -1;
            }
            n = n + 1;
        }
    
        return n * -1;
    }
}