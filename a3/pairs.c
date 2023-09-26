#include <stdio.h>


void pairHelper (int n, int result) {

    if (n == 0) return;

    //
    printf("%d", result);
    printf("%d", result);
    //pairHelper(n / 10, );


}


void numberPairs (int n) {
    pairHelper(n, n % 10);
    printf("\n");
}