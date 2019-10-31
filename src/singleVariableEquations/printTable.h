#pragma once
#include "../../lib/methodNamesConstants.h"

namespace numath {
    namespace singleVariableEquations {

        void printTable(methodName method, int nIter, double data[]);

        void _printIncrSearch(int nIter, double data[]);

        void _printBisection(int nIter, double data[]);

        void _printFalsePosition(int nIter, double data[]);

        void _printFixedPoint(int nIter, double data[]);

        void _printNewton(int nIter, double data[]);

        void _printSecant(int nIter, double data[]);

        void _printMultRoots(int nIter, double data[]);

    }
}