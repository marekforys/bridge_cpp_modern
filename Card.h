#ifndef CARD_H
#define CARD_H

#include <string>

enum class Suit { Clubs, Diamonds, Hearts, Spades };
enum class Rank { Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };

class Card {
public:
    Card(Suit suit, Rank rank);
    Suit getSuit() const;
    Rank getRank() const;
    std::string toString() const;
private:
    Suit suit;
    Rank rank;
};

#endif // CARD_H 