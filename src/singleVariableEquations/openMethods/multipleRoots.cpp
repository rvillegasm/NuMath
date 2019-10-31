#include <stdio.h>
#include "../../../lib/methodNamesConstants.h"
#include "../printTable.h"

#include <cmath>
#include <cstring>
#include "multipleRoots.h"

#include "../../../lib/exceptions.h"

namespace numath {
    namespace singleVariableEquations {

        double multipleRoots(double (*func)(double), double (*dFunc)(double), double (*d2Func)(double), double x0, int nIter, double tol, const char *errorType) {
            
            int count;
            double fx, dfx, d2fx;
            double x1, x1_denominator;
            double error;

            fx = func(x0);
            dfx = dFunc(x0);
            d2fx = d2Func(x0);
            x1_denominator = pow(dfx, 2) - fx * d2fx;
            error = tol + 1;
            count = 0;

            printf("Method: Multiple Roots\n");
            printf("%20s | %20s | %20s | %20s | %20s | %20s |\n", "iter", "Xn", "f(Xn)", "f'(Xn)", "f''(Xn)", "Error");
            double printData[5] = {x0, fx, dfx, d2fx, error};
            printTable(MULT_ROOTS, count, printData);

            while (error > tol && fx != 0 && x1_denominator != 0 && count < nIter) {
                x1 = x0 - ((fx * dfx) / x1_denominator);
                fx = func(x1);
                dfx = dFunc(x1);
                d2fx = d2Func(x1);
                error = ((strcmp(errorType, "abs") == 0) ? fabs(x1 - x0) : fabs((x1 - x0) / x1));
                x1_denominator = pow(dfx, 2) - fx * d2fx;
                count++;
                x0 = x1;

                double printData[5] = {x0, fx, dfx, d2fx, error};
                printTable(MULT_ROOTS, count, printData);
            }

            if (fx == 0) {
                // x0 is a root
                return x0;
            }
            else if (error < tol) {
                // x0 (and x1 has the same value) is an approx of the root
                return x1;
            }
            else if (x1_denominator == 0) {
                throw DenominatorException();
            }
            else {
                throw IterException();
            }

        }

    }
}