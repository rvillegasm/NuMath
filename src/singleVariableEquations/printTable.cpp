#include <stdio.h>
#include "printTable.h"
#include "../../lib/methodNamesConstants.h"

#define DECIMALS 13

void printTable(methodName method, int nIter, double data[]) {

    switch (method) {
        
        case INCR_SEARCH:
            _printIncrSearch(nIter, data);
            break;

        case BISECTION:
            _printBisection(nIter, data);               
            break;
        case FALSE_POSITION:
            _printFalsePosition(nIter, data);
            break;
        case FIXED_POINT:
            _printFixedPoint(nIter, data);
            break;
        case NEWTON:
            _printNewton(nIter, data);
            break;
        case SECANT:
            _printSecant(nIter, data);
            break;
        case MULT_ROOTS:
            _printMultRoots(nIter, data);
            break;
    }
}

void _printIncrSearch(int nIter, double data[]) {

    printf("%20i | %20.*e | %20.*e |\n", nIter, DECIMALS, data[0], DECIMALS, data[1]);
}

void _printBisection(int nIter, double data[]) {
    
    printf("%20i | %20.*e | %20.*e | %20.*e | %20.*e | %20.*e |\n", nIter, DECIMALS, data[0], DECIMALS, data[1], DECIMALS, data[2],DECIMALS, data[3], DECIMALS, data[4]);
}

void _printFalsePosition(int nIter, double data[]) {

    printf("%20i | %20.*e | %20.*e | %20.*e | %20.*e | %20.*e | %20.*e | %20.*e |\n", nIter, DECIMALS, data[0], DECIMALS, data[1], DECIMALS, data[2], DECIMALS, data[3], DECIMALS, data[4], DECIMALS, data[5], DECIMALS, data[6]);
}

void _printFixedPoint(int nIter, double data[]) {
    
    printf("%20i | %20.*e | %20.*e | %20.*e |\n", nIter, DECIMALS, data[0], DECIMALS, data[1], DECIMALS, data[2]);
}

void _printNewton(int nIter, double data[]) {
    
    printf("%20i | %20.*e | %20.*e | %20.*e | %20.*e |\n", nIter, DECIMALS, data[0], DECIMALS, data[1], DECIMALS, data[2], DECIMALS, data[3]);
}

void _printSecant(int nIter, double data[]) {

    printf("%20i | %20.*e | %20.*e | %20.*e |\n", nIter, DECIMALS, data[0], DECIMALS, data[1], DECIMALS, data[2]);
}

void _printMultRoots(int nIter, double data[]) {

    printf("%20i | %20.*e | %20.*e | %20.*e | %20.*e | %20.*e |\n", nIter, DECIMALS, data[0], DECIMALS, data[1], DECIMALS, data[2], DECIMALS, data[3], DECIMALS, data[4]);
}