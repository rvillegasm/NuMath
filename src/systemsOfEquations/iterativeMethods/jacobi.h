#pragma once
#include <vector>

/**
 * Generates a new set of values for an iterative method approach
 * using the jacobi method.
 * 
 * Note: This function only calculates one set of values and does not 
 * solve a system of equations. In order to actually solve it use
 * the 'solveIterative' function and pass this function to it as the
 * 'method' function pointer. 
 * 
 * @param variables vector of variables to be used for the generation of the
 *                  new ones.
 * @param matrix matrix representing the system of equations.
 * @param indepTerms vector containing the independent terms of the system.
 */
std::vector<double> jacobi(std::vector<double> &variables, 
                           std::vector<std::vector<double>> &matrix,
                           std::vector<double> &indepTerms);