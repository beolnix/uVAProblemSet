#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits>
#include "uVA_11364.hpp"


int main()
{
    int number; 
    scanf("%d", &number);
    for (int i = 0; i < number; i++) {
        int numberOfShops = 0;
        scanf("%d", &numberOfShops);
        int shops[numberOfShops];
        for (int shopCursor = 0; shopCursor < numberOfShops; shopCursor++) {
            scanf("%d", &shops[shopCursor]);
        }
        int result = uVA_11364::calculateDistance(shops, &numberOfShops);
        printf("%d\n", result);
    }

    return 0;
}
