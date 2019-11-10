#include "linearSpline.h"

namespace numath {
    namespace interpolation {

        PiecewiseFunction linearSpline(std::vector<numath::Point> &points) {
            
            PiecewiseFunction spline;

            for (unsigned int i = 0; i < points.size() - 1; i++) {
                std::string function = "";
                double m = (points[i+1].y - points[i].y) / (points[i+1].x - points[i].x);
                double b = points[i+1].y - (m * points[i+1].x);
                function = std::to_string(m) + "*x+(" + std::to_string(b) + ")";
                // Add the function
                spline.functions.push_back(function);

                Point limit;
                limit.x = points[i].x;
                limit.y = points[i+1].x;
                // Add the X axis limits
                spline.limits.push_back(limit);
            }

            return spline;
        }

    }
}