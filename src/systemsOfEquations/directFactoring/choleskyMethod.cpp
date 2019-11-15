#include <omp.h>
#include "choleskyMethod.h"
#include <cfloat>
#include <math.h>

#include "../../../lib/exceptions.h"

namespace numath {
    namespace systemsOfEquations {

        std::vector<double> choleskyMethod(std::vector<std::vector<double>> A, std::vector<double> b)
        {
            int N = A.size();
            std::vector<double> results;
            std::vector<std::vector<double>> L(N, std::vector<double>(N, 0.0));
            std::vector<std::vector<double>> U(N, std::vector<double>(N, 0.0));
            __initializeMatrixCH(L, U);

            try
            {
                __LUFactoringCH(A, L, U, N);
                // printf("Final L matrix\n");
                // toStringMatrixCH(L);
                // printf("Final U matrix\n");
                // toStringMatrixCH(U);
                std::vector<double> z = __forwardSubstitutionCHM(L, b);
                // printf("z vector\n");
                // for(double e: z){
                //     printf("%f ",e);
                // }
                // printf("\n\n");
                results = __backwardSubstitutionCHM(U, z);
            }
            catch (DenominatorException &ex)
            {
                throw ex;
            }
            return results;
        }

        void __initializeMatrixCH(std::vector<std::vector<double>> &L, std::vector<std::vector<double>> &U)
        {
            int N = L.size();
            
            #pragma omp parallel for
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (i < j)
                    {
                        U[i][j] = DBL_MAX;
                        L[i][j] = 0;
                    }
                    else if (i > j)
                    {
                        L[i][j] = DBL_MAX;
                        U[i][j] = 0;
                    }
                    else if (i == j)
                    {
                        U[i][j] = DBL_MAX;
                        L[i][j] = DBL_MAX;
                    }
                }
            }
        }

        void __LUFactoringCH(std::vector<std::vector<double>> &A, std::vector<std::vector<double>> &L, std::vector<std::vector<double>> &U, int N)
        {
            for(int k = 1; k < N+1; k++){
                // printf("Phase %d\n\n",k);
                // toStringIncMatrixCH(L,'L');
                // toStringIncMatrixCH(U,'U');
                
                    double sum = 0;

                    #pragma omp parallel for reduction(+:sum)
                    for(int p = 0; p < k-1; p++){
                        sum += L[k-1][p] * U[p][k-1];
                    }
                    U[k-1][k-1] = sqrt(A[k-1][k-1] - sum);
                    L[k-1][k-1] = U[k-1][k-1];
                    
                    for(int j = k+1; j < N+1; j++){
                        sum = 0;

                        #pragma omp parallel for reduction(+:sum)
                        for(int p = 0; p < k-1; p++){
                            
                            sum += L[j-1][p] * U[p][k-1];
                        }
                        L[j-1][k-1] = (A[j-1][k-1] - sum) / L[k-1][k-1];
                    }
                    
                    for(int i = k+1; i < N+1; i++){
                        sum = 0;

                        #pragma omp parallel for reduction(+:sum)
                        for(int p = 0; p < k-1; p++){
                            sum += L[k-1][p] * U[p][i-1];
                        }
                        U[k-1][i-1] = (A[k-1][i-1] - sum)/L[k-1][k-1];
                    } 
                    
                }
            
            
        }

        std::vector<double> __forwardSubstitutionCHM(std::vector<std::vector<double>> &L, std::vector<double> &b)
        {
            int N = L.size();
            std::vector<double> x(N, 0.0);
            for (int i = 1; i < N + 1; i++)
            {
                double sum = 0;
                for (int p = i - 1; p > 0; p--)
                {
                    sum += (L[i - 1][p - 1] * x[p - 1]);
                }
                double denominator = L[i - 1][i - 1];
                if (denominator == 0)
                {
                    throw DenominatorException();
                }
                else
                {
                    x[i - 1] = (b[i - 1] - sum) / L[i - 1][i - 1];
                }
            }
            return x;
        }

        std::vector<double> __backwardSubstitutionCHM(std::vector<std::vector<double>> &U, std::vector<double> &z)
        {
            int N = U.size();
            std::vector<double> x(N, 0.0);
            for (int i = N - 1; i >= 0; i--)
            {
                double sum = 0;
                for (int j = i + 1; j < N; j++)
                {
                    sum += U[i][j] * x[j];
                }
                double denominator = U[i][i];
                if (denominator == 0)
                {
                    throw DenominatorException();
                }
                else
                {
                    x[i] = (z[i] - sum) / U[i][i];
                }
            }
            return x;
        }

        // void toStringMatrixCH(std::vector<std::vector<double>> &matrix)
        // {
        //     for (unsigned int i = 0; i < matrix.size(); i++)
        //     {
        //         for (unsigned int j = 0; j < matrix[0].size(); j++)
        //         {
        //             printf("%f ",matrix[i][j]);
        //         }
        //         std::cout << std::endl;
                
        //     }
        //     printf("\n");
        // } 

        //Prints incomplete matrix with equal spacing
        // void toStringIncMatrixCH(std::vector<std::vector<double>> &matrix, char name)
        // {
        //     printf("%c matrix\n",name);
        //     for (unsigned int i = 0; i < matrix.size(); i++)
        //     {
        //         for (unsigned int j = 0; j < matrix[0].size(); j++)
        //         {
        //             if(matrix[i][j]==DBL_MAX){
        //                 if(i==j){
        //                     printf("%6c%d%d ",'L',j+1,i+1);
        //                 }else{
        //                 printf("%6c%d%d ",name,j+1,i+1);
        //                 }
        //             }else{
        //                 printf("%.6f ",matrix[i][j]);
        //             }
        //         }
        //         std::cout << std::endl;
                
        //     }
        //     printf("\n");
        // } 

    }
}