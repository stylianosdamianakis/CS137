#include <stdio.h>

void pyramid(int n){
    for(int i = 0; i < n; i++){
        for(int k = 0; k < n - (i+1); k++){
            printf(" ");
        }
        printf("*");
        for(int j = 0; j < i; j++){
            printf("@@");
        }
        printf("*\n");
    }
}

int filterdigit(int num, int digit){
    if(num<10){
        if(num==digit)return 0;
        return num;
    }
    return (num%10 == digit)?filterdigit(num/10, digit):filterdigit(num/10, digit)*10+(num%10);
}

int power(int b, int n){
    if(n==0) return 1;
    return b*power(b,n-1);
}

int geometric_sum(int b, int n){
    if(n==0) return 1;
    return power(b, n) + geometric_sum(b, n-1);
}

int helper(long int num, int place, int acc){
    if(num == 0) return acc;
    acc += (num % 10)*place;
    helper(num/10, place/10, acc);
}

int getSize(int num, int acc){
    if (num == 1) return acc;
    getSize(num/10, acc*10);
}

int fun(long int num){
    helper(num, getSize(num, 1), 0);
}

int max_input(int largest){
    int n = 0;
    if(!scanf("%d", &n)){
        return largest;
    }
    largest = (largest>n)?largest:n;
    max_input(largest);
}

int read_ints(){
    int min,min_i,max,max_i,x,index;
    if(scanf("%d", &x)){
        min = x;
        max = x;
        index = 1;
        max_i = 1;
        min_i = 1;
    } else {
        printf("No integer given.");
        return 0;
    }

    while(scanf("%d", &x)){
        index++;
        if(x>=max){
            max = x;
            max_i = index;
        }
        if(x<=min){
            min = x;
            min_i = index;
        }
    }
    printf("(%d, %d)(%d, %d)", min, min_i, max, max_i);
    return 0;
}

