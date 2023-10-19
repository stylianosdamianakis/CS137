#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
extern void score_update();

int max_input(int largest){
    int n = 0;
    if(!scanf("%d", &n)){
        return largest;
    }
    largest = (largest>n)?largest:n;
    max_input(largest);
}


int main(void) {
    printf("%d", max_input(0));
}