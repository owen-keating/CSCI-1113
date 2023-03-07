//
//  main.cpp
//  hw5A
//
//  Created by Owen Keating on 3/18/21.
//

#include <iostream>
using namespace std;

int alpha(int x){
    if(x==0){
        return 0;
    }
    else{
        return alpha(x-1) + beta(x) + 1;
    }
}

int beta(int x){
    if(x==0){
        return 0;
    }
    else{
        return beta(x/2) + alpha(x/2) + x;
    }
}

int main(){
    int x, a, b;
    cout << "Which number?" << endl;
    cin >> x;
    a = alpha(x);
    b = beta(x);
    cout << "Alpha number:" << endl << a << endl;
    cout << "Beta number:" << endl << b;
}
