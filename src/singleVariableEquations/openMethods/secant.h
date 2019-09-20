#pragma once

double secant(double (*func)(double), double x0, double x1, int nIter, double tol, const char *errorType);