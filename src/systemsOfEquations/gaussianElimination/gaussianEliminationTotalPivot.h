#pragma once
#include <vector>


/**
 * Solves a system of N equations by using a simple version of the Gaussian Elimination algorithm 
 * and Total Pivot strategy to reduce propagation error.
 * 
 * @param augmentedMatrix augmented matrix representing the system 
 *                        (size N-1 by N).
 */
std::vector<double> gaussianEliminationTotalPivot(std::vector<std::vector<double>> augmentedMatrix);

/**
 * Transforms a given augmented matrix into a superior triangular matrix.
 * 
 * @param augmentedMatrix augmented matrix representig the system.
 */
void __forwardEliminationTP(std::vector<std::vector<double>> &augmentedMatrix);

/**
 * Relocates rows and columns in a matrix so the largest element in k row and column is placed in the main diagonal
 * 
 * @param augmentedMatrix augmented matrix representig the system.
 */
void __totalPivot(std::vector<std::vector<double>> &augmentedMatrix, std::vector<int> &marks, int k, int n);

/**
 * Finds the value of every unknown of the suystem.
 * 
 * @param augmentedTriangularMatrix augmented triangular matrix of the system.
 */
std::vector<double> __backwardSubstitutionTP(std::vector<std::vector<double>> &augmentedTriangularMatrix);

/**
 * Initializes the marks' vector
 * @param n size of the marks' vector.
 */
std::vector<int> __fillMarks(int n);

void toStringMatrixGT(std::vector<std::vector<double>> &augmentedMatrix);