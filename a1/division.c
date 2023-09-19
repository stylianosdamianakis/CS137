#include <stdio.h>

int division() {

    int num;
    int denom;
    int result;
    int sign;

    scanf("%d %d", &num, &denom);

    //if the result is a decimal
    if ((num/denom)*denom != num){

        //round away from zero
        sign = (num > 0 && denom > 0) || (num < 0 && denom < 0);
        result = (sign > 0)?num/denom+1:num/denom-1;

    } else {
        result = num/denom;
    }

    //print the result
    printf("%d\n", result);

    return 0;
}