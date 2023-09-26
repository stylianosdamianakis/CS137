#include <stdio.h>

void numberPairs (int n) {

    if (n == 0) return;

    int lastDig = n % 10;
    int scndLastDig = (n / 10) % 10;

    numberPairs(n / 10);

    if (lastDig != scndLastDig) {
        printf("%d", n % 10);
        printf("%d", n % 10);
    }
}