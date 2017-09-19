#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits>

int main()
{
    int number; 
    scanf("%d", &number);
    for (int i = 0; i < number; i++) {
        long a, b;
        scanf("%ld %ld", &a, &b);

        if (a > b) {
            printf(">\n");
        } else if (a < b) {
            printf("<\n");
        } else {
            printf("=\n");
        }
    }

    return 0;
}
