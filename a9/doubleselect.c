#include <stdio.h>

void printarr(int a[], int len){
    for (int i=0; i<len-1; i++)
        printf("%d ", a[i]);
    printf("%d\n", a[len-1]);
}

void doubleselectionsort(int a[], int len){

    if (len == 0 || len == 1) return;

    //loop through half of the array
    for (int i = 0; i < len/2; i++) {

        int smallest = i;
        int largest = len-i-1;

        //loop through the unsorted array
        for (int j = i; j < len-i; j++) {

            //update the indexes if applicable
            if (a[j] > a[largest]) largest = j;
            else if (a[j] < a[smallest]) smallest = j;
        }

        //do the swap
        int temp = a[i];
        a[i] = a[smallest];
        a[smallest] = temp;
        if (largest == i) largest = smallest;
        temp = a[len-i-1];
        a[len-i-1] = a[largest];
        a[largest] = temp;

        //print the array
        printarr(a, len);
    }
}

/*int main(void) {

    int a[7] = {4, 4, 4, 0, 0, -10, -10};
    doubleselectionsort(a,7);
    printf("\n");
    int a2[5] = {6, 11, 2, -4, -1};
    doubleselectionsort(a2,5);
    printf("\n");
    int a3[10] = {1, 8, 5, 4, 6, 2, 5, 6, 2, 9};
    doubleselectionsort(a3,10);
    printf("\n");
    int a4[2] = {0,1};
    doubleselectionsort(a4, 2);
    printf("\n");

    return 0;
}*/
