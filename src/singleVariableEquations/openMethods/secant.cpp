#include <stdio.h>
#include "../../../lib/methodNamesConstants.h"
#include "../printTable.h"

#include <cmath>
#include <cstring>
#include "secant.h"

#include "../../../lib/exceptions.h"

double secant(double (*func)(double), double x0, double x1, int nIter, double tol, const char *errorType) {
    
    int count;
    double fx0, fx1;
    double error;
    double x2, x2_denominator;

    fx0 = func(x0);
    if (fx0 == 0) {
        return x0;
    }
    else {
        fx1 = func(x1);
        count = 0;
        error = tol + 1;
        x2_denominator = fx1 - fx0;

        printf("Method: Secant\n");
        printf("%20s | %20s | %20s | %20s |\n", "iter", "Xn", "f(Xn)", "Error");
        double printData_1[3] = {x0, fx0, error};
        printTable(SECANT, count, printData_1);
        double printData_2[3] = {x1, fx1, error};
        printTable(SECANT, count, printData_2);

        while (error > tol && fx1 != 0 && x2_denominator != 0 && count < nIter) {
            x2 = x1 - (fx1 * (x1 - x0) / x2_denominator);
            error = ((strcmp(errorType, "abs") == 0) ? fabs(x2 - x1) : fabs((x2 - x1) / x2));
            x0 = x1;
            fx0 = fx1;
            x1 = x2;
            fx1 = func(x1);
            x2_denominator = fx1 - fx0;
            count++;

            double printData[3] = {x1, fx1, error};
            printTable(SECANT, count, printData);
        }

        if (fx1 == 0) {
            // x1 is a root
            return x1;
        }
        else if (error < tol) {
            // x1 is an approx of a root
            return x1;
        }
        else if (x2_denominator == 0) {
            // possible multiple roots found
            throw DenominatorException();
        } 
        else {
            throw IterException();
        }
    }
}
