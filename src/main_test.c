#include <stdio.h>
#include "singleVariableEquations/incrementalSearch.h"
#include <math.h>

double f(double x);

int main() {

    double start, finish;

    if(incrementalSearch(f, -1, 0.001, 25000, &start, &finish) == -1) {
        printf("Nothing could be found\n");
    }
    else if (start == NULL){
        if (interval.isRoot) {
            printf("The root is %f\n", interval.first);    
        }
        else {
            printf("The root is inside %f and %f\n", interval.first, interval.last);
        }
    }
}

double f(double x) {
    return exp(2*x)+5*x;
    // return x-3;
}