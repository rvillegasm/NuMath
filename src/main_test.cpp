#include <math.h>
#include <stdio.h>
#include <iostream>
#include <ctype.h>
#include <iomanip>

#include "singleVariableEquations/incrementalSearch.h"
#include "singleVariableEquations/closedMethods/bisection.h"
#include "singleVariableEquations/closedMethods/falsePosition.h"
#include "singleVariableEquations/openMethods/fixedPoint.h"
#include "singleVariableEquations/openMethods/newton.h"
#include "singleVariableEquations/openMethods/secant.h"
#include "singleVariableEquations/openMethods/multipleRoots.h"

#include "systemsOfEquations/gaussianElimination/gaussianElimination.h"
#include "systemsOfEquations/gaussianElimination/gaussianEliminationTotalPivot.h"
#include "systemsOfEquations/directFactoring/choleskyMethod.h"
#include "systemsOfEquations/directFactoring/croutMethod.h"
#include "systemsOfEquations/directFactoring/doolittleMethod.h"

#include "systemsOfEquations/iterativeMethods/solveIterative.h"
#include "systemsOfEquations/iterativeMethods/jacobi.h"
#include "systemsOfEquations/iterativeMethods/gaussSeidel.h"

#include "../lib/statusConstants.h"
#include "../lib/exceptions.h"
#include "../lib/errorFunctions.h"

#include "../external/tinyExpression/tinyexpr.h"

#define TOLERANCE 1e-12

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

//  GLOBAL VARIABLE. BE VERY CAREFULL WITH THIS.
std::string inputFunction;
std::string helperFunction1;
std::string helperFunction2;

