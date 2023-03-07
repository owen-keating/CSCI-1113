//
//  main.cpp
//  hw6A
//
//  Created by Hello on 3/25/21.
//

#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 10000;

int main(){
    string u;
    cout << "Enter username:" << endl;
    cin >> u;
    string p;
    cout << "Enter password:" << endl;
    cin >> p;
    ifstream inFS;
    inFS.open("peopleData.txt");
    int size = 0;
    string users[MAX];
    while(!inFS.fail()){
        string a;
        getline(inFS,a);
        if(a!=""){
            users[size] = a;
            size++;
        }
    }
    inFS.close();
    string usernames[MAX];
    string passwords[MAX];
    for(int i = 0; i<size; i++){
        int n = int(users[i].find(' '));
        usernames[i] = users[i].substr(0,n);
        passwords[i] = users[i].substr(n+1);
    }
    for(int i = 0; i<size; i++){
        if(u==usernames[i]){
            if(p==passwords[i]){
                cout << "Login successful!";
            }
            else{
                cout << "Alert! Hacker detected!";
            }
            break;
        }
        if(i==size-1){
            cout << "No account created.";
        }
    }
    return 0;
}
