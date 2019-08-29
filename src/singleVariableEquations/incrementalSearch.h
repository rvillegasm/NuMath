typedef struct pair {
    double first;
    double last;
}

pair incrementalSearch(double (*func)(double), double x0, double delta, int nIter);