#include <stdio.h>
#include "singleVariableEquations/incrementalSearch.h"
#include <math.h>

double f(double x);

int main() {

    double start, finish;

    if(incrementalSearch(f, -1, 0.001, 25000, &start, &finish) == -1) {
        printf("Nothing could be found\n");
    }
    else if (start){
        if (finish) {
            printf("The root is %f\n", start);    
        }
        else {
            printf("The root is inside %f and %f\n", start, finish);
        }
    }
}

double f(double x) {
    //return exp(2*x)+5*x;
     return x-3;
}