//
//  main.cpp
//  hw1A
//
//  Created by Owen Keating on 2/4/21.
//

#include <iostream>
#include <math.h>
using namespace std;

int main(){
    
    double theta1, theta2, n1, n2;
    cin >> theta1;
    cin >> n1;
    cin >> n2;
    theta2 = asin(sin(theta1 * M_PI / 180) * (n1/n2)) * 180 / M_PI;
    cout << theta2;
    
}
