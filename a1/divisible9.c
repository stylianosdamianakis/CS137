#include <stdio.h>

int divisible9(){

    int input;
    int sum;

    scanf("%d", &input);

    //get the sum of all the numbers
    sum = input/10000 + (input/1000 - (input/10000)*10) + (input/100 - (input/1000)*10) + (input/10 - (input/100)*10) + (input - (input/10)*10);

    //print if the result is divisible by 9
    if ((sum/9)*9 != sum){
        printf("no\n");
    } else {
        printf("yes\n");
    }

    return 0;
}