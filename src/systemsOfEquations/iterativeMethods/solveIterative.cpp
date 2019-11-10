#include "solveIterative.h"
#include "../../../lib/exceptions.h"

#include <string>
#include <cstdio>

namespace numath {
    namespace systemsOfEquations {

        std::vector<double> solveIterative(std::vector<std::vector<double>> &A, 
                                           std::vector<double> &b,
                                           std::vector<double> &initialValues, 
                                           double tol, 
                                           int nIter,
                                           std::vector<double> (*method)(std::vector<double>&,
                                                                         std::vector<std::vector<double>>&,
                                                                         std::vector<double>&),
                                           double (*errorFunc)(std::vector<double>&,
                                                               std::vector<double>&),
                                           double lambda,
                                           std::vector<std::vector<double>> &table) {

            int count;
            double dispersion;
            std::vector<double> x0 (initialValues), x1, lastX1;

            count = 0;
            dispersion = tol + 1;

            // Add info to the table
            std::vector<double> iterVector1 = {(double) count};
            iterVector1.insert(iterVector1.end(), initialValues.begin(), initialValues.end());
            table.push_back(iterVector1);
            // ---------------------

            while (dispersion > tol && count < nIter) {
                if (count != 0) {
                    lastX1 = x1;
                }
                x1 = method(x0, A, b);
                if (count != 0 ) {
                    for (unsigned int i = 0; i < x1.size(); i++) {
                        x1[i] = lambda * x1[i] + (1 - lambda) * lastX1[i]; 
                    }
                }
                dispersion = errorFunc(x1, x0);
                x0 = x1;
                count++;

                // Add info to the table
                std::vector<double> iterVector2 = {(double) count};
                iterVector2.insert(iterVector2.end(), x1.begin(), x1.end());
                iterVector2.push_back(dispersion);
                table.push_back(iterVector2);
                // ---------------------
            }

            if (dispersion < tol) {
                return x1;
            }
            else {
                throw IterException();
            }

        }

    }
}