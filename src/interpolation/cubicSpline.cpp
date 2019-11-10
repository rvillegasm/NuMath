#include "cubicSpline.h"

#include <cmath>
#include <iostream>

namespace numath {
    namespace interpolation {

        std::pair<std::vector<std::vector<double>>, std::vector<double>> cubicSpline(std::vector<numath::Point> &points) {

            std::pair<std::vector<std::vector<double>>, std::vector<double>> splineMatrix;

            std::vector<std::vector<double>> matrix;
            std::vector<double> indepTerms;

            const unsigned int N_POINTS = points.size();

            // Points loop - insert the firstRows of the matrix
            for (unsigned int i = 0; i < N_POINTS - 1; i++) {
                
                // For the current point...
                std::vector<double> firstRow;
                // Fill with zeros at the start
                for (unsigned int j = 0; j < ((i + 1) * 4) - 4; j++) {
                    firstRow.push_back(0);
                }
                // Fill with the corresponding values, according to the
                // cubic equation formula (ax^3, bx^2, cx, d)
                firstRow.push_back(pow(points[i].x, 3));
                firstRow.push_back(pow(points[i].x, 2));
                firstRow.push_back(points[i].x);
                firstRow.push_back(1);
                // Fill with zeros at the end
                for (unsigned int j = (i + 1) * 4; j < (N_POINTS - 1) * 4; j++) {
                    firstRow.push_back(0);
                }

                // For the next point...
                std::vector<double> secondRow;
                // Fill with zeros at the start
                for (unsigned int j = 0; j < ((i + 1) * 4) - 4; j++) {
                    secondRow.push_back(0);
                }
                // Fill with the corresponding values, according to the
                // cubic equation formula (ax^3, bx^2, cx, d)
                secondRow.push_back(pow(points[i+1].x, 3));
                secondRow.push_back(pow(points[i+1].x, 2));
                secondRow.push_back(points[i+1].x);
                secondRow.push_back(1);
                // Fill with zeros at the end
                for (unsigned int j = (i + 1) * 4; j < (N_POINTS - 1) * 4; j++) {
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
                for (unsigned int j = 0; j < (i * 4) - 4; j++) {
                    row.push_back(0);
                }
                // Fill with the corresponding values, according to the
                // derivative of the cubic equation (3ax^2, 2bx, c, 0)
                row.push_back(3 * pow(points[i].x, 2));
                row.push_back(2 * points[i].x);
                row.push_back(1);
                row.push_back(0);
                // Push the inverse values next
                row.push_back(-3 * pow(points[i].x, 2));
                row.push_back(-2 * points[i].x);
                row.push_back(-1);
                row.push_back(0);
                // Fill with zeros at the end
                for (unsigned int j = (i * 4) + 4; j < (N_POINTS - 1) * 4; j++) {
                    row.push_back(0);
                }

                // Add the row to the matrix
                matrix.push_back(row);
                indepTerms.push_back(0);
            }

            // Second derivative loop - exclude the first and last values
            for (unsigned int i = 1; i < N_POINTS - 1; i++) {
                
                // For the current point...
                std::vector<double> row;
                // Fill with zeros at the start
                for (unsigned int j = 0; j < (i * 4) - 4; j++) {
                    row.push_back(0);
                }
                // Fill with the corresponding values, according to the
                // second derivative of the cubic equation (6ax, 2b, 0, 0)
                row.push_back(6 * points[i].x);
                row.push_back(2);
                row.push_back(0);
                row.push_back(0);
                // Push the inverse values next
                row.push_back(-6 * points[i].x);
                row.push_back(-2);
                row.push_back(0);
                row.push_back(0);
                // Fill with zeros at the end
                for (unsigned int j = (i * 4) + 4; j < (N_POINTS - 1) * 4; j++) {
                    row.push_back(0);
                }

                // Add the row to the matrix
                matrix.push_back(row);
                indepTerms.push_back(0);
            }

            // Add the row vector that specifies that the second derivative equals zero
            // at the first and last point
            std::vector<double> firstRow;
            firstRow.push_back(6 * points[0].x);
            firstRow.push_back(2);
            for (unsigned int i = 2; i < (N_POINTS - 1) * 4; i++) {
                firstRow.push_back(0);
            }

            std::vector<double> secondRow;
            for (unsigned int i = 0; i < ((N_POINTS - 1) * 4) - 4; i++) {
                secondRow.push_back(0);
            }
            secondRow.push_back(6 * points[N_POINTS-1].x);
            secondRow.push_back(2);
            secondRow.push_back(0);
            secondRow.push_back(0);

            matrix.push_back(firstRow);
            matrix.push_back(secondRow);
            indepTerms.push_back(0);
            indepTerms.push_back(0);

            splineMatrix = std::make_pair(matrix, indepTerms);            

            return splineMatrix;

            // TODO: solve the system (using total pivot), create the piecewise function and return

        }

    }
}