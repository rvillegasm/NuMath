#pragma once

#include <vector>
#include <string>
#include "point.h"

namespace numath{
    namespace interpolation {
        
        /**
         * Calculates the polynomial that passes through each 
         * given point using Lagrange's method.
         * 
         * @param points points to calculate the polynomial.
         */
        std::string lagrange(std::vector<numath::Point> &points);

    }
}