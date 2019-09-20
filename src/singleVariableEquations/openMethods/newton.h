#pragma once

/**
 * Function that analizes a single-variable mathematical function and
 * returns one of it's roots, or an approximation of it.
 * 
 * arguments:
 *     func: Function pointer to the single-variable function.
 *     dFunc: Function pointer to the helper function.
 *     x0: Initial value of the method. Any number inside the domain of the function.
 *     nIter: Max number of iterations.
 *     tol: Desired tolerance.
 * 
 * Returns:
 *     One of the roots inside the interval, or an approximation of it.
 */
double newton(double (*func)(double), double (*dFunc)(double), double x0, int nIter, double tol, const char *errorType);