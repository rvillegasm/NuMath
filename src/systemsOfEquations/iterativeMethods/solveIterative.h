#pragma once
#include <vector>

/**
 * Solves a system of N equations by using a specified iterative method such
 * as Jacobi's or Gauss-Seidel's, based on a given set of initial values,
 * a tolerance and a max number of iterations.
 * 
 * @param A Matrix containing the coefficients of system of equations.
 * @param b Independent terms of the system of equations.
 * @param initialValues Initial values for every variable of the system.
 * @param tol Desired tolereance.
 * @param nIter Desired maximum number of iterations.
 * @param method Function specifying the method to be used.
 * @param errorFunc Function used to calculate the dispersion of the method.
 * 
 * @throw IterException if the number of iterations runs out without being able to surpass the tolerance.
 *          
 */
std::vector<double> solveIterative(std::vector<std::vector<double>> &A, 
                                   std::vector<double> &b,
                                   std::vector<double> &initialValues, 
                                   double tol, 
                                   int nIter,
                                   std::vector<double> (*method)(std::vector<double>&,
                                                                 std::vector<std::vector<double>>&,
                                                                 std::vector<double>&),
                                   double (*errorFunc)(std::vector<double>&,
                                                       std::vector<double>&));