#include <stdio.h>
#include "singleVariableEquations/incrementalSearch.h"
#include <math.h>

double f(double x);

int main() {

    Pair interval = incrementalSearch(f, -1, 0.0001, 25000);
    if(interval.finished){
        printf("The root is inside %f and %f\n", interval.first, interval.last);
    }
    else{
        printf("Nothing could be found\n");
    }
}

double f(double x) {
    return exp(2*x)+5*x;
}