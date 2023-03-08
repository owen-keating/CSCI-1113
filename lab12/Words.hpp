//
//  Words.hpp
//  lab12
//
//  Created by Hello on 4/27/21.
//

#ifndef WORDS_H
#define WORDS_H

#include <stdio.h>
using namespace std;

class Words{
public:
    Words();
    ~Words();
    void add(string s);
    void remove();
    void print();
    int maxSize();
private:
    string* arr;
    int index;
    int size;
};

#endif
