//
//  Bug.hpp
//  lab09
//
//  Created by Hello on 3/30/21.
//

#ifndef BUG_H
#define BUG_H

class Bug{
public:
    Bug();
    Bug(int);
    void move();
    void turn();
    void display() const;
private:
    int position;
    int dir;
};

#endif
