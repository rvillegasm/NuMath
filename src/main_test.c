#include <math.h>
#include <stdio.h>

#include "singleVariableEquations/incrementalSearch.h"
#include "singleVariableEquations/bisection.h"
#include "singleVariableEquations/falsePosition.h"
#include "../lib/statusConstants.h"

double f(double x);

int main() {

    Interval interval = incrementalSearch(f, 2.5, 0.0001, 25000);
    if(interval.wasSuccessful){
        if (interval.isRoot) {
            printf("The root is %f\n", interval.first);    
        }
        else {
            printf("The root is inside %f and %f\n", interval.first, interval.last);
            int status;
            double root = falsePosition(f, interval.first, interval.last, 25000, 10e-10, &status);
            if (status == FAILURE) {
                fprintf(stderr, "No root found.\n");
            }
            else {
                printf("The root is: %e\n", root);
            }
        }
    }
    else{
        printf("Nothing could be found\n");
    }
}

double f(double x) {
    //return exp(2*x)+5*x;
     return x-3;
}