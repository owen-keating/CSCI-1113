//
//  Point.cpp
//  lab09
//
//  Created by Hello on 3/30/21.
//

#include <iostream>
#include "Point.hpp"
using namespace std;

Point::Point(){
    xlocation = 0;
    ylocation = 0;
}

Point::Point(int x, int y){
    xlocation = x;
    ylocation = y;
}

void Point::showPoint() const{
    cout << "(" << xlocation << "," << ylocation << ")" << endl;
}
