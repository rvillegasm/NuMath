#include <stdio.h>
#include "printTable.h"
#include "../../lib/methodNamesConstants.h"

void printTable(short int method, int nIter, double data[]) {

    switch (method) {
        
        case BISECTION:
            _printBisection(nIter, data);               
            break;

    }
}

void _printBisection(int nIter, double data[]) {
    
}
