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
                                           std::vector<std::vector<double>> &table) {

            int count;
            double dispersion;
            std::vector<double> x0 (initialValues), x1;

            count = 0;
            dispersion = tol + 1;

            // Add info to the table
            std::vector<double> iterVector1 = {(double) count};
            iterVector1.emplace_back(initialValues);
            table.push_back(iterVector1);
            // ---------------------

            while (dispersion > tol && count < nIter) {
                x1 = method(x0, A, b);
                dispersion = errorFunc(x1, x0);
                x0 = x1;
                count++;

                // Add info to the table
                std::vector<double> iterVector2 = {(double) count};
                iterVector2.emplace_back(x1);
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