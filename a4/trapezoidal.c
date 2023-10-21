#include <stdio.h>
#include <math.h>
#include <assert.h>
#define PI acos(-1)

double trapezoidal(double (*f)(double), double a, double b, double epsilon, int n){

    double sumArea1 = 0.0;
    double sumArea2 = 0.0;

    //calculating the first area
    for (int i = 0; i < n; i++) {
        double x1 = a + (i * ((b-a)/n));
        double x2 = x1 + ((b-a)/n);
        sumArea2 += (x2-x1)*((f(x1)+f(x2))/2);
    }

    //recalculating until the difference of the areas is <= to epsilon
    do{
        sumArea1 = sumArea2;
        sumArea2 = 0.0;
        n*=2;
        for (int i = 0; i < n; i++) {
            double x1 = a + (i * ((b-a)/n));
            double x2 = x1 + ((b-a)/n);
            sumArea2 += (x2-x1)*((f(x1)+f(x2))/2);
        }
    }while((fabs(sumArea2-sumArea1)) > epsilon);
    return sumArea2;
}
