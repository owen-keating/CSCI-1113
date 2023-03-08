//
//  DeckOfCards.cpp
//  lab09
//
//  Created by Hello on 3/30/21.
//

#include <iostream>
#include "DeckOfCards.hpp"
using namespace std;

DeckOfCards::DeckOfCards(){
    index = 0;
    for(int i = 0; i<4; i++){
        deck[i*13] = "A";
        deck[i*13+1] = "2";
        deck[i*13+2] = "3";
        deck[i*13+3] = "4";
        deck[i*13+4] = "5";
        deck[i*13+5] = "6";
        deck[i*13+6] = "7";
        deck[i*13+7] = "8";
        deck[i*13+8] = "9";
        deck[i*13+9] = "10";
        deck[i*13+10] = "J";
        deck[i*13+11] = "Q";
        deck[i*13+12] = "K";
    }
    shuffle();
}

string DeckOfCards::dealCard(){
    index++;
    return deck[index-1];
}

void DeckOfCards::shuffle(){
    srand(int(time(0)));
    for(int i = 51; i>0; i--){
        int j = rand()%(i+1);
        string s = deck[i];
        deck[i] = deck[j];
        deck[j] = s;
    }
}
