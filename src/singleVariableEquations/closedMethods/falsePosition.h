#pragma once

namespace numath {
    namespace singleVariableEquations {

        /**
         * Function that analizes an interval from a single-variable mathematical
         * function and returns one of it's roots or an approximation of it by 
         * calculating the value in which the straight line from one limit of the
         * interval to the other is zero (all of the values are evaluated in the 
         * function). It analyzes in which of the two sub-intervals the root is
         * and repeats the process until the root is found or the maximum number
         * of iterations are exceeded. 
         * 
         * arguments:
         *     func: Function pointer to the single-variable function.
         *     xi: Inferior value of the interval. Any number inside the domain of the function.
         *     xu: Upper value of the interval. Any number inside the domain of the function.
         *     nIter: Max number of iterations.
         *     tol: Desired tolerance.
         *     errorType: String containing the error type.
         * 
         * Returns:
         *     One of the roots inside the interval, or an approximation of it.
         * 
         * Throws:
         *     IterException: When the max number of iterations are exceeded.
         *     IntervalException: When the interval does not contain a root.
         */
        double falsePosition(double (*func)(double), double xi, double xu, int nIter, double tol, const char *errorType);

    }
}