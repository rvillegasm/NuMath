#pragma once
#include <vector>

namespace numath {
    namespace systemsOfEquations {

        /**
         * Solves a system of N equations by using a simple version of the
         * Gaussian Elimination algorithm (without any pivoting).
         * 
         * @param augmentedMatrix augmented matrix representing the system 
         *                        (size N-1 by N).
         */
        std::vector<double> simpleGaussianElimination(std::vector<std::vector<double>> augmentedMatrix);

        /**
         * Transforms a given augmented matrix into a superior triangular matrix.
         * 
         * @param augmentedMatrix augmented matrix representig the system.
         */
        void __forwardElimination(std::vector<std::vector<double>> &augmentedMatrix);

        /**
         * Finds the value of every unknown of the system.
         * 
         * @param augmentedTriangularMatrix augmented triangular matrix of the system.
         */
        std::vector<double> __backwardSubstitution(std::vector<std::vector<double>> &augmentedTriangularMatrix);


        void toStringMatrixGE(std::vector<std::vector<double>> &augmentedMatrix);

    }
}