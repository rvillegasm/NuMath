#pragma once
#include "../../lib/point.h"
#include <vector>
namespace numath{
    /**
     *   Method that finds the derivative at a certain point given the values ​​of nearby points
     *   @param points Close points
     *   @param direction Backwards(0),forward(1) or central(2)
     *   @param h Point spacing 
     *   @param num Number of points with which the derivative will be calculated
     */
double differentiation(std::vector<Point> &points, int direction, double h, int num);
}