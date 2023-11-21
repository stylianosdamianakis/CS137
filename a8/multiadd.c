#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>


long long int multiadd(long long int a[], int n){

    if (n < 1) return 0;
    if (n == 1) return a[0];

    //initialization
    long long int *countingArr = malloc(sizeof(long long int) * n);
    long long int *sortedArr = malloc(sizeof(long long int) * n);

    //initializing the arrays with zero
    for (int i = 0; i < n; i++) {
        countingArr[i] = 0;
        sortedArr[i] = 0;
    }

    //creating the counting array
    for (int i = 0; i < n; i++) {

        //if any input is not a natural number, return zero
        if (a[i] == 0) {
            free(countingArr);
            free(sortedArr);
            return 0;
        }
        countingArr[a[i] - 1]++;
    }

    //creating the sorted array
    int k = 0;
    for (int i = 0; i < n; i++) {
        while (countingArr[i] > 0) {
            sortedArr[k] = i+1;
            countingArr[i]--;
            k++;
        }
    }

    //toggling between operations until the final result is reached
    bool mult = true;
    int nVal = n;
    while (nVal > 1) {
        for (int i = 0; i < nVal/2; i++) {

            //multiplying concurrent integers
            if (mult) {
                sortedArr[i] = sortedArr[2*i] * sortedArr[2*i+1];

            //adding concurrent integers
            } else {
                sortedArr[i] = sortedArr[2*i] + sortedArr[2*i+1];
            }
        }

        nVal /= 2;
        mult = !mult;
    }

    long long int total;
    total = sortedArr[0];
    free(countingArr);
    free(sortedArr);
    return total;
}


/*int main(void){
    long long int a[8] = {1,4,3,6,5,3,2,8};
    assert(748 == multiadd(a,8));
    long long int b[16] = {0};
    assert(0 == multiadd(b,16));
    long long int c[16] = {1,6,5,8,6,7,5,4,8,9,10,2,12,14,1,1};
    assert(27498 == multiadd(c,16));
    return 0;
}

//different function that also might work
bool mult = true;
for (int i = n; i > 1; i/=2) {

    //multiplying concurrent integers
    if (mult) {
        for (int j = 0; j < i/2; j++) {
            sortedArr[j] = sortedArr[j*2] * sortedArr[j*2+1];
        }

    //adding concurrent integers
    } else {
        for (int j = 0; j < i/2; j++) {
            sortedArr[j] = sortedArr[j*2] + sortedArr[j*2+1];
        }
    }

    //flipping the operation
    mult = !mult;
}*/