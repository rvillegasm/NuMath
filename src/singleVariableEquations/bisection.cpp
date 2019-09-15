#include <math.h>
#include "bisection.h"

#include "../../lib/statusConstants.h"
#include "../../lib/exceptions.h"

double bisection(double (*func)(double), double xi, double xu, int nIter, double tol, int *status) {

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
            error = fabs(xm - lastXm);
            count++;
        }
        if (fxm == 0) {
            // exact value found
            *status = EXACT_VALUE;
            return xm;
        }
        else if (error < tol) {
            // approx value found
            *status = APPROX_VALUE;
            return xm;
        }
        else {
            // iterations were not enough to find a root
            *status = FAILURE;
            throw IterException();
        }
    }
    // the specified interval is not valid
    *status = FAILURE;
    throw IntervalException();
}
