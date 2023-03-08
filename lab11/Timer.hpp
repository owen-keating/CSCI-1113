//
//  Timer.hpp
//  lab11
//
//  Created by Hello on 4/14/21.
//

#ifndef TIMER_H
#define TIMER_H

#include <stdio.h>

class Timer{
public:
    Timer();
    Timer(int h, int m);
    int* randArray(int n);
private:
    int hours;
    int minutes;
};

#endif
