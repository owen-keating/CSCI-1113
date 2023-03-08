//
//  main.cpp
//  lab12
//
//  Created by Hello on 4/21/21.
//

#include <iostream>
#include "Family.hpp"
#include "Words.hpp"
using namespace std;

//  stretch1

/*int main(){
    string names[] = {"Pops", "Doggo", "Xavier", "Aren"};
    Family f = Family(names, 4);
    f.print(); // shows: Pops, Doggo, Xavier, Aren
}*/

//  stretch2

/*int main(){
    string names[] = {"Pops", "Doggo", "Xavier", "Aren"};
    Family f = Family(names, 4);
    Family copy;
    copy = f;
    copy.change(0, "Mama");
    f.print(); // shows: Pops, Doggo, Xavier, Aren
    copy.print(); // shows: Mama, Doggo, Xavier, Aren
}*/

//  stretch3

/*int main(){
    string names[] = {"Pops", "Doggo", "Xavier", "Aren"};
    Family f = Family(names, 4);
    Family copy = f;
    copy.change(0, "Mama");
    f.print(); // shows: Pops, Doggo, Xavier, Aren
    copy.print(); // shows: Mama, Doggo, Xavier, Aren
}*/

//  workout

/*int main(){
    Words fav;
    fav.add("llama");
    fav.print(); // shows: llama
    cout << fav.maxSize() << endl; // shows: 5
    fav.remove();
    fav.add("ant");
    fav.add("bat");
    fav.add("cat");
    fav.add("dog");
    fav.add("elk");
    fav.add("frog");
    fav.print(); // showns: ant bat cat dog elk frog
    cout << fav.maxSize() << endl; // shows: 10
    fav.remove();
    fav.remove();
    fav.remove();
    fav.print(); // showns: ant bat cat
    cout << fav.maxSize() << endl; // shows: 10
}*/
