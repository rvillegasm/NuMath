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

Interval run_incrSearch(double (*f)(double), double x_start, double delta, int nIter);
double run_bisection(double (*f)(double), double xi, double xu, int nIter, double tol, const char *errorType); 
double run_falsePosition(double (*f)(double), double xi, double xu, int nIter, double tol, const char *errorType);
double run_fixedPoint(double (*f)(double), double (*g)(double), double xa, int nIter, double tol, const char *errorType);
double run_newton(double (*f)(double), double (*g)(double), double x0, int nIter, double tol, const char *errorType);
double run_secant(double (*f)(double), double x0, double x1, int nIter, double tol, const char *errorType);
double run_multRoots(double (*f)(double), double (*g)(double), double (*g2)(double), double x0, int nIter, double tol, const char *errorType);

int main() {

    int num_method;
    printf("Welcome to NuMath.\n Please select the method that you want to use:\n");
    printf("0) Incremental Search\n1) Bisection.\n2) False Position.\n3) Fixed Point\n4) Newton\n5) Secant\n6) Multiple Roots\n=> ");
    scanf("%i", &num_method);

    /*Para Incremental search*/
    double x_start = 0;
    double delta = 0.1;
    Interval interval;
    /*Para Biseccion y regla falsa*/
    double xi = 0;
    double xu = 0;
    /*Para Punto fijo*/
    double xa = 0;
    /*Para Newton y raices multiples (x1 para secant)*/
    double x0 = 2;
    double x1 = 4;

    double nIter = 200;
    const char *error = "rel";
    double root;

    switch (num_method) {
        
        case 0:
            interval = run_incrSearch(f, x_start, delta, nIter);
            if(interval.wasSuccessful){
                if (interval.isRoot) {
                    printf("The root is %f\n", interval.first);    
                }
                else {
                    printf("The root is inside %f and %f\n", interval.first, interval.last);
                }
            }
            else {
                printf("Nothing Could be found\n");
                exit(EXIT_FAILURE);
            }
            break;
        case 1: 
            root = run_bisection(f, xi, xu, nIter, TOLERANCE, error);
            printf("The root is: %e\n", root);
            break;
        case 2:
            root = run_falsePosition(f, xi, xu, nIter, TOLERANCE, error);
            printf("The root is: %e\n", root);
            break;
        case 3:
            root = run_fixedPoint(f, g, xa, nIter, TOLERANCE, error);
            printf("The root is: %e\n", root);
            break;
        case 4:
            /*g es la derivada de f en este caso*/
            root = run_newton(f, g, x0, nIter, TOLERANCE, error);
            printf("The root is: %e\n", root);
            break;
        case 5:
            root = run_secant(f, x0, x1, nIter, TOLERANCE, error);
            printf("The root is: %e\n", root);
            break;
        case 6:
            /*g es la derivada de f en este caso y g2 es la segunda deriv*/
            root = run_multRoots(f, g, g2, x0, nIter, TOLERANCE, error);
            printf("The root is: %e\n", root);
            break;
    
    }

}

Interval run_incrSearch(double (*f)(double), double x_start, double delta, int nIter) {
    Interval interval;
    interval = incrementalSearch(f, x_start, delta, nIter);
    return interval;
}

double run_bisection(double (*f)(double), double xi, double xu, int nIter, double tol, const char *errorType) {

    double root;        
    try {
        root = bisection(f, xi, xu, nIter, tol, errorType);
    }
    catch (IterException &iterEx) {
        printf("%s\n", iterEx.what());
        exit(EXIT_FAILURE);
    }
    catch (IntervalException &intervEx) {
        printf("%s\n", intervEx.what());
        exit(EXIT_FAILURE);
    }

    return root;
}

double run_falsePosition(double (*f)(double), double xi, double xu, int nIter, double tol, const char *errorType) {
    
    double root;        
    try {
        root = falsePosition(f, xi, xu, nIter, tol, errorType);
    }
    catch (IterException &iterEx) {
        printf("%s\n", iterEx.what());
        exit(EXIT_FAILURE);
    }
    catch (IntervalException &intervEx) {
        printf("%s\n", intervEx.what());
        exit(EXIT_FAILURE);
    }

    return root;
}

double run_fixedPoint(double (*f)(double), double (*g)(double), double xa, int nIter, double tol, const char *errorType) {
    
    double root;
    try {
        root = fixedPoint(f, g, xa, nIter, tol, errorType);
    }
    catch(IterException &e)
    {
        printf("%s\n", e.what());
        exit(EXIT_FAILURE);
    }

    return root;
}

double run_newton(double (*f)(double), double (*g)(double), double x0, int nIter, double tol, const char *errorType) {
    
    double root;
    try {
        root = newton(f, g, x0, nIter, tol, errorType);
    }
    catch(IterException &e)
    {
        printf("%s\n", e.what());
        exit(EXIT_FAILURE);
    }
    catch(DerivativeException &e)
    {
        printf("%s\n", e.what());
        exit(EXIT_FAILURE);
    }

    return root;
}

double run_secant(double (*f)(double), double x0, double x1, int nIter, double tol, const char *errorType) {
    
    double root;
    try {
        root = secant(f, x0, x1, nIter, tol, errorType);
    }
    catch(IterException &e)
    {
        printf("%s\n", e.what());
        exit(EXIT_FAILURE);
    }
    catch(DenominatorException &e)
    {
        printf("%s\n", e.what());
        exit(EXIT_FAILURE);
    }

    return root;
}

double run_multRoots(double (*f)(double), double (*g)(double), double (*g2)(double), double x0, int nIter, double tol, const char *errorType) {

    double root;
    try {
        root = multipleRoots(f, g, g2, x0, nIter, tol, errorType);
    }
    catch(IterException &e)
    {
        printf("%s\n", e.what());
        exit(EXIT_FAILURE);
    }
    catch(DenominatorException &e)
    {
        printf("%s\n", e.what());
        exit(EXIT_FAILURE);
    }

    return root;
}


double f(double x) {
    // return exp(2*x)+5*x;
    // return x-3;
    return pow(x, 4)- 18*pow(x, 2) + 80;
    // return exp(-pow(x,2)+1)-x*sin(2*x+3)-4*x+4;
}

double g(double x){
    return 4*pow(x, 3) - 36*x;
    // return -2*x*exp(-pow(x,2)+1)-sin(2*x+3)-2*x*cos(2*x+3)-4;
}

double g2(double x){
    return 12*pow(x, 2) - 36;
    // return -2*x*exp(-pow(x,2)+1)-sin(2*x+3)-2*x*cos(2*x+3)-4;
}