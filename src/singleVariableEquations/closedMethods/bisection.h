#pragma once

/**
 * Function that analizes an interval from a single-variable mathematical
 * function and returns one of it's roots or an approximation of it by
 * finding the middle value of the interval, with which it analyzes the two
 * sub-intervals and determines which of the two contains the root.
 * It does this continuously until the root is found or the maximum number
 * of iterations are exeeded.
 * 
 * arguments:
 *     func: Function pointer to the single-variable function.
 *     xi: Inferior value of the interval. Any number inside the domain of the function.
 *     xu: Upper value of the interval. Any number inside the domain of the function.
 *     nIter: Max number of iterations.
 *     tol: Desired tolerance.
 *     errorType: string containign the error type.
 * 
 * Returns:
 *     One of the roots inside the interval, or an approximation of it.
 * 
 * Throws:
 *     IterException: When the max number of iterations are exceeded.
 *     IntervalException: When the interval does not contain a root.
 */
double bisection(double (*func)(double), double xi, double xu, int nIter, double tol, const char *errorType);