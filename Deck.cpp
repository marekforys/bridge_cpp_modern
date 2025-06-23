#include "Deck.h"
#include <algorithm>
#include <random>
#include <chrono>

Deck::Deck() {
    for (int s = 0; s < 4; ++s) {
        for (int r = 2; r <= 14; ++r) {
            cards.emplace_back(static_cast<Suit>(s), static_cast<Rank>(r));
        }
    }
    currentIndex = 0;
}

void Deck::shuffle() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
    currentIndex = 0;
}

Card Deck::draw() {
    if (currentIndex < cards.size()) {
        return cards[currentIndex++];
    }
    throw std::out_of_range("No more cards in the deck");
}

bool Deck::empty() const {
    return currentIndex >= cards.size();
}

std::vector<Card> Deck::dealHand(int numCards) {
    std::vector<Card> hand;
    for (int i = 0; i < numCards; ++i) {
        hand.push_back(draw());
    }
    return hand;
} 