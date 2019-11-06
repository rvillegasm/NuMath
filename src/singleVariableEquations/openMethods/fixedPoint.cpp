
#include "fixedPoint.h"
#include <cmath>
#include <cstring>
#include "../../../lib/exceptions.h"

namespace numath {
    namespace singleVariableEquations {

        double fixedPoint(double (*func)(double), double (*gFunc)(double), double xa, int nIter, double tol, const char *errorType, std::vector<std::vector<double>> &table) {
            
            double fx = func(xa);
            int count = 0;
            double error = tol + 1;
            double xn = 0;

            // Add info to the table
            std::vector<double> iterVector1 = {(double) count, xa, fx, error};
            table.push_back(iterVector1);
            // ---------------------

            while (fx != 0 && error > tol && count < nIter) {
                xn = gFunc(xa);
                fx = func(xn);
                error = ((strcmp(errorType, "abs") == 0) ? fabs(xn - xa) : fabs((xn - xa) / xn));
                xa = xn;
                count++;

                // Add info to the table
                std::vector<double> iterVector2 = {(double) count, xn, fx, error};
                table.push_back(iterVector2);
                // ---------------------
            }

            if (fx == 0) {
                return xa;
            }
            else if (error < tol) {
                return xa;
            }
            else {
                throw IterException();
            }
        }

    }
}