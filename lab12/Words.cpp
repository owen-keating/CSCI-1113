//
//  Words.cpp
//  lab12
//
//  Created by Hello on 4/27/21.
//

#include <iostream>
#include "Words.hpp"

Words::Words(){
    arr = new string[5];
    index = 0;
    size = 5;
}

Words::~Words(){
    delete [] arr;
}

void Words::add(string s){
    if(index<size){
        arr[index] = s;
    }
    else{
        string str;
        for(int i = 0; i<size; i++){
            str = str + arr[i] + " ";
        }
        delete [] arr;
        size = size + 5;
        arr = new string[size];
        int start = 0, end;
        for(int i = 0; i<index; i++){
            end = static_cast<int>(str.find(' ', start));
            arr[i] = str.substr(start, end-start);
            start = end+1;
        }
        arr[index] = s;
    }
    index++;
}

void Words::remove(){
    arr[index-1] = "";
    index--;
}

void Words::print(){
    for(int i = 0; i<index-1; i++){
        cout << arr[i] << " ";
    }
    cout << arr[index-1] << endl;
}

int Words::maxSize(){
    return size;
}
