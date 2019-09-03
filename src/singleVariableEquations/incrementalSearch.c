#include "incrementalSearch.h"

#include <stdio.h>

Pair incrementalSearch(double (*func)(double), double x0, double delta, int nIter) {
    
    double fx0, x1, fx1;
    Pair interval = {0, 0, false};
    
    fx0 = func(x0);

    if (fx0 == 0) {
        // x0 is a root
        interval.first = x0;
        interval.last = x0;
        interval.finished = true;

        return interval;
    }
    else {
        x1 = x0 + delta;
        fx1 = func(x1);
        while (fx0 * fx1 > 0 && --nIter > 0) {
            x0 = x1;
            fx0 = fx1;
            x1 = x0 + delta;
            fx1 = func(x1);
        }

        if (fx1 == 0) {
            // x1 is a root
            interval.first = x1;
            interval.last = x1;
            interval.finished = true; 

            return interval;
        }
        else if (fx0 * fx1 < 0) {
            interval.first = x0;
            interval.last = x1;
            interval.finished = true;

            return interval;
        }
        else {
            // fracaso
        }

        return interval;
    }
    

    // while (func(x0) * func(x1) > 0 && --nIter > 0) {
    //     x0 = x1;
    //     x1 = x1 + delta;
    // }
    
    // printf("%e --> %e\n",x0, func(x0));

    // if (func(x1) == 0) {
    //     // x1 is a root
    //     interval.first = x1;
    //     interval.last = x1;
    //     interval.finished = true;       
    // }

    // if (func(x0) * func(x1) < 0) {
    //     interval.first = x0;
    //     interval.last = x1;
    //     interval.finished = true;
    // }
    // else if (nIter == 0){
    //     // nothing could be found.
    // }

    // return interval;
}