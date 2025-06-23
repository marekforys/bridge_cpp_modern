#include "Card.h"
#include <sstream>

Card::Card(Suit suit, Rank rank) : suit(suit), rank(rank) {}

Suit Card::getSuit() const {
    return suit;
}

Rank Card::getRank() const {
    return rank;
}

std::string Card::toString() const {
    static const char* suitNames[] = {"C", "D", "H", "S"};
    static const char* rankNames[] = {"", "", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    std::ostringstream oss;
    oss << rankNames[static_cast<int>(rank)] << suitNames[static_cast<int>(suit)];
    return oss.str();
} 