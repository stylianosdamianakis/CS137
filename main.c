#include "a6/vlinteger.h"
#include <stdio.h>
#include <assert.h>

int main(void) {

    struct linteger *int1 = vlintegerCreate();
    printf("Enter the digits separated by a space: \n");
    vlintegerRead(int1);
    vlintegerPrint(int1);
    assert(int1->arr[0] !=0);
    char c;
    scanf("%c", &c);
    struct linteger *int2 = vlintegerCreate();
    printf("Enter the digits separated by a space: \n");
    vlintegerRead(int2);
    vlintegerPrint(int2);
    assert(int2->arr[0] !=0);
    scanf("%c", &c);
    struct linteger *add = vlintegerAdd(int1, int2);
    printf("addition\n");
    vlintegerPrint(add);
    assert(add->arr[0] !=0);
    scanf("%c", &c);
    struct linteger *mult = vlintegerMult(int1, int2);
    printf("multiplication\n");
    vlintegerPrint(mult);
    assert(mult->arr[0] !=0);
    vlintegerDestroy(int1);
    vlintegerDestroy(int2);
    vlintegerDestroy(add);
    vlintegerDestroy(mult);

}