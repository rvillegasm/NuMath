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
                                                               std::vector<double>&)) {

            int count;
            double dispersion;
            std::vector<double> x0 (initialValues), x1;

            count = 0;
            dispersion = tol + 1;

            // BORRAR LUEGO 
            printf("%5s | ", "nIter");
            for (unsigned int i = 0; i < initialValues.size(); i++){
                std::string machete = "X" + std::to_string(i);
                printf("%10s | ", machete.c_str());
            }

            printf("%10s \n", "Error");

            printf("%5d | ", count);
            for (unsigned int i = 0; i < initialValues.size(); i++){
                printf("%10lf | ", x0[i]);
            }
            printf("\n");

            // BORRAR LUEGO

            while (dispersion > tol && count < nIter) {
                x1 = method(x0, A, b);
                dispersion = errorFunc(x1, x0);
                x0 = x1;
                count++;

                // BORRAR LUEGO
                printf("%5d | ", count);
                for (unsigned int i = 0; i < initialValues.size(); i++){
                    printf("%10lf | ", x1[i]);
                }
                printf("%10e \n", dispersion);

                // BORRAR LUEGO
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