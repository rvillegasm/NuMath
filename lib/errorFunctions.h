#pragma once

#include <vector>
#include <cmath>

namespace numath {
    
    /**
     * Calculates the absolute squared norm between two vectors of the same size.
     * 
     * @param x1 first vector.
     * @param x2 second vector.
     */
    double absNorm(std::vector<double> &x1, std::vector<double> &x0);

    /**
     * Calculates the realtive squared norm between two vectors of the same size.
     * 
     * @param x1 first vector.
     * @param x2 second vector.
     */
    double relNorm(std::vector<double> &x1, std::vector<double> &x0);
    
}