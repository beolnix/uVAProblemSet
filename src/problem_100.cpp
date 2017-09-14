#include <iostream>
#include <algorithm>
#include <string>
#include <math.h> 
using namespace std;

int main() {
    int i, j;
    // char line[1000];
    long cycleLength[10000] = {0};
    long temp[10000] = {0};
    freopen("/Users/dan.atmakin/dev/contest/practise_01/test.txt", "r", stdin);
    while(scanf("%d %d", &i, &j) != EOF) {        

        long start = i;
        long end = j;
        if (start > end) {
            start = j;
            end = i;
        }

        long cycleMax = 0;
        for (int cur = start; cur <= end; cur++) {
            long nextNum = cur;            
            long step = 1;
            long count = 0;
            TEST:
            count = count + 1;            
            temp[step] = nextNum;
            if (nextNum < 10000 && cycleLength[nextNum] > 0) {
                step = step + cycleLength[nextNum] - 1;
                goto FINISH;
            }
            if (nextNum == 1){
                goto FINISH;
            } else {
                step = step + 1;
                if (nextNum % 2 == 0) {                
                    nextNum = nextNum / 2;
                    goto TEST;
                } else {
                    nextNum = (3 * nextNum) + 1;
                    goto TEST;
                }
            }
            FINISH:
            if (step > cycleMax) {
                cycleMax = step;
            }
            for (long i2 = 1; i2 < count; i2++) {
                if (temp[i2] < 10000){
                    cycleLength[temp[i2]] = step - i2 + 1;
                }
            }
        }
        printf("%d %d %ld\n", i, j, cycleMax);
    }

    return 0;
}
