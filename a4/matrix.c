#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

void arrprint(int a[], int n){
    for (int i = 0; i<n-1 ;i++){
        printf("%d ",a[i]);
    }
    printf("%d\n", a[n-1]);
}


void matrixprint(int n, int m[][n]){
    for (int i = 0; i<n ;i++){
        for (int j=0; j<n-1; j++){
            printf("%d ",m[i][j]);
        }
        printf("%d\n", m[i][n-1]);
    }
}


//convert 2D array nxn into 1D array of size nxn
void convert(int n, int mat[n][n], int a[]){
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[k] = mat[i][j];
            k++;
        }
    }
}

//returns true if mat is a magic square matrix.
// mat is a magic square if the sums of the numbers in each row,
// each column, and both main diagonals are the same
// the function also prints the magic constant (the magic sum of each row, column, and diagonal).
// use "The magic constant is: %d\n"  for printing the magic constant
bool ismagicsquare(int n, int mat[n][n]){

    //finding the magic constant
    int magicConst = 0;
    for (int i = 0; i < n; i++) {
        magicConst += mat[i][0];
    }

    //checking the sum of each row
    int sumRow = 0;
    int sumCol = 0;
    int sumD1 = 0;
    int sumD2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //checking the sum of each row
            sumRow += mat[i][j];

            //checking the sum of each column
            sumCol += mat[j][i];

            //checking the sum of diagonal one
            if (i == j) sumD1 += mat[i][j];

            //checking the sum of diagonal two
            if (i + j == n-1) sumD2 += mat[i][j];
        }

        if (sumRow != magicConst || sumCol != magicConst) return 0;
        sumRow = 0;
        sumCol = 0;
    }

    if (sumD1 != magicConst || sumD2 != magicConst) return 0;

    printf("The magic constant is: %d\n", magicConst);
    return 1;
}
