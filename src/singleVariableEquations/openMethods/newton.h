#pragma once

/**
 * Function that analizes a single-variable mathematical function and
 * returns one of it's roots or an approximation of it by calculating
 * the points in which the derivative of the function at a specific
 * point equals 0, and then repeating that process using said value until
 * the root is found.
 * 
 * arguments:
 *     func: Function pointer to the single-variable function.
 *     dFunc: Function pointer to the derivative of the function.
 *     x0: Initial value of the method. Any number inside the domain of the function.
 *     nIter: Max number of iterations.
 *     tol: Desired tolerance.
 *     errorType: String containing the error type
 * 
 * Returns:
 *     One of the roots inside the interval, or an approximation of it.
 * 
 * Throws:
 *     IterException: When the max number of iterations are exceeded.
 *     DerivativeException: When the derivative equals zero.
 */
double newton(double (*func)(double), double (*dFunc)(double), double x0, int nIter, double tol, const char *errorType);