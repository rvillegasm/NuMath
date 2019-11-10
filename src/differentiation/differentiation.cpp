
#include "differentiation.h"
#include "../../lib/point.h"
#include "../../lib/exceptions.h"
#include <vector>
#include <iostream>
/**
 *  x, y lista de x y f(x)
 *  direction 0=backwards, 1=forward, 2 =  central
 */

namespace numath{
    double differentiation( std::vector<Point> &points, int direction, double h, int num ){
        if(num==2){
            return (points[1].y-points[0].y)/h;
        }else if(num==3){
            if(direction==0){
                return (points[0].y-4*points[1].y+3*points[2].y)/(2*h);
            }else if (direction==1){
                return (-points[2].y+4*points[1].y-3*points[0].y)/(2*h);
            }else if(direction ==2){  
                return (-points[0].y+points[2].y)/(2*h);
            }else{
                throw MethodException();
            }
        }else if(num==5){
            if(direction==0){
                return ((25*points[4].y)-(48*points[3].y)+(36*points[2].y)-(16*points[1].y)+(3*points[0].y))/(12*h);
            }else if (direction==1){               
                return  (-25*points[0].y+48*points[1].y-36*points[2].y+16*points[3].y-3*points[4].y)/(12*h);
            }else if(direction ==2){
                return (points[0].y-8*points[1].y+8*points[3].y-points[4].y)/(12*h);
            }else{
                throw MethodException();
            }
        }else{
            throw MethodException();
        }
    }
}