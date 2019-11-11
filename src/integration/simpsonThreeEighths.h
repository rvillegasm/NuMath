#pragma once
#include "point.h"
#include <vector>

namespace numath {
    namespace integration {
        /**
         *   Method that finds the integral of a certain function given a list of points
         *   using simpson3/8 general method
         *   @param points Points that pass the function
         */
       double simpsonThreeEighths(std::vector<Point> &points); 
       
    }
}