#include <omp.h>
#include <cstdio>
#include <string>

#include "newton.h"


void __newtonInterpolation(int N, double value, std::vector<double> x, std::vector<double> y){  
        printf("Newton methof.");      
        std::vector<std::vector<double>> table;       
        for(int i = 0; i<N;i++){
            table[i][0] = y[i];
        }    
        
        for(int i = 0; i<N;i++){
            for(int j = 1; j<i+1;j++){
                table[i][j] = (table[i][j-1] - table[i-1][j-1])/(x[i] - x[i-j]);
                
            }
        }
        printf("\ndata table:\n");
        //__printMatrix(table, N,x);
        printf("Interpoling method:");
        //std::string pol = "P(x): "+std::to_string(table[0][0]);
        std::string temp = "";
        double result = table[0][0];
        double aux = 1;
        for(int i = 1; i<N;i++){
           //temp = temp + "(x"+"-"+(x[i-1])+")";
            //pol = pol + "\n"+(table[i][i]>0?"+":"")+(table[i][i]+"*"+temp);
            
            aux = aux * (value-x[i-1]);
            result = result + table[i][i]*aux;
        }
        //System.out.println(pol);
        //System.out.println("\nresult:");
        //System.out.println("f("+value+") = "+ result);
    }

    /* void __printMatrix(std::vector<std::vector<double>> &matrix, int n, std::vector<double> &x){
        //System.out.print("Xi");
        //printSpaces(std::string.valueOf("Xi").length(),30);
        for(int i=0;i<n;i++){
            //System.out.print("f"+(i)+"[]");
            //printSpaces(std::string.valueOf("f"+i+"[]").length(),30);
        }
        //System.out.println("");
        for(int i=0; i< n;i++){
            //System.out.print(x[i]);
            //printSpaces(std::string.valueOf(x[i]).length(),30);
            for(int j=0; j <n; j++){
                //System.out.print(matrix[i][j]);
                //printSpaces(std::string.valueOf(matrix[i][j]).length(),30);
            }
            //System.out.print("\n");
        }
        //System.out.println("");
    }
     
    void __printSpaces(int n, int k){
        if(n<k){
            for(int i = 0; i<k-n;i++){
                //System.out.print(" ");
            }
        }
    }
    
    std::string __strI(int a, int b){
        std::string str = "";
        for(int i=a;i<=b;i++){
           //str = str +""+ i;
        }
        return str;
    } */