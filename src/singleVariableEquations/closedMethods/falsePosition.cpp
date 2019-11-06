#include <math.h>
#include <cstring>
#include <vector>

#include "falsePosition.h"

#include "../../../lib/exceptions.h"

namespace numath {
    namespace singleVariableEquations {

        double falsePosition(double (*func)(double), double xi, double xu, int nIter, double tol, const char *errorType, std::vector<std::vector<double>> &table) {

            int count;
            double xm;
            double lastXm;
            double fxm;
            double error;

            double fxi = func(xi);
            double fxu = func(xu);
            
            if (fxi == 0) {
                // xi is a root
                return xi;
            }
            else if (fxu == 0) {
                // xu is a root
                return xu;
            }
            else if (fxi * fxu < 0) {
                xm = xi -((fxi*(xi-xu))/(fxi-fxu));
                fxm = func(xm);
                count = 1;
                error = tol + 1;

                // Add info to the table
                std::vector<double> iterVector1 = {(double) count, xm, fxm, error};
                table.push_back(iterVector1);
                // ---------------------

                while (error > tol && fxm != 0 && count < nIter) {
                    if (fxi * fxm < 0) {
                        xu = xm;
                        fxu = fxm;
                    }
                    else {
                        xi = xm;
                        fxi = fxm;
                    }
                    lastXm = xm;
                    xm = xi -((fxi*(xi-xu))/(fxi-fxu));
                    fxm = func(xm);
                    error = ((strcmp(errorType, "abs") == 0) ? fabs(xm - lastXm) : fabs((xm - lastXm) / xm));
                    count++;

                    // Add info to the table
                    std::vector<double> iterVector2 = {(double) count, xm, fxm, error};
                    table.push_back(iterVector2);
                    // ---------------------
                }
                if (fxm == 0) {
                    // exact value found
                    return xm;
                }
                else if (error < tol) {
                    // approx value found
                    return xm;
                }
                else {
                    // iterations were not enough to find a root
                    throw IterException();
                }
            }
            // the specified interval is not valid
            throw IntervalException();
        }

    }
}