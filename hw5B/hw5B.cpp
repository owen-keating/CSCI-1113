//
//  main.cpp
//  hw5B
//
//  Created by Hello on 3/18/21.
//

#include <iostream>
using namespace std;

string unmash(string s, string n, int x){
    if(x == s.length()*2){
        return n;
    }
    else{
        if(x < s.length()){
            n = n + s.at(x);
        }
        else{
            n = n + s.at(s.length()-(x-s.length()+1));
        }
        x+=2;
        return unmash(s, n, x);
    }
}

int main(){
    string s, sorted, n = "";
    int x = 0;
    cout << "Enter anything:" << endl;
    getline(cin, s);
    sorted = unmash(s, n, x);
    cout << sorted;
}
