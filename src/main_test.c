#include <math.h>
#include <stdio.h>

#include "singleVariableEquations/incrementalSearch.h"

double f(double x);

int main() {

    Interval interval = incrementalSearch(f, 1, 0.0001, 25000);
    if(interval.wasSuccessful){
        if (interval.isRoot) {
            printf("The root is %f\n", interval.first);    
        }
        else {
            printf("The root is inside %f and %f\n", interval.first, interval.last);
        }
    }
    else{
        printf("Nothing could be found\n");
    }
}

double f(double x) {
    // return exp(2*x)+5*x;
    return x-3;
}