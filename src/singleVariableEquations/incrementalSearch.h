#pragma once

#include "../../lib/interval.h"

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
Interval incrementalSearch(double (*func)(double), double x0, double delta, int nIter);