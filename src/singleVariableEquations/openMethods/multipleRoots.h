#pragma once

double multipleRoots(double (*func)(double), double (*dFunc)(double), double (*d2Func)(double), double x0, int nIter, double tol, const char *errorType);