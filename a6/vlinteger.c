#include "vlinteger.h"
#include <stdlib.h>
#include <stdio.h>

struct linteger *vlintegerCreate (void) {
    struct linteger *t1 = malloc(sizeof(struct linteger));
    t1->arr = NULL;
    t1->length = 0;	// no values in t1.
    return t1;
}

void vlintegerPrint (struct linteger *t1) {
    printf("length=%d\n", t1->length);
    for (int i = 0; i < t1->length; ++i)
    {
        printf("%d", t1->arr[i]);
    }
    printf("\n");
}

void vlintegerDestroy (struct linteger *t1) {
    if (t1)
    {
        free(t1->arr);	// free the inside array first
        free(t1);	// then free the structure
    }
}

void vlintegerRead (struct linteger *t1) {

    //reset the length and the array values
    t1->length = 0;
    t1->arr = malloc(0);
    int size = 0;

    int digit;
    while (scanf("%d", &digit)){

        //copy the data into the new array
        size += 4;
        int *newData = malloc(size);
        for (int i = 0; i < (size/sizeof(int))-1; i++) {
            newData[i] = t1->arr[i];
        }
        newData[t1->length] = digit;

        //free the old array
        free(t1->arr);

        //update to point to the new array
        t1->arr = newData;

        //update the length
        t1->length+=1;
    }
}


struct linteger *vlintegerAdd (struct linteger *t1, struct linteger *t2) {

    //creating the linteger struct to hold the sum
    struct linteger *total = vlintegerCreate();
    total->length = (t1->length > t2->length)?t1->length+1:t2->length+1;
    total->arr = malloc(total->length * sizeof(int));

    //summing up the two arrays
    for (int i = 0; i < total->length; i++) {

        int sum = 0;
        if (t1->length-1-i >= 0){
            sum += t1->arr[t1->length-1-i];
        }
        if (t2->length-1-i >= 0){
            sum += t2->arr[t2->length-1-i];
        }

        total->arr[total->length-i-1] = sum;
    }

    //calculating carryover
    for (int i = total->length-1; i > 0; i--) {
        if (total->arr[i] >= 10) {
            total->arr[i] -= 10;
            total->arr[i-1] += 1;
        }
    }

    //removing frontal zero if applicable
    if (total->arr[0] == 0) {
        struct linteger *total2 = vlintegerCreate();
        total2->length = total->length-1;
        total2->arr = malloc(total2->length * sizeof(int));

        //copying from total1 to total 2
        for (int i = 1; i < total->length; i++) {
            total2->arr[i-1] = total->arr[i];
        }

        free(total->arr);
        return total2;
    }

    return total;
}


struct linteger *vlintegerMult (struct linteger *t1, struct linteger *t2) {

    //creating the linteger struct to hold the product
    struct linteger *total = vlintegerCreate();
    total->length = t1->length + t2->length;
    total->arr = malloc(total->length * sizeof(int));

    //initializing the array with zeros
    for (int i = 0; i < total->length; i++) {
        total->arr[i] = 0;
    }

    //multiplying the structs
    for (int i = 0; i < t1->length; i++) {
        for (int j = 0; j < t2->length; j++) {
            total->arr[i+j+1] += t1->arr[i] * t2->arr[j];
        }
    }

    //calculating carryover
    for (int i = total->length-1; i > 0; i--) {
        if (total->arr[i] >= 10) {
            total->arr[i-1] += total->arr[i]/10;
            total->arr[i] %= 10;
        }
    }

    //removing frontal zero if applicable
    if (total->arr[0] == 0) {
        struct linteger *total2 = vlintegerCreate();
        total2->length = total->length-1;
        total2->arr = malloc(total2->length * sizeof(int));

        //copying from total1 to total 2
        for (int i = 1; i < total->length; i++) {
            total2->arr[i-1] = total->arr[i];
        }

        free(total->arr);
        return total2;
    }

    return total;
}
