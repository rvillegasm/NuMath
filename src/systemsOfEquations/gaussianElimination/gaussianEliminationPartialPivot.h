#pragma once
#include <vector>


/**
 * Solves a system of N equations by using the Gaussian Elimination algorithm 
 * and Partial Pivot strategy to reduce propagation error.
 * @param augmentedMatrix augmented matrix representing the system 
 *                        (size N-1 by N).
 */
std::vector<double> gaussianEliminationPartialPivot(std::vector<std::vector<double>> augmentedMatrix);

/**
 * Transforms a given augmented matrix into a superior triangular matrix.
 * 
 * @param augmentedMatrix augmented matrix representig the system.
 */
void __forwardEliminationPP(std::vector<std::vector<double>> &augmentedMatrix);

/**
 * Relocates rows in a matrix so the largest element of each row is placed in the main diagonal
 * 
 * @param augmentedMatrix augmented matrix representig the system.
 */
void __partialPivot(std::vector<std::vector<double>> &augmentedMatrix, int k, int n);

/**
 * Finds the value of every unknown of the system.
 * 
 * @param augmentedTriangularMatrix augmented triangular matrix of the system.
 */
std::vector<double> __backwardSubstitutionPP(std::vector<std::vector<double>> &augmentedTriangularMatrix);


//void toStringMatrix(std::vector<std::vector<double>> &augmentedMatrix);