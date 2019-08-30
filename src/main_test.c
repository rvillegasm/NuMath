#include <stdio.h>
#include "singleVariableEquations/incrementalSearch.h"

double f(double x);

int main() {
    Pair interval = incrementalSearch(f, 0, 0.001, 2500);
    printf("The root is inside %f and %f\n", interval.first, interval.last);
}

double f(double x) {
    return x - 1;
}