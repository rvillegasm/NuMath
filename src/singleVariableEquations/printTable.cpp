#include <stdio.h>
#include "printTable.h"
#include "../../lib/methodNamesConstants.h"

void printTable(methodName method, int nIter, double data[]) {

    switch (method) {
        
        case BISECTION:
            _printBisection(nIter, data);               
            break;

    }
}

void _printBisection(int nIter, double data[]) {
    
    // printf("Method: Bisection\n");
    // printf("%10s%10s%10s%10s%10s%10s\n", "iter", "Xi", "Xu", "Xm", "f(Xm)", "Error");
    printf("%10i%10e%10e%10e%10e%10e", nIter, data[0], data[1], data[2], data[3], data[4]);
}
