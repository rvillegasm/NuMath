#include "gaussSeidel.h"

std::vector<double> gaussSeidel(std::vector<double> &variables, 
                                std::vector<std::vector<double>> &matrix,
                                std::vector<double> &indepTerms) {
    
    double sum;
    std::vector<double> results (indepTerms.size());
    const int N = variables.size();

    // already does the same as: for i = 0 to N-1 do x1[i] := x0[i]
    results = variables;

    for (int i = 0; i < N; i++) {

        sum = 0;
        for (int j = 0; j < N; j++) {
            if (j != i) {
                sum = sum + (matrix[i][j] * results[j]);
            }
        }

        results[i] = (indepTerms[i] - sum) / matrix[i][i];
    }

    return results;
}