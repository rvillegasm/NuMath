#pragma once

double newton(double (*func)(double), double (*dFunc)(double), double x0, int nIter, double tol);