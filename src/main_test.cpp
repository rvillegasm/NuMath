#include <math.h>
#include <stdio.h>

#include "singleVariableEquations/incrementalSearch.h"
#include "singleVariableEquations/closedMethods/bisection.h"
#include "singleVariableEquations/closedMethods/falsePosition.h"
#include "singleVariableEquations/openMethods/fixedPoint.h"
#include "singleVariableEquations/openMethods/newton.h"
#include "singleVariableEquations/openMethods/secant.h"
#include "singleVariableEquations/openMethods/multipleRoots.h"

#include "../lib/statusConstants.h"
#include "../lib/exceptions.h"

#define TOLERANCE 10e-10

double f(double x);
double g(double x);
double g2(double x);

int main() {

    double root = 0;
    try
    {
        root = multipleRoots(f, g, g2, -1, 20, TOLERANCE, "rel");
    }
    catch(IterException &e)
    {
        printf("%s\n", e.what());
    }
    catch(DenominatorException &e)
    {
        printf("%s\n", e.what());
    }

    printf("%e\n", root);
    

    // Interval interval;
    
    // interval = incrementalSearch(f, -1, 0.0001, 25000);

    // if(interval.wasSuccessful){
    //     if (interval.isRoot) {
    //         printf("The root is %f\n", interval.first);    
    //     }
    //     else {
    //         printf("The root is inside %f and %f\n", interval.first, interval.last);
            
    //         int status;
    //         double root;
            
    //         try {
    //             root = bisection(f, interval.first, interval.last, 25, TOLERANCE, &status);
    //         }
    //         catch (IterException &iterEx) {
    //             printf("%s\n", iterEx.what());
    //             return EXIT_FAILURE;
    //         }
    //         catch (IntervalException &intervEx) {
    //             printf("%s\n", intervEx.what());
    //             return EXIT_FAILURE;
    //         }

    //         if (status == EXACT_VALUE) {
    //             printf("The exact root is: %e\n", root);
    //         }
    //         else if (status == APPROX_VALUE) {
    //             printf("The root is: %e, with a tolerance of %.1e\n", root, TOLERANCE);
    //         }
    //     }
    // }
    // else{
    //     printf("Nothing could be found\n");
    // }
}

double f(double x) {
    // return exp(2*x)+5*x;
    // return x-3;
    return pow(x, 2);
    // return exp(-pow(x,2)+1)-x*sin(2*x+3)-4*x+4;
}

double g(double x){
    return 2*x;
    // return -2*x*exp(-pow(x,2)+1)-sin(2*x+3)-2*x*cos(2*x+3)-4;
}

double g2(double x){
    return 2;
    // return -2*x*exp(-pow(x,2)+1)-sin(2*x+3)-2*x*cos(2*x+3)-4;
}