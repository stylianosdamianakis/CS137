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
