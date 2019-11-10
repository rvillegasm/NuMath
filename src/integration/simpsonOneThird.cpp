#include "simpsonOneThird.h"

namespace numath {
    namespace integration {

       double simpsonOneThird(std::vector<Point> &points) {

           const unsigned int N_POINTS = points.size();

           double h = (points[N_POINTS-1].x - points[0].x) / (N_POINTS - 1);

           double oddPointSum = 0;
           for (unsigned int i = 1; i < N_POINTS - 1; i += 2) {
               oddPointSum += points[i].y;
           }

           double evenPointSum = 0;
           for (unsigned int i = 2; i < N_POINTS - 1; i += 2) {
               evenPointSum += points[i].y;
           }


           return (h / 3) * (points[0].y + (4 * oddPointSum) + (2 * evenPointSum) +points[N_POINTS-1].y);

       }
       
    }
}