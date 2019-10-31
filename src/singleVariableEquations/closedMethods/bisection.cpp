#include <stdio.h>

#include <math.h>
#include <cstring>
#include "bisection.h"
#include "../printTable.h"

#include "../../../lib/statusConstants.h"
#include "../../../lib/exceptions.h"
#include "../../../lib/methodNamesConstants.h"

namespace numath {
    namespace singleVariableEquations {

        double bisection(double (*func)(double), double xi, double xu, int nIter, double tol, const char *errorType) {

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
                xm = (xi + xu)/2;
                fxm = func(xm);
                count = 1;
                error = tol + 1;
                
                printf("Method: Bisection\n");
                printf("%20s | %20s | %20s | %20s | %20s | %20s |\n", "iter", "Xi", "Xu", "Xm", "f(Xm)", "Error");
                double printData[5] = {xi, xu, xm, fxm, error};
                printTable(BISECTION, count, printData);

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
                    xm = (xi + xu)/2;
                    fxm = func(xm);
                    error = ((strcmp(errorType, "abs") == 0) ? fabs(xm - lastXm) : fabs((xm - lastXm) / xm));
                    count++;
                    double printData[5] = {xi, xu, xm, fxm, error};
                    printTable(BISECTION, count, printData);
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