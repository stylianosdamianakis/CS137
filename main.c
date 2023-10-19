#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
extern void score_update();

int read_ints(){
    int min,min_i,max,max_i,x,index;
    if(scanf("%d", &x)){
        min = x;
        max = x;
        index = 1;
        max_i = 1;
        min_i = 1;
    } else {
        printf("No integer given.");
        return 0;
    }

    while(scanf("%d", &x)){
        index++;
        if(x>=max){
            max = x;
            max_i = index;
        }
        if(x<=min){
            min = x;
            min_i = index;
        }
    }
    printf("(%d, %d)(%d, %d)", min, min_i, max, max_i);
    return 0;
}


int main(void) {
    read_ints();
}