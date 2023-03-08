//
//  Point.hpp
//  lab10
//
//  Created by Hello on 3/31/21.
//

#ifndef POINT_H
#define POINT_H

#include <stdio.h>
using namespace std;

class Point{
public:
    Point();
    Point(int xval, int yval);
    //Point operator+(Point a);
    friend Point operator+(Point a, Point b);
    friend ostream& operator<<(ostream& os, Point a);
private:
    int xloc;
    int yloc;
};

#endif
