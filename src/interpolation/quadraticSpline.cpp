#include "quadraticSpline.h"

#include <cmath>
#include <iostream>

namespace numath {
    namespace interpolation {

        std::pair<std::vector<std::vector<double>>, std::vector<double>> quadraticSpline(std::vector<numath::Point> &points) {

            std::pair<std::vector<std::vector<double>>, std::vector<double>> splineMatrix;

            std::vector<std::vector<double>> matrix;
            std::vector<double> indepTerms;

            const unsigned int N_POINTS = points.size();

            // Points loop - insert the firstRows of the matrix
            for (unsigned int i = 0; i < N_POINTS - 1; i++) {
                
                // For the current point...
                std::vector<double> firstRow;
                // Fill with zeros at the start
                for (unsigned int j = 0; j < ((i + 1) * 3) - 3; j++) {
                    firstRow.push_back(0);
                }
                // Fill with the corresponding values, according to the
                // quadratic equation formula (ax^2, bx, c)
                firstRow.push_back(pow(points[i].x, 2));
                firstRow.push_back(points[i].x);
                firstRow.push_back(1);
                // Fill with zeros at the end
                for (unsigned int j = (i + 1) * 3; j < (N_POINTS - 1) * 3; j++) {
                    firstRow.push_back(0);
                }

                // For the next point...
                std::vector<double> secondRow;
                // Fill with zeros at the start
                for (unsigned int j = 0; j < ((i + 1) * 3) - 3; j++) {
                    secondRow.push_back(0);
                }
                // Fill with the corresponding values, according to the
                // quadratic equation formula (ax^2, bx, c)
                secondRow.push_back(pow(points[i+1].x, 2));
                secondRow.push_back(points[i+1].x);
                secondRow.push_back(1);
                // Fill with zeros at the end
                for (unsigned int j = (i + 1) * 3; j < (N_POINTS - 1) * 3; j++) {
                    secondRow.push_back(0);
                }

                // Add the row and the corresponding independent term to the matrix
                matrix.push_back(firstRow);
                indepTerms.push_back(points[i].y);
                matrix.push_back(secondRow);
                indepTerms.push_back(points[i+1].y);
            }

            // Derivative loop - exclude the first and last values
            for (unsigned int i = 1; i < N_POINTS - 1; i++) {
                
                // For the current point...
                std::vector<double> row;
                // Fill with zeros at the start
                for (unsigned int j = 0; j < (i * 3) - 3; j++) {
                    row.push_back(0);
                }
                // Fill with the corresponding values, according to the
                // derivative of the quadratic equation (2ax, b, 0)
                row.push_back(2 * points[i].x);
                row.push_back(1);
                row.push_back(0);
                // Push the inverse values next
                row.push_back(-2 * points[i].x);
                row.push_back(-1);
                row.push_back(0);
                // Fill with zeros at the end
                for (unsigned int j = (i * 3) + 3; j < (N_POINTS - 1) * 3; j++) {
                    row.push_back(0);
                }

                // Add the row to the matrix
                matrix.push_back(row);
                indepTerms.push_back(0);
            }

            // Add the row vector that specifies that the derivative equals zero
            // at the first point
            std::vector<double> row;
            row.push_back(2 * points[0].x);
            row.push_back(1);
            for (unsigned int i = 2; i < (N_POINTS - 1) * 3; i++) {
                row.push_back(0);
            }

            matrix.push_back(row);
            indepTerms.push_back(0);

            splineMatrix = std::make_pair(matrix, indepTerms);            

            return splineMatrix;

            // TODO: solve the system (using total pivot), create the piecewise function and return

        }

    }
}