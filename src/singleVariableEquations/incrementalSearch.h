#pragma once
#include <stdbool.h>

/* Representation of a pair. It's Fields are first and last. */
typedef struct Pair {
    double first;
    double last;
    bool finished;
    
} Pair;

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
 *     Pair containing the starting and final values of the interval, if it finds one.
 *     TODO: Otherwise, STILL TO BE DETERMINED
 */
Pair incrementalSearch(double (*func)(double), double x0, double delta, int nIter);