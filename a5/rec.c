#include <stdio.h>
#include <assert.h>
#include <math.h>

typedef struct Point{
    int x;
    int y;
} point;

typedef struct Rectangle {
    point bottomLeft;
    int width;
    int height;
} rectangle;


rectangle intersection(rectangle rects[], int n){

    rectangle intersection = rects[0];

    for (int i = 1; i < n; i++) {

        //rectangles' top right corner
        point intTopRight = {intersection.bottomLeft.x + intersection.width, intersection.bottomLeft.y + intersection.height};
        point currTopRight = {rects[i].bottomLeft.x + rects[i].width, rects[i].bottomLeft.y + rects[i].height};

        //check if the rectangles actually intersect
        if (currTopRight.x <= intersection.bottomLeft.x || currTopRight.y <= intersection.bottomLeft.y ||
        rects[i].bottomLeft.x >= intTopRight.x || rects[i].bottomLeft.y >= intTopRight.y){

            //return a blank rectangle if they do not intersect
            rectangle blank = {{0,0},0,0};
            return blank;
        }

        //get the coordinates of the new bottom left corner
        point newBotLeft = {abs(intersection.bottomLeft.x - rects[i].bottomLeft.x) +
                            ((intersection.bottomLeft.x < rects[i].bottomLeft.x)?intersection.bottomLeft.x : rects[i].bottomLeft.x),
                            abs(intersection.bottomLeft.y - rects[i].bottomLeft.y) +
                            ((intersection.bottomLeft.y < rects[i].bottomLeft.y)?intersection.bottomLeft.y : rects[i].bottomLeft.y)};

        //get the coordinates of the new top right corner
        point newTopRight = {((intTopRight.x > currTopRight.x)?intTopRight.x : currTopRight.x) - abs(intTopRight.x - currTopRight.x),
                             ((intTopRight.y > currTopRight.y)?intTopRight.y : currTopRight.y) - abs(intTopRight.y - currTopRight.y)};

        intersection.bottomLeft = newBotLeft;
        intersection.height = newTopRight.y - newBotLeft.y;
        intersection.width = newTopRight.x - newBotLeft.x;
    }

    return intersection;
}
