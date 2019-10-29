 #include <omp.h>
#include <cstdio>
#include <string>
#include "math.h"
#include "lagrange.h"
 
 void __lagrangeInterpolation(int n, double value, std::vector<double> &x, std::vector<double> &y){
        printf("\nLagrange.");
        printf("\n\nFunction L(x):");
        
        double result = 0;
        std::string pol = "\nP(x): ";  
        for(int k = 0; k<n;k++){
            double product = 1;
            std::string term = "";
            for(int i = 0; i < n ; i++){
                if(i!=k){
                    product = product * (value-x[i])/(x[k]-x[i]);
                    term = term + ("[(x-"+std::to_string(x[i])+")/("+std::to_string(x[k])+"-"+std::to_string(x[i])+")]");
                }
            }
            std::string s1 ="\nL"+std::to_string(k)+"(x):"+term;
            printf(s1.c_str());
            char c = ' ';
            if(y[k]>0){c='+';}
            pol += (c)+std::to_string(y[k])+"*"+term+"\n";
            result += product * y[k];
        } 
        printf("\n\nInterpolating polynomial");
        printf(pol.c_str()); 
        printf("\nResult:");
        std::string s ="\nf("+std::to_string(value)+") = "+ std::to_string(result);
        printf(s.c_str());
    }
