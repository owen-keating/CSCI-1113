//
//  Point.cpp
//  lab10
//
//  Created by Hello on 3/31/21.
//

#include <iostream>
#include "Point.hpp"
using namespace std;

Point::Point(){
    xloc = 0;
    yloc = 0;
}

Point::Point(int xval, int yval){
    xloc = xval;
    yloc = yval;
}

/*Point Point::operator+(Point a){
    Point totalval;
    totalval.xloc = xloc + a.xloc;
    totalval.yloc = yloc + a.yloc;
    return totalval;
}*/

Point operator+(Point a, Point b){
    Point totalval;
    totalval.xloc = a.xloc + b.xloc;
    totalval.yloc = a.yloc + b.yloc;
    return totalval;
}

ostream& operator<<(ostream& os, Point a){
    os << '(' << a.xloc << ',' << a.yloc << ')' << endl;
    return os;
}
