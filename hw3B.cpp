//
//  main.cpp
//  hw3B
//
//  Created by Hello on 2/19/21.
//

#include <iostream>
#include <math.h>
using namespace std;

int main(){
    
    int num_triangles = 0;
    double total_area = 0.0;
    double base = 0.0;
    double height = 0.0;
    char type = 't';
    while(type=='t'){
        type = 'a';
        while(type!='t' and type!='q'){
            cout << "Please enter a command" << endl;
            cin >> type;
            if(type!='t' and type!='q'){
                cout << "Unknown command, try again" << endl;
                continue;
            }
        }
        if(type=='t'){
            cin >> base >> height;
            if(base<=0 or height<=0){
                cout << "Invalid triangle, try again" << endl;
                continue;
            }
            num_triangles++;
            total_area = total_area + (0.5 * base * height);
        }
        base = 0.0;
        height = 0.0;
    }
    
    if(num_triangles==0){
        cout << "No triangles";
    }
    else{
        cout << "Average area:" << endl << (total_area / num_triangles);
    }
    
}
