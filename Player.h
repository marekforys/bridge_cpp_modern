#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include "Card.h"

class Player {
public:
    Player(const std::string& name);
    void addCard(const Card& card);
    void addCards(const std::vector<Card>& cards);
    Card playCard(int index);
    void showHand() const;
    int handSize() const;
    std::string getName() const;
    const std::vector<Card>& getHand() const;
private:
    std::string name;
    std::vector<Card> hand;
};

#endif // PLAYER_H 