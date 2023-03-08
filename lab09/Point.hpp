//
//  Point.hpp
//  lab09
//
//  Created by Hello on 3/30/21.
//

#ifndef POINT_H
#define POINT_H

class Point{
public:
    void showPoint() const;
    Point();
    Point(int, int);
private:
    int xlocation;
    int ylocation;
};

#endif
