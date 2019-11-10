#pragma once
#include "../../lib/point.h"
#include <vector>

namespace numath {
    namespace integration {
        /**
         *   Method that finds the integral of a certain function given a list of points
         *   using simpson1/3 general method
         *   @param points Points that pass the function
         */
       double simpsonOneThird(std::vector<Point> &points); 
       
    }
}