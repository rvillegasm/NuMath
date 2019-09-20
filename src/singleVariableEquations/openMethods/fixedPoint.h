#pragma once

/**
 * Function that analizes a single-variable mathematical function and
 * returns one of it's roots, or an approximation of it.
 * 
 * arguments:
 *     func: Function pointer to the single-variable function.
 *     gFunc: Function pointer to the helper function.
 *     xa: Initial value of the method. Any number inside the domain of the function.
 *     nIter: Max number of iterations.
 *     tol: Desired tolerance..
 * 
 * Returns:
 *     One of the roots inside the interval, or an approximation of it.
 */
double fixedPoint(double (*func)(double), double (*gFunc)(double), double xa, int nIter, double tol, const char *errorType);