#include "incrementalSearch.h"

Pair incrementalSearch(double (*func)(double), double x0, double delta, int nIter) {
    
    double x1;
    Pair interval = {0, 0};
    
    if (func(x0) == 0) {
        // x0 is a root
    }
    
    x1 = x0 + delta;
    if (func(x1) == 0) {
        // x1 is a root
    }

    while (func(x0) * func(x1) > 0 && nIter-- > 0) {
        x0 = x1;
        x1 = x1 + delta;
    }

    if (func(x0) * func(x1) < 0) {
        interval.first = x0;
        interval.last = x1;
    }
    else if (nIter == 0){
        // nothing could be found.
    }

    return interval;
}