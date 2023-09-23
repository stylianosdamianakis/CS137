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

    printf("\n");
}


void rotation(int w){

    //initialize variables
    int corner1, corner2, corner3, corner4 = 0;

    //get the number of frames that need to be printed
    int size = (w % 2 == 0)?(w+1)/2:(w+1)/2-1;

    //loop through each frame
    for (int i = 0; i < size; i++) {

        corner1 = 1+(w+1)*i;
        corner2 = w+(w-1)*i;
        corner3 = w*w-(w+1)*i;
        corner4 = w*w-(w-1)-(w-1)*i;

        //loop through the number of sets of 4 nums that need to be printed
        for (int j = 0; j < (w-1)-2*i; j++) {
            printf("%d %d %d %d ", corner1+j, corner2+(w*j), corner3-1*j, corner4-w*j);
        }
    }

    //print the middle number if applicable
    if (w % 2 == 1){
        printf("%d", (w/2+1)+w*(w/2));
    }

    printf("\n");
}

