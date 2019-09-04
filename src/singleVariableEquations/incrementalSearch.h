#pragma once

#include <stdbool.h>

/** 
 * Representation of an interval. It's Fields are:
 * first (double): The initial value of the interval.
 * last (double): The final value fo the interval.
 * successful (bool): If an interval (or root) could actually be found.
 * isRoot (bool): If the two values represent a root instead of an interval. 
 */
typedef struct Interval {
    double first;
    double last;
    bool wasSuccessful;
    bool isRoot;
} Interval;

/**
 * Function that analizes a single-variable mathematical function and
 * returns an interval that contains a root of said function.
 * 
 * arguments:
 *     func: Function pointer to the single-variable function.
 *     x0: Starting point of the algo. Any number inside the domain of the function.
 *     delta: Amount in which the interval will be moved during the search.
 *     nIter: Max number of iterations.
 * 
 * Returns:
 *     Interval containing the starting and final values of the interval, if it finds one,
 *     or a pair of two equal numbers if it finds a root.
 */
int incrementalSearch(double (*func)(double), double x0, double delta, int nIter, double *retVal0, double *retVal1);