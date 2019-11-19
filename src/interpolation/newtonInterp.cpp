#include "newtonInterp.h"

#include <vector>
#include <string>

namespace numath{
    namespace interpolation {

        std::string newton(std::vector<numath::Point> &points, std::vector<std::vector<double>> &finalTable) {

            const unsigned int N = points.size();
            double table[N][N];

            std::string result = "";

            // Initialize table with the F(x) values
            for (unsigned int i = 0; i < N; i++) {
                table[i][0] = points[i].y;
            }
            // Calculate all the values of the table
            for (unsigned int i = 0; i < N; i++) {
                for (unsigned int j = 1; j <= i; j++) {
                    table[i][j] = (table[i][j-1] - table[i-1][j-1]) / (points[i].x - points[i-j].x);
                }
            }

            // Add the local table to the one passed as a parameter
            for (unsigned int i = 0; i < N; i++) {
                std::vector<double> row;
                for (unsigned int j = 0; j < N; j++) {
                    row.push_back(table[i][j]);
                }
                finalTable.push_back(row);
            }
            // -----------------------------------------------------

            // Build the polynomial
            for (unsigned int i = 0; i < N; i++) {
                // calculate each term of the polynomial
                std::string term;
                if (i == 0) {
                    term = std::to_string(table[i][i]);
                }
                else {
                    term = "+" + std::to_string(table[i][i]);
                }
                for (unsigned int k = 0; k < i; k++) {
                    term = term + "*(x-" + std::to_string(points[k].x) + ")";
                }
                
                result = result + term;
            }

            return result;
        }

    }
}