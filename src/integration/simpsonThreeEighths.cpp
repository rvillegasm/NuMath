#include "../../lib/point.h"
#include <vector>

namespace numath {
    namespace integration {

       double simpsonThreeEighths(std::vector<Point> &points) {

           const unsigned int N_POINTS = points.size();

           double h = (points[N_POINTS-1].x - points[0].x) / (N_POINTS - 1);

           double multiple3Sum = 0;
           double nonMultiple3Sum = 0;
           for (unsigned int i = 1; i < N_POINTS - 1; i++) {
               if (i % 3 == 0) {
                   multiple3Sum += points[i].y;
               }
               else {
                   nonMultiple3Sum += points[i].y;
               }
            }
            return ((3 * h) / 8) * (points[0].y + points[N_POINTS-1].y + (2 * multiple3Sum) + (3 * nonMultiple3Sum));
       }
       
    }
}