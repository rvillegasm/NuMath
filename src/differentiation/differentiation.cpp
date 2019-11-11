
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
    namespace differentiation{
        double differentiation( std::vector<Point> &points, int direction, double h, int num ){
            if(num==2){
                //Two points
                return (points[1].y-points[0].y)/h;
            }else if(num==3){
                //Uses the first three points
                if(direction==0){
                    // Three points backwards
                    return (points[0].y-4*points[1].y+3*points[2].y)/(2*h);
                }else if (direction==1){
                    // Three points forward
                    return (-points[2].y+4*points[1].y-3*points[0].y)/(2*h);
                }else if(direction ==2){  
                    // Three points center
                    return (-points[0].y+points[2].y)/(2*h);
                }else{
                    throw MethodException();
                }
            }else if(num==5){
                //Uses the first five points
                if(direction==0){
                    // Five points backwards
                    return ((25*points[4].y)-(48*points[3].y)+(36*points[2].y)-(16*points[1].y)+(3*points[0].y))/(12*h);
                }else if (direction==1){    
                    // Five points forward          
                    return  (-25*points[0].y+48*points[1].y-36*points[2].y+16*points[3].y-3*points[4].y)/(12*h);
                }else if(direction ==2){
                    // Five points center
                    return (points[0].y-8*points[1].y+8*points[3].y-points[4].y)/(12*h);
                }else{
                    throw MethodException();
                }
            }else{
                throw MethodException();
            }
        }
    }
}