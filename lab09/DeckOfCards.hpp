//
//  DeckOfCards.hpp
//  lab09
//
//  Created by Hello on 3/30/21.
//

#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

class DeckOfCards{
public:
    DeckOfCards();
    std::string dealCard();
    void shuffle();
private:
    int index;
    std::string deck[52];
};

#endif
