//
//  main.cpp
//  hw1A
//
//  Created by Hello on 2/12/21.
//

#include <iostream>
#include <math.h>
using namespace std;

int main(){
    
    int x = 0;
    char c = 'a';
    while(x==0){
        cin >> c;
        if(c=='s' or c=='S' or c=='c' or c=='C'){
            x = 1;
        }
    }
    double radius;
    cin >> radius;
    double volume;
    if(c=='s' or c=='S'){
        volume = (4.0/3.0) * M_PI * radius * radius * radius;
    }
    else{
        double height;
        cin >> height;
        volume = (1.0/3.0) * M_PI * radius * radius * height;
    }
    cout << volume;
    
}
