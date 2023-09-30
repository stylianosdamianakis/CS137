#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

int pow(int n, int acc, int num){

    if (num == 0) return acc;

    acc *= n;
    pow(n, acc, --num);
}


int sum(int n, int acc, int num){

    if (n == 0) return acc;

    acc += pow(n % 10, 1, num);
    sum(n / 10, acc, num);
}

int termCount(int n, int acc){

    if (n/10 == 0) return acc;
    termCount(n/10, ++acc);
}

bool narcissist(int n){

    int total = sum(n, 0, termCount(n, 1));

    if (total == n) return true;
    return false;
}
