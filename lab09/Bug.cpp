//
//  Bug.cpp
//  lab09
//
//  Created by Hello on 3/30/21.
//

#include <iostream>
#include "Bug.hpp"
using namespace std;

Bug::Bug(){
    position = 0;
    dir = 1;
}

Bug::Bug(int x){
    position = x;
    dir = 1;
}

void Bug::move(){
    position+=dir;
}

void Bug::turn(){
    dir*=-1;
}

void Bug::display() const{
    cout << "position = " << position << ", direction = " << dir << endl;
}
