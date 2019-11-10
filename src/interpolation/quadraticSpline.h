#pragma once

#include <string>
#include <vector>
#include "../../lib/point.h"
#include "../../lib/piecewiseFunction.h"
#include "../systemsOfEquations/gaussianElimination/gaussianEliminationTotalPivot.h"

namespace numath {
    namespace interpolation {


        /**
         * Calculates the polynomial that passes through each 
         * given point using a quadratic spline.
         * 
         * @param points points to calculate the polynomial.
         */
        PiecewiseFunction quadraticSpline(std::vector<numath::Point> &points);

    }
}