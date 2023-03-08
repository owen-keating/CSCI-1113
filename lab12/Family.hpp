//
//  Family.hpp
//  lab12
//
//  Created by Hello on 4/27/21.
//

#ifndef FAMILY_H
#define FAMILY_H

#include <stdio.h>
using namespace std;

class Family{
public:
    Family();
    Family(string n[], int s);
    Family& operator=(const Family& f);
    Family(const Family& f);
    ~Family();
    void print();
    void change(int i, string n);
private:
    string* names;
    int size;
};

#endif
