#include "solveIterative.h"
#include "../../../lib/exceptions.h"

std::vector<double> solveIterative(std::vector<std::vector<double>> &A, 
                                   std::vector<double> &b,
                                   std::vector<double> &initialValues, 
                                   double tol, 
                                   int nIter,
                                   std::vector<double> (*method)(std::vector<double>&,
                                                                 std::vector<std::vector<double>>&,
                                                                 std::vector<double>&),
                                   double (*errorFunc)(std::vector<double>&,
                                                       std::vector<double>&)) {

    int count;
    double dispersion;
    std::vector<double> x0 (initialValues), x1;

    count = 0;
    dispersion = tol + 1;

    while (dispersion > tol && count < nIter) {
        x1 = method(x0, A, b);
        dispersion = errorFunc(x1, x0);
        x0 = x1;
        count++;
    }

    if (dispersion < tol) {
        return x1;
    }
    else {
        throw IterException();
    }

}