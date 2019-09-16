#pragma once

/**
 * Function that analizes an interval from a single-variable mathematical function and
 * returns one of it's roots, or an approximation of it.
 * 
 * arguments:
 *     func: Function pointer to the single-variable function.
 *     xi: Inferior value of the interval. Any number inside the domain of the function.
 *     xu: Upper value of the interval. Any number inside the domain of the function.
 *     nIter: Max number of iterations.
 *     tol: Desired tolerance.
 *     status: Pointer to an integer that specifies the exit status of the numerical method.
 *             It's possible values are: EXACT_VALUE (0), APPROX_VALUE (1), FAILURE (-1).
 * 
 * Returns:
 *     One of the roots inside the interval, or an approximation of it.
 */
double bisection(double (*func)(double), double xi, double xu, int nIter, double tol, int *status);