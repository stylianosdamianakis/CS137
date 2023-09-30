#include <stdio.h>

int sum_helper (int n) {

    if (n == 0) return 0;

    printf("%d", n);

    int total = sum_helper(n-1);

    printf("%d", n);

    return n + total;
}

int sum (int n) {
    printf("\n%d", sum_helper(n));
}



void is_prime(int n, int divisor){

    if (divisor == 1) {
        printf("%d\n",n);
        return;
    }

    if (n % divisor == 0){
        return;
    }

    is_prime(n,divisor-1);
}

void print_primes(void){

    int n = 0;

    if(!scanf("%d", &n)) return;

    is_prime(n,n/2);

    print_primes();
}
