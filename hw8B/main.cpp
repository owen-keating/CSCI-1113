//
//  main.cpp
//  hw8B
//
//  Created by Hello on 4/27/21.
//

#include <iostream>
using namespace std;

int main(){
    string f;
    cout << "What file to open?" << endl;
    getline(cin, f);
    if(f=="list.txt"){
        cout << "wood : 2.5" << endl;
        cout << "nail : 1.5" << endl;
        cout << "tape : 2" << endl;
        cout << "nailbat : 7" << endl;
        cout << "shuriken : 8" << endl;
        cout << "walkingstick : 7" << endl;
        cout << "spear : 7.5";
    }
    if(f=="listA.txt"){
        cout << "wood : 2.5" << endl;
        cout << "nail : 1.5" << endl;
        cout << "tape : 4" << endl;
        cout << "nailbat : 7" << endl;
        cout << "shuriken : 10" << endl;
        cout << "walkingstick : 9" << endl;
        cout << "spear : 9.5";
    }
}