int main() {

    std::vector<std::vector<double>> matrix = {{34, -5, 6, 12}, {-9, 43, 21, -8}, {-12, 4, 75, 22}, {7, 5, -13, 65}};
    std::vector<double> b = {37,123,16,9};
    std::vector<double> results;
    std::vector<double> init = {1,2,3,4};
    std::vector<std::vector<double>> matrixSGE = {{34, -5, 6, 12,37}, {-9, 43, 21, -8,123}, {-12, 4, 75, 22,16}, {7, 5, -13, 65,9}};
    std::vector<std::vector<double>> matrixGEPP = {{-7, 2, -3, 4, -12}, {5, -1, 14, -1, 13}, {1, 9, -7, 5, 31}, {-12, 13, -8, -4,-32}};
    std::vector<std::vector<double>> matrixGETP = {{-7, 2, -3, 4, -12}, {5, -1, 14, -1, 13}, {1, 9, -7, 13, 31}, {-12, 13, -8, -4,-32}};
    
    std::vector<std::vector<double>> Acrout = {{36, 3, -4, 5}, {5, -45, 10, -2}, {6, 8, 57, 5}, {2, 3, -8, -42}};
    std::vector<double> Bcrout = {-20,69,96,-32};

    std::vector<std::vector<double>> Achol = {{20, -1, 3, 4}, {6 ,23, 4, 3}, {7, 21, 46, 9}, {-3, -9, 12, 38}};
    std::vector<double> Bchol = {30,-10,20,-14};
    // try {
    //     results =croMethod(matrix,b);
    // }
    // catch (IterException &e) {
    //     std::cout << e.what() << std::endl;
    //     exit(EXIT_FAILURE);
    // }
    // int i =1;
    // //Does not apply to Total Pivot given marks vector
    // for (double r : results) {
    //     std::cout << "X" << i << " :" << std::setprecision(10) << r << std::endl;
    //     i++;
    // }

    try {
        results = solveIterative(matrix, b, init, 10e-5, 2000, jacobi, absNorm);
    }
    catch (IterException &e) {
        std::cout << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }

    // std::vector<std::vector<double>> matrix = {{20, -1, 3, 4}, {6, 23, 4, 3}, {7, 21, 46, 9}, {-3, -9, 12, 38}};
    // std::vector<double> b = {30,-10,20,-14};
    // std::vector<double> results;

    // try {
    //     results = choleskyMethod(matrix,b);
    // }
    // catch (DenominatorException &e) {
    //     std::cout << e.what() << std::endl;
    //     exit(EXIT_FAILURE);
    // }
    // for (double r : results) {
    //     std::cout << r << std::endl;
    // }

    // printf("Welcome to NuMath.\nPlease enter the function you want to use:\n");
    // std::cin >> inputFunction;

    // int num_method;
    // printf("Please select the method that you want to use:\n");
    // printf("0) Incremental Search\n1) Bisection.\n2) False Position.\n3) Fixed Point\n4) Newton\n5) Secant\n6) Multiple Roots\n=> ");
    // scanf("%i", &num_method);

    // /*Para Incremental search*/
    // double x_start;
    // double delta;
    // Interval interval;
    // /*Para Biseccion y regla falsa*/
    // double xi = 0;
    // double xu = 0;
    // /*Para Punto fijo*/
    // double xa = 3.3;
    // /*Para Newton y raices multiples (x1 para secant)*/
    // double x0 = 2;
    // double x1 = 4;

    // int nIter = 200;
    // double tol;
    // std::string errorType;
    // printf("Enter the desired type of error: (abs|rel|no) ");
    // std::cin >> errorType;
    // while ((errorType.compare("abs") != 0) && (errorType.compare("rel") != 0) && (errorType.compare("no") != 0)) {
    //     printf("Enter a valid type of error: (abs|rel|no) ");
    //     std::cin >> errorType;
    // }
    // const char *error = errorType.c_str();
    // double root;

    // switch (num_method) {
        
    //     case 0:
    //         printf("Enter the starting point of the algorithm: ");
    //         scanf("%lf", &x_start);
    //         printf("Enter the value of delta: ");
    //         scanf("%lf", &delta);
    //         printf("Enter the desired number of iterations: ");
    //         scanf("%i", &nIter);
    //         while (nIter < 0) {
    //             printf("Enter a valid number of iterations: ");
    //             scanf("%i", &nIter);
    //         }
    //         interval = run_incrSearch(f, x_start, delta, nIter);
    //         if(interval.wasSuccessful){
    //             if (interval.isRoot) {
    //                 printf("The root is %f\n", interval.first);    
    //             }
    //             else {
    //                 printf("The root is inside %f and %f\n", interval.first, interval.last);
    //             }
    //         }
    //         else {
    //             printf("Nothing Could be found\n");
    //             exit(EXIT_FAILURE);
    //         }
    //         break;
    //     case 1: 
    //         printf("Enter the inferior limit of the interval: ");
    //         scanf("%lf", &xi);
    //         printf("Enter the upper limit of the interval: ");
    //         scanf("%lf", &xu);
    //         printf("Enter the desired number of iterations: ");
    //         scanf("%i", &nIter);
    //         while (nIter < 0) {
    //             printf("Enter a valid number of iterations: ");
    //             scanf("%i", &nIter);
    //         }
    //         printf("Enter the desired tolerance: ");
    //         scanf("%le", &tol);
    //         while (tol > 1 || tol < 0) {
    //             printf("Enter a valid tolerance (0 < |tol| < 1): ");
    //             scanf("%le", &tol);
    //         }
    //         root = run_bisection(f, xi, xu, nIter, tol, error);
    //         printf("The root is: %e\n", root);
    //         break;
    //     case 2:
    //         printf("Enter the inferior limit of the interval: ");
    //         scanf("%lf", &xi);
    //         printf("Enter the upper limit of the interval: ");
    //         scanf("%lf", &xu);
    //         printf("Enter the desired number of iterations: ");
    //         scanf("%i", &nIter);
    //         while (nIter < 0) {
    //             printf("Enter a valid number of iterations: ");
    //             scanf("%i", &nIter);
    //         }
    //         printf("Enter the desired tolerance: ");
    //         scanf("%le", &tol);
    //         while (tol > 1 || tol < 0) {
    //             printf("Enter a valid tolerance (0 < |tol| < 1): ");
    //             scanf("%le", &tol);
    //         }
    //         root = run_falsePosition(f, xi, xu, nIter, tol, error);
    //         printf("The root is: %e\n", root);
    //         break;
    //     case 3:
    //         printf("Enter the g function: ");
    //         std::cin >> helperFunction1;
    //         printf("Enter the starting point of the algorithm: ");
    //         scanf("%lf", &xa);
    //         printf("Enter the desired number of iterations: ");
    //         scanf("%i", &nIter);
    //         while (nIter < 0) {
    //             printf("Enter a valid number of iterations: ");
    //             scanf("%i", &nIter);
    //         }
    //         printf("Enter the desired tolerance: ");
    //         scanf("%le", &tol);
    //         while (tol > 1 || tol < 0) {
    //             printf("Enter a valid tolerance (0 < |tol| < 1): ");
    //             scanf("%le", &tol);
    //         }
    //         root = run_fixedPoint(f, g, xa, nIter, tol, error);
    //         printf("The root is: %e\n", root);
    //         break;
    //     case 4:
    //         printf("Enter the derivative of the function: ");
    //         std::cin >> helperFunction1;
    //         printf("Enter the starting point of the algorithm: ");
    //         scanf("%lf", &x0);
    //         printf("Enter the desired number of iterations: ");
    //         scanf("%i", &nIter);
    //         while (nIter < 0) {
    //             printf("Enter a valid number of iterations: ");
    //             scanf("%i", &nIter);
    //         }
    //         printf("Enter the desired tolerance: ");
    //         scanf("%le", &tol);
    //         while (tol > 1 || tol < 0) {
    //             printf("Enter a valid tolerance (0 < |tol| < 1): ");
    //             scanf("%le", &tol);
    //         }
    //         /*g es la derivada de f en este caso*/
    //         root = run_newton(f, g, x0, nIter, tol, error);
    //         printf("The root is: %e\n", root);
    //         break;
    //     case 5:
    //         printf("Enter the first starting point of the algorithm: ");
    //         scanf("%lf", &x0);
    //         printf("Enter the second starting point of the algorithm: ");
    //         scanf("%lf", &x1);
    //         printf("Enter the desired number of iterations: ");
    //         scanf("%i", &nIter);
    //         while (nIter < 0) {
    //             printf("Enter a valid number of iterations: ");
    //             scanf("%i", &nIter);
    //         }
    //         printf("Enter the desired tolerance: ");
    //         scanf("%le", &tol);
    //         while (tol > 1 || tol < 0) {
    //             printf("Enter a valid tolerance (0 < |tol| < 1): ");
    //             scanf("%le", &tol);
    //         }
    //         root = run_secant(f, x0, x1, nIter, tol, error);
    //         printf("The root is: %e\n", root);
    //         break;
    //     case 6:
    //         printf("Enter the derivative of the function: ");
    //         std::cin >> helperFunction1;
    //         printf("Enter the second derivative of the function: ");
    //         std::cin >> helperFunction2;
    //         printf("Enter the starting point of the algorithm: ");
    //         scanf("%lf", &x0);
    //         printf("Enter the desired number of iterations: ");
    //         scanf("%i", &nIter);
    //         while (nIter < 0) {
    //             printf("Enter a valid number of iterations: ");
    //             scanf("%i", &nIter);
    //         }
    //         printf("Enter the desired tolerance: ");
    //         scanf("%le", &tol);
    //         while (tol > 1 || tol < 0) {
    //             printf("Enter a valid tolerance (0 < |tol| < 1): ");
    //             scanf("%le", &tol);
    //         }
    //         /*g es la derivada de f en este caso y g2 es la segunda deriv*/
    //         root = run_multRoots(f, g, g2, x0, nIter, tol, error);
    //         printf("The root is: %e\n", root);
    //         break;
    // }

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

    const char *strFunction = inputFunction.c_str();
    te_variable vars[] = {{"x", &x}};

    int err;
    double result;
    te_expr *expr = te_compile(strFunction, vars, 1, &err);

    if (expr) {
        result = te_eval(expr);

        te_free(expr);
    }
    else {
        printf("Parse Error at %d\n", err);
        exit(EXIT_FAILURE);
    }

    return result;
}

double g(double x){

    const char *strFunction = helperFunction1.c_str();
    te_variable vars[] = {{"x", &x}};

    int err;
    double result;
    te_expr *expr = te_compile(strFunction, vars, 1, &err);

    if (expr) {
        result = te_eval(expr);

        te_free(expr);
    }
    else {
        printf("Parse Error at %d\n", err);
        exit(EXIT_FAILURE);
    }

    return result;
}

double g2(double x){

    const char *strFunction = helperFunction2.c_str();
    te_variable vars[] = {{"x", &x}};

    int err;
    double result;
    te_expr *expr = te_compile(strFunction, vars, 1, &err);

    if (expr) {
        result = te_eval(expr);

        te_free(expr);
    }
    else {
        printf("Parse Error at %d\n", err);
        exit(EXIT_FAILURE);
    }

    return result;
}