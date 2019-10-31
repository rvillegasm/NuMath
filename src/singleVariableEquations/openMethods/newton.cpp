#include <stdio.h>
#include "../../../lib/methodNamesConstants.h"
#include "../printTable.h"

#include <cmath>
#include <cstring>
#include "newton.h"
#include "../../../lib/exceptions.h"

namespace numath {
    namespace singleVariableEquations {

        double newton(double (*func)(double), double (*dFunc)(double), double x0, int nIter, double tol, const char *errorType) {

            double fx = func(x0);
            double dfx = dFunc(x0);
            double x1;
            int count = 0;
            double error = tol + 1;

            printf("Method: Newton\n");
            printf("%20s | %20s | %20s | %20s | %20s |\n", "iter", "Xn", "f(Xn)", "f'(Xn)", "Error");
            double printData[4] = {x0, fx, dfx, error};
            printTable(NEWTON, count, printData);

            while (error > tol && fx != 0 && dfx != 0 && count < nIter) {
                x1 = x0 - fx/dfx;
                fx = func(x1);
                dfx = dFunc(x1);
                error = ((strcmp(errorType, "abs") == 0) ? fabs(x1 - x0) : fabs((x1 - x0) / x1));
                x0 = x1;
                count++;

                double printData[4] = {x1, fx, dfx, error};
                printTable(NEWTON, count, printData);
            }
            
            if (fx == 0) {
                return x0;
            }
            else if (error < tol) {
                return x1;
            }
            else if (dfx == 0) {
                throw DerivativeException();
            }
            else {
                throw IterException();
            }
        }

    }
}