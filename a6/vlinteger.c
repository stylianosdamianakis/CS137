#include "vlinteger.h"
#include <stdlib.h>
#include <stdio.h>

struct linteger *vlintegerCreate(void) {
    struct linteger *t1 = malloc(sizeof(struct linteger));
    t1->arr = NULL;
    t1->length = 0;	// no values in t1.
    return t1;
}

int power(int x, int y) {
    int total = 1;
    for (int i = 0; i < y; i++) {
        total*=x;
    }

    return total;
}

void vlintegerPrint(struct linteger *t1) {
    printf("length=%d\n", t1->length);
    for (int i = 0; i < t1->length; ++i)
    {
        printf("%d", t1->arr[i]);
    }
    printf("\n");
}

void vlintegerDestroy(struct linteger *t1) {
    if (t1)
    {
        free(t1->arr);	// free the inside array first
        free(t1);	// then free the structure
    }
}

void vlintegerRead(struct linteger *t1) {

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


struct linteger *vlintegerAdd(struct linteger *t1, struct linteger *t2) {

    //finding the sum
    int sum = 0;
    for (int i = 0; i < t1->length; i++) {
        sum += t1->arr[i] * power(10, t1->length - i - 1);
    }
    for (int i = 0; i < t2->length; i++) {
        sum += t2->arr[i] * power(10, t2->length - i - 1);
    }

    //find the length of the resulting sum
    int length = 0;
    for (int i = sum; i > 0; i/=10) {
        length++;
    }

    //create the final structure
    struct linteger *total = vlintegerCreate();

    int sumCopy = sum;
    int *array = malloc(length * sizeof(int));
    for (int i = 0; sumCopy > 0; i++) {
        array[length-1-i] = sumCopy%10;
        sumCopy/=10;
    }

    total->arr = array;
    total->length = length;

    return total;
}


struct linteger *vlintegerMult(struct linteger *t1, struct linteger *t2) {

    //finding the sums
    int sum1 = 0;
    int sum2 = 0;

    for (int i = 0; i < t1->length; i++) {
        sum1 += t1->arr[i] * power(10, t1->length - i - 1);
    }
    for (int i = 0; i < t2->length; i++) {
        sum2 += t2->arr[i] * power(10, t2->length - i - 1);
    }

    int tot = sum1 * sum2;

    //find the length of the resulting sum
    int length = 0;
    for (int i = tot; i > 0; i/=10) {
        length++;
    }

    //create the final structure
    struct linteger *total = vlintegerCreate();

    int totCopy = tot;
    int *array = malloc(length * sizeof(int));
    for (int i = 0; totCopy > 0; i++) {
        array[length-1-i] = totCopy%10;
        totCopy/=10;
    }

    total->arr = array;
    total->length = length;

    return total;
}
