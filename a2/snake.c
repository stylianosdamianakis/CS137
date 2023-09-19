#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int snake(){

    //initialize variables
    int maxCharacters = 0;
    int spaceBeforeSnake = 1;
    int headLocation = 3;

    //read the max character amount
    scanf("%d", &maxCharacters);

    //create each line
    for (int i = 0; i < maxCharacters-3; i++) {

        //create the space before the snake
        for (int j = 0; j < spaceBeforeSnake; j++) {
            printf("%c", '_');
        }

        //create the body of the snake
        for (int k = spaceBeforeSnake; k < headLocation; k++) {
            printf("%c", 'X');
        }

        //create the head of the snake
        printf("%c", 'H');

        //create the empty space and bait
        for (int p = headLocation+1; p < maxCharacters; p++) {
            printf("%c",(p % 2 == 0)?'_':'.');
        }

        printf("\n");
        //increase the head location and the space before the snake if applicable
        headLocation++;
        spaceBeforeSnake = (headLocation % 2 == 1)?spaceBeforeSnake:spaceBeforeSnake+1;
    }

    return 0;
}