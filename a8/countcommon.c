#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int count_common(int a[], int n1, int b[], int n2){

    if (!n1 || !n2) return 0;
    int total = 0;
    int aIndex = 0;
    int bIndex = 0;

    //loop through both arrays
    while (aIndex < n1 && bIndex < n2) {

        //skipping duplicates
        while (aIndex+1 < n1 && a[aIndex] == a[aIndex+1]) {
            aIndex++;
        }
        while (bIndex+1 < n2 && b[bIndex] == b[bIndex+1]) {
            bIndex++;
        }

        //index management
        if (a[aIndex] < b[bIndex]) {
            aIndex++;

        } else if (a[aIndex] > b[bIndex]) {
            bIndex++;

        //if the values are equal
        } else {
            total++;
            bIndex++;
            aIndex++;
        }
    }

    return total;
}

/*int main(void){
    int a1[4] = {1,1,1,1};
    int b1[8] = {1,1,1,1,1,1,1,1};
    assert(1 == count_common(a1,4,b1,8));
    int a2[8] = {1,3,3,4,5,8,9,100};
    int b2[7] = {4,4,8,15,20,40,100};
    assert(3 == count_common(a2,8,b2,7));
    return 0;
}*/