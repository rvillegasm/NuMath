#pragma once

#include <vector>
#include <string>
#include "point.h"

namespace numath{
    namespace interpolation {

        /**
         * Calculates the polynomial that passes through each
         * given point using Newton's method.
         * 
         * @param points points to calculate the polynomial.
         * @param finalTable Table in which the calculated values will be stored
         */
        std::string newton(std::vector<numath::Point> &points, std::vector<std::vector<double>> &finalTable);

    }
}