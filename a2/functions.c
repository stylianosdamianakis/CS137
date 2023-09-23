#include "functions.h"
#include <stdio.h>

void square(int w){

    //loop through rows
    for (int i = 0; i < w; i++) {

        //loop through columns
        for (int j = 1; j <= w; j++) {

            //print the number
            printf("%d ", j + (i*w));
        }

        //print a new line
        printf("\n");
    }
}


void spiral(int w){

    //print the first set of numbers
    for (int i = 0; i < w; i++) {
        printf("%d ", i+1);
    }

    //keep track of the current value and signs to be used in the loop
    int value = w;
    int sign = 1;

    //decrement the amount of characters that need to be printed by one
    for (int i = w; i > 0; i--) {

        //add or subtract w from the previous number (vertical lines)
        for (int j = 1; j < i; j++) {
            printf("%d ", value+w*sign*j);
            value = (j == i-1)?value+w*sign*j:value;
        }

        //flip the sign
        sign *= -1;

        //add or subtract one from the previous number (horizontal lines)
        for (int j = 1; j < i ; j++) {
            value += sign;
            printf("%d ", value);
        }

    }
}


void rotation(int w){


}
