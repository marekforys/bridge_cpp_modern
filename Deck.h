#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

class Deck {
public:
    Deck();
    void shuffle();
    Card draw();
    bool empty() const;
    std::vector<Card> dealHand(int numCards);
private:
    std::vector<Card> cards;
    int currentIndex;
};

#endif // DECK_H 