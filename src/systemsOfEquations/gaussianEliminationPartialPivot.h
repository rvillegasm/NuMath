#pragma once
#include <vector>


/**
 * Solves a system of N equations by using a simple version of the
 * Gaussian Elimination algorithm (without any pivoting).
 * 
 * @param augmentedMatrix augmented matrix representing the system 
 *                        (size N-1 by N).
 */
std::vector<double> gaussianEliminationPartialPivot(std::vector<std::vector<double>> augmentedMatrix);

/**
 * Transforms a given augmented matrix into a superior triangular matrix.
 * 
 * @param augmentedMatrix augmented matrix representig the system.
 */
void __forwardElimination2(std::vector<std::vector<double>> &augmentedMatrix);

/**
 * Relocates rows in a matrix so the largest element of each row is placed in the main diagonal
 * 
 * @param augmentedMatrix augmented matrix representig the system.
 */
void __partialPivot(std::vector<std::vector<double>> &augmentedMatrix, int k, int n);

/**
 * Finds the value of every unknown of the suystem.
 * 
 * @param augmentedTriangularMatrix augmented triangular matrix of the system.
 */
std::vector<double> __backwardSubstitution2(std::vector<std::vector<double>> &augmentedTriangularMatrix);


// void toStringMatrix(std::vector<std::vector<double>> &augmentedMatrix);