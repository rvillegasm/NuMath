#include "lagrange.h"

#include <vector>
#include <string>
#include "../../lib/point.h"

namespace numath{
    namespace interpolation {

        std::string lagrange(std::vector<numath::Point> &points) {
        
            std::string result = "";
            const unsigned int N = points.size();
            
            for (unsigned int i = 0; i < N; i++) {
                
                std::string li = "";
                for (unsigned int p = 0; p < N; p++) {
                    if (p != i) {
                        li = li + "((x-" + std::to_string(points[p].x) + ")";
                        li = li + "/(" + std::to_string(points[i].x - points[p].x) + "))*";
                        
                    }
                }

                if (i == 0){
                    // Do not add the terms together
                    result = result + li + std::to_string(points[i].y);
                }
                else {
                    // Add the terms together
                    result = result + "+" + li + std::to_string(points[i].y);
                }
            }

            return result;
        }

    }
}
