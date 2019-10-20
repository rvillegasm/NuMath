#pragma once
#include <vector>
#include <cmath>

/**
 * Calculates the absolute squared norm between two vectors of the same size.
 * 
 * @param x1 first vector.
 * @param x2 second vector.
 */
double absNorm(std::vector<double> &x1, std::vector<double> &x0) {
    double sum = 0;
    for (long unsigned int i = 0; i < x1.size(); i++) {
        sum += pow(fabs(x1[i] - x0[i]), 2);
    }
    return sqrt(sum);
}

/**
 * Calculates the realtive squared norm between two vectors of the same size.
 * 
 * @param x1 first vector.
 * @param x2 second vector.
 */
double relNorm(std::vector<double> &x1, std::vector<double> &x0) {
    
    double numeratorSum = 0;
    double denominatorSum = 0;
    for (long unsigned int i = 0; i < x1.size(); i++) {
        numeratorSum += pow(fabs(x1[i] - x0[i]), 2);
        denominatorSum += pow(x1[i], 2);
    }

    return sqrt(numeratorSum)/sqrt(denominatorSum);
}