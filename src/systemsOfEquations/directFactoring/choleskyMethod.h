#pragma once
#include <vector>
/**
 * Solves a system of N equations by using Cholesky's LU Factoring
 * @param A Matrix of coefficients
 * @param b Vector containing the right side of the system of equations
 */
std::vector<double> choleskyMethod(std::vector<std::vector<double>> A, std::vector<double> b);

/**
 * Fills the matrices L and U with their initial values
 * @param L Matrix L
 * @param U Matrix U
 */
void __initializeMatrixCH(std::vector<std::vector<double>> &L,std::vector<std::vector<double>> &U);

/**
 * Method that factors matrix A into two triangular matrices L and U
 * @param A Matrix of coefficients
 * @param L Initialized L matrix
 * @param U Initialized U matrix
 * @param N Equation system Size
 */
void __LUFactoringCH(std::vector<std::vector<double>> &A, std::vector<std::vector<double>> &L, std::vector<std::vector<double>> &U,  int N);

/**
 * Finds the value of every unknown of the system.
 * 
 * @param L Left side of the system of equations
 * @param b Right side of the system of ecuations
 */
std::vector<double> __forwardSubstitutionCHM(std::vector<std::vector<double>> &L, std::vector<double> &b);

/**
 * Finds the value of every unknown of the system.
 * 
 * @param U Left side of the system of equations
 * @param z Right side of the system of ecuations
 */
std::vector<double> __backwardSubstitutionCHM(std::vector<std::vector<double>> &U, std::vector<double> &z);


//void toStringMatrix(std::vector<std::vector<double>> &augmentedMatrix);