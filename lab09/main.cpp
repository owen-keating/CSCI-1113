//
//  main.cpp
//  lab09
//
//  Created by Hello on 3/24/21.
//

#include <iostream>
#include <vector>
#include "Point.hpp"
#include "Bug.hpp"
#include "Complex.hpp"
#include "DeckOfCards.hpp"
using namespace std;

//  warmup

/*int main(){
    Point p1 = Point(5,6);
    Point p2;
    p2 = Point();
    p1.showPoint();
    p2.showPoint();
    return 0;
}*/

//  stretch1

/*int main(){
    Bug b1 = Bug(10);
    b1.display();
    b1.move();
    b1.display();
    b1.turn();
    b1.display();
    b1.move();
    b1.display();
    return 0;
}*/

//  stretch2

/*int main(){
    double a, b, c, d;
    cout << "Enter values for real and imaginary coefficients: ";
    cin >> a >> b;
    Complex c1 = Complex(a,b);
    cout << "Enter values for real and imaginary coefficients: ";
    cin >> c >> d;
    Complex c2 = Complex(c,d);
    c1.output();
    c2.output();
    c2.setReal(22.2);
    cout << "The new real coefficient is " << c2.getReal() << endl;
    c2.output();
    return 0;
}*/

//  workout1

void show_hand(string a, string b, string c, string d){
    cout << a << " " << b << " " << c << " " << d << endl;
}

/*int main(){
    DeckOfCards d1 = DeckOfCards();
    for(int i = 0; i<13; i++){
        string hand[4];
        for(int j = 0; j<4; j++){
            hand[j] = d1.dealCard();
        }
        show_hand(hand[0], hand[1], hand[2], hand[3]);
    }
    return 0;
}*/

//  workout2

int scoreDealer(vector<int>& hand, int length){
    int score = 0;
    for(int i = 0; i<length; i++){
        score+=hand[i];
    }
    int ace_index = -1;
    bool ace = false;
    for(int i = 0; i<length; i++){
        if(hand[i]==11){
            ace_index = i;
            ace = true;
        }
    }
    if(score>21 and ace==true){
        hand[ace_index] = 1;
        return scoreDealer(hand,length);
    }
    else{
        return score;
    }
}

/*int main(){
    DeckOfCards d1 = DeckOfCards();
    vector<int> hand(2);
    for(int i = 0; i<2; i++){
        string a = d1.dealCard();
        cout << "next card: " << a << endl;
        if(a=="A"){
            hand[i] = 11;
        }
        else if(a=="J" or a=="Q" or a=="K"){
            hand[i] = 10;
        }
        else{
            hand[i] = stoi(a);
        }
    }
    int length = 2;
    int score = scoreDealer(hand,length);
    if(score==21){
        cout << "dealer blackjack" << endl;
    }
    while(score<17){
        string b = d1.dealCard();
        cout << "next card: " << b << endl;
        if(b=="A"){
            hand.push_back(11);
        }
        else if(b=="J" or b=="Q" or b=="K"){
            hand.push_back(10);
        }
        else{
            hand.push_back(stoi(b));
        }
        length++;
        score = scoreDealer(hand,length);
    }
    if(score>21){
        cout << "dealer busted" << endl;
    }
    cout << "dealer scores " << score << endl;
    return 0;
}*/
