#include <stdio.h>

#include <cmath>
#include <cstring>
#include "newton.h"
#include "../../../lib/exceptions.h"

namespace numath {
    namespace singleVariableEquations {

        double newton(double (*func)(double), double (*dFunc)(double), double x0, int nIter, double tol, const char *errorType, std::vector<std::vector<double>> &table) {

            double fx = func(x0);
            double dfx = dFunc(x0);
            double x1;
            int count = 0;
            double error = tol + 1;

            // Add info to the table
            std::vector<double> iterVector1 = {(double) count, x0, fx, error};
            table.push_back(iterVector1);
            // ---------------------

            while (error > tol && fx != 0 && dfx != 0 && count < nIter) {
                x1 = x0 - fx/dfx;
                fx = func(x1);
                dfx = dFunc(x1);
                error = ((strcmp(errorType, "abs") == 0) ? fabs(x1 - x0) : fabs((x1 - x0) / x1));
                x0 = x1;
                count++;

                // Add info to the table
                std::vector<double> iterVector2 = {(double) count, x1, fx, error};
                table.push_back(iterVector2);
                // ---------------------
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