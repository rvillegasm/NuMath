#include "numath.h"
#include <stdlib.h>
#include <omp.h>
// #include "external/tinyExpression/tinyexpr.h"

#include <iostream>

int main() {
    
    numath::Point p1;
    numath::Point p2;
    numath::Point p3;
    numath::Point p4;

    p1.x = 2;
    p1.y = 3;
    p2.x = 4;
    p2.y = 5;
    p3.x = 7;
    p3.y = -2;
    p4.x = 9;
    p4.y = 11;
    
    std::vector<numath::Point> points;
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
    points.push_back(p4);

    std::vector<std::vector<double>> SGE ={
        {18,12,3,-5,120},
        {6,14,-3,4,-18},
        {3,-6,35,-2,36},
        {12,-7,4,-56,45}
    };

    std::vector<std::vector<double>> SGEB (20,std::vector<double> (20,0));

    for(int i =0;i<SGEB.size();i++){
        for(int j =0;j<SGEB.size();j++){
            if(i != j){
                SGEB[i][j]= rand()%10-5;
            }else if(i == j){
                SGEB[i][j]= rand()%30+15;
            }
        }
    }

    // numath::PiecewiseFunction spline = numath::interpolation::linearSpline(points);
    // for (std::string function : spline.functions) {
    //     std::cout << function << std::endl;
    // }

    // double x;

    // te_variable vars[] = {{"x", &x}};
    // int err;

    // te_expr *expr = te_compile(spline.functions[2].c_str(), vars, 1, &err);

    // if(expr) {
    //     x = 2.5;

    //     const double h1 = te_eval(expr);
    //     std::cout << h1 << std::endl;

    //     te_free(expr);
    // }
    // else {
    //     printf("Parse error at %d\n", err);
    // }
    double start_time = omp_get_wtime();
    std::vector<double> results = numath::systemsOfEquations::simpleGaussianElimination(SGEB);
    double end_time = omp_get_wtime();
    printf("It took: %f\n", end_time - start_time);
    for(int i =1;i<=results.size();i++){
        printf("X%d = %.20f\n",i,results[i-1]);
    }

}