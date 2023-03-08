//
//  Family.cpp
//  lab12
//
//  Created by Hello on 4/27/21.
//

#include <iostream>
#include "Family.hpp"

Family::Family(){
    names = nullptr;
    size = 0;
}

Family::Family(string n[], int s){
    names = new string[s];
    for(int i = 0; i<s; i++){
        names[i] = n[i];
    }
    size = s;
}

Family& Family::operator=(const Family& f){
    delete [] names;
    names = new string[f.size];
    for(int i = 0; i<f.size; i++){
        names[i] = f.names[i];
    }
    size = f.size;
    return *this;
}

Family::Family(const Family& f){
    names = new string[f.size];
    for(int i = 0; i<f.size; i++){
        names[i] = f.names[i];
    }
    size = f.size;
}

Family::~Family(){
    delete [] names;
}

void Family::print(){
    for(int i = 0; i<size-1; i++){
        cout << names[i] << ", ";
    }
    cout << names[size-1] << endl;
}

void Family::change(int i, string n){
    names[i] = n;
}
