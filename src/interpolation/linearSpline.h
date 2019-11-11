#pragma once

#include <string>
#include <vector>
#include "point.h"
#include "piecewiseFunction.h"

namespace numath {
    namespace interpolation {


        /**
         * Calculates the polynomial that passes through each 
         * given point using a linear spline.
         * 
         * @param points points to calculate the polynomial.
         */
        PiecewiseFunction linearSpline(std::vector<numath::Point> &points);

    }
}