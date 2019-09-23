#include <stdio.h>
#include "../../../lib/methodNamesConstants.h"
#include "../printTable.h"

#include "fixedPoint.h"
#include <cmath>
#include <cstring>
#include "../../../lib/exceptions.h"

double fixedPoint(double (*func)(double), double (*gFunc)(double), double xa, int nIter, double tol, const char *errorType) {
    
    double fx = func(xa);
    int count = 0;
    double error = tol + 1;
    double xn = 0;

    printf("Method: Fixed Point\n");
    printf("%20s | %20s | %20s | %20s |\n", "iter", "Xn", "f(Xn)", "Error");
    double printData[3] = {xa, fx, error};
    printTable(FIXED_POINT, count, printData);

    while (fx != 0 && error > tol && count < nIter) {
        xn = gFunc(xa);
        fx = func(xn);
        error = ((strcmp(errorType, "abs") == 0) ? fabs(xn - xa) : fabs((xn - xa) / xn));
        xa = xn;
        count++;
        
        double printData[3] = {xn, fx, error};
        printTable(FIXED_POINT, count, printData);
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