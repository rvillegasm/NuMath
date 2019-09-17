#include "fixedPoint.h"
#include <cmath>
#include "../../../lib/exceptions.h"

double fixedPoint(double (*func)(double), double (*gFunc)(double), double xa, int nIter, double tol) {
    double fx = func(xa);
    int count = 0;
    double error = tol + 1;
    double xn = 0;
    while(fx != 0 && error > tol && count < nIter){
        xn = gFunc(xa);
        fx = func(xn);
        error = fabs(xn - xa);
        xa = xn;
        count++;
    }
    if(fx == 0){
        return xa;
    }
    else if(error < tol){
        return xa;
    }
    else{
        throw IterException();
    }
}