#include "trapezium.h"

namespace numath {
    namespace integration {

       double trapezium(std::vector<Point> &points) {

           const unsigned int N_POINTS = points.size();

           double h = (points[N_POINTS-1].x - points[0].x) / (N_POINTS - 1);

           double sum = 0;
           for (unsigned int i = 1; i < N_POINTS - 1; i++) {
               sum += points[i].y; 
           }

           return (h / 2) * (points[0].y + (2 * sum) + points[N_POINTS-1].y);
       }
       
    }
}