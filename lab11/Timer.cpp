//
//  Timer.cpp
//  lab11
//
//  Created by Hello on 4/14/21.
//

#include <iostream>
#include "Timer.hpp"

Timer::Timer(){
    hours = 0;
    minutes = 0;
}

Timer::Timer(int h, int m){
    hours = h;
    minutes = m;
}

int* Timer::randArray(int n){
    int* arr = new int[n];
    for(int i = 0; i<n; i++){
        arr[i] = rand();
    }
    return arr;
}
