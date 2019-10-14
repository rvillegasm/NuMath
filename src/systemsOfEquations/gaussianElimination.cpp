#include <omp.h>
#include "gaussianElimination.h"

#include "../../lib/exceptions.h"

// #include <iostream>

std::vector<double> simpleGaussianElimination(std::vector<std::vector<double>> augmentedMatrix) {
    std::vector<double> results;
    try {
        __forwardElimination(augmentedMatrix);
        // toStringMatrix(augmentedMatrix);
        results = __backwardSubstitution(augmentedMatrix);
    }
    catch (DenominatorException &ex) {
        throw ex;
    }
    return results;
}

void __forwardElimination(std::vector<std::vector<double>> &augmentedMatrix) {
    const int N = augmentedMatrix.size();
    double multDenominator,multiplier;
    // Phase cicle
    for (int k = 1; k <= N-1; k++) {
        // Row cicle
        //#pragma omp parallel for schedule(static,10) default(none) shared(augmentedMatrix,k) private(multDenominator,multiplier)
        #pragma omp parallel for
        for(int i = k + 1; i <= N; i++) {
            multDenominator = augmentedMatrix[k-1][k-1];
            if (multDenominator == 0) {
                throw DenominatorException();
            }
            else {
                multiplier = augmentedMatrix[i-1][k-1] / multDenominator;
                // Column cicle
                for (int j = k; j <= N + 1; j++) {
                    augmentedMatrix[i-1][j-1] = augmentedMatrix[i-1][j-1] - (multiplier * augmentedMatrix[k-1][j-1]);
                }
            }
        }
    }
}

std::vector<double> __backwardSubstitution(std::vector<std::vector<double>> &augmentedTriangularMatrix) {
    const int N = augmentedTriangularMatrix.size();
    std::vector<double> results(N, 0.0);
    // Inverse row cicle
    for (int i = N; i > 0; i--) {
        results[i-1] = augmentedTriangularMatrix[i-1][N];
        //Column cicle 
        for (int j = i+1; j <= N; j++) {
            results[i-1] = results[i-1] - augmentedTriangularMatrix[i-1][j-1] * results[j-1];
        }
        double denominator = augmentedTriangularMatrix[i-1][i-1];        
        if (denominator == 0) {
            throw DenominatorException();
        }
        else {
            results[i-1] = results[i-1] / denominator;
        }
    }
    return results;
}


// void toStringMatrix(std::vector<std::vector<double>> &augmentedMatrix) {
//     for (int i = 0; i < augmentedMatrix.size(); i++) {
//         for(int j = 0; j < augmentedMatrix[0].size(); j++) {
//             std::cout << augmentedMatrix[i][j] << "  ";
//         }
//         std::cout << std::endl;
//     }
// }

