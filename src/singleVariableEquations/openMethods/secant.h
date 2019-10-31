#pragma once

namespace numath {
    namespace singleVariableEquations {

        /**
         * Function that analizes a single-variable mathematical function and
         * returns one of it's roots or an approximation of it by calculating
         * a straight line between the two initial values and finding the value
         * in which that line equals zero. It then calculates a line between the
         * second starting value and the newly found one and repeats the process
         * until the root is found.
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
         *     DenominatorException: When the denominator of the line function is zero.
         */
        double secant(double (*func)(double), double x0, double x1, int nIter, double tol, const char *errorType);

    }
}