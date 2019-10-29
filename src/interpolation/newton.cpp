#include <omp.h>
#include <cstdio>
#include <string>

#include "newton.h"


void __newtonInterpolation(int N, double value, std::vector<double> &x, std::vector<double> &y){  
        
        printf("Newton method.");      
        std::vector<std::vector<double>> table(N, std::vector<double>(N));       
        for(int i = 0; i<N;i++){
            table[i][0] = y[i];
        }    
        
        for(int i = 0; i<N;i++){
            for(int j = 1; j<i+1;j++){
                table[i][j] = (table[i][j-1] - table[i-1][j-1])/(x[i] - x[i-j]);
                
            }
        }
        printf("\nData table:\n");
        __printMatrixN(table, N,x);
        std::string pol = "\nP(x): "+std::to_string(table[0][0]);
        std::string temp = "";
        double result = table[0][0];
        double aux = 1;
        for(int i = 1; i<N;i++){
            temp = temp + "(x-"+std::to_string(x[i-1])+")";
            char c = ' ';
            if(table[i][i]>0){
                c ='+';
            }
            pol = pol + " "+c+(std::to_string(table[i][i])+"*"+temp);
            
            aux = aux * (value-x[i-1]);
            result = result + table[i][i]*aux;
        }
        printf(pol.c_str());
        printf("\nResult:");
        std::string s = "f("+std::to_string(value)+") = "+ std::to_string(result);
        printf(s.c_str()); 
    }

     void __printMatrixN(std::vector<std::vector<double>> &matrix, int n, std::vector<double> &x){
        printf("Xi");
        __printSpaces(0,30);
        for(int i=0;i<n;i++){
            std::string s = "f"+std::to_string(i)+"[]";
            printf(s.c_str());
            __printSpaces(s.length(),30);
        }
        printf(" \n");
        for(int i=0; i< n;i++){
            printf(std::to_string(x[i]).c_str());
            __printSpaces(std::to_string(x[i]).length(),30);
            for(int j=0; j <n; j++){

                std::string a = std::to_string(matrix[i][j]);
                printf(a.c_str());
                __printSpaces(std::to_string(matrix[i][j]).length(),30);
            }
            printf("\n");
        }
        printf(" ");
    }
     
    void __printSpaces(int n, int k){
        if(n<k){
            for(int i = 0; i<(k-n)/2;i++){
                printf(" ");
            }
        }
    }
    
    std::string __strI(int a, int b){
        std::string str = "";
        for(int i=a;i<=b;i++){
           str = str +""+ std::to_string(i);
        }
        return str;
    }  