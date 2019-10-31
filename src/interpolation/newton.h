#pragma once

#include <vector>
#include <string>
#include "../../lib/point.h"

namespace numath{
    namespace interpolation {

        /**
         * Calculates the polynomial that passes through each
         * given point using Newton's method.
         * 
         * @param points points to calculate the polynomial.
         */
        std::string newton(std::vector<numath::Point> &points);

    }
}