#include <stdio.h>
#include <math.h>

void grades(){

    //initializing variables
    int n;
    int num = 0;
    int numMax = 0;
    int numMin = 0;
    int numFailed = 0;
    int max = 0;
    int min = 100;
    double mean, sDev;
    int vals[101] = {};

    //user inputs numbers
    while (scanf("%d", &n)) {
        if (n>max){
            max = n;
            numMax = 1;
        } else if (n==max) numMax++;

        if (n<min){
            min = n;
            numMin = 1;
        } else if (n == min) numMin++;

        numFailed = (n<50)? numFailed+1:numFailed;
        num++;
        vals[n]++;
    }

    //mean calculation
    int sum = 0;
    for (int i = 0; i < 101; i++) {
        sum += vals[i]*i;
    }
    mean = 1.0*sum/num;

    //standard deviation calculation
    double sumOfDiffsSquared = 0;
    for (int i = 0; i < 101; i++) {
        if (vals[i] == 0) continue;
        for (int j = 0; j < vals[i]; j++) {
            sumOfDiffsSquared += pow((i-mean),2);
        }
    }

    sDev = sqrt((sumOfDiffsSquared/(num-1)));

    printf("The maximal grade is: %d\n", max);
    printf("The number of students who received the maximal grade is: %d\n", numMax);
    printf("The minimal grade is: %d\n", min);
    printf("The number of students who received the minimal grade is: %d\n", numMin);
    printf("The course mean is: %0.3f\n", mean);
    printf("The standard deviation is: %0.3f\n", sDev);
    printf("The number of students who failed the course is: %d\n", numFailed);
}
