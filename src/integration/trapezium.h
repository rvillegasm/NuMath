#pragma once
#include "point.h"
#include <vector>

namespace numath {
    namespace integration {
        /**
         *   Method that finds the integral of a certain function given a list of points
         *   using trapezium general method
         *   @param points Points that pass the function
         */
       double trapezium(std::vector<Point> &points); 
       
    }
}