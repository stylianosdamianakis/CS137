#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
extern void score_update();

int filterdigit(int num, int digit){
    if(num<10){
        if(num==digit)return 0;
        return num;
    }
    return (num%10 == digit)?filterdigit(num/10, digit):filterdigit(num/10, digit)*10+(num%10);
}

int main(void) {
    printf("%d", filterdigit(17271,1));
}