#include "Player.h"
#include <iostream>

Player::Player(const std::string& name) : name(name) {}

void Player::addCard(const Card& card) {
    hand.push_back(card);
}

void Player::addCards(const std::vector<Card>& cards) {
    hand.insert(hand.end(), cards.begin(), cards.end());
}

Card Player::playCard(int index) {
    if (index < 0 || index >= hand.size()) {
        throw std::out_of_range("Invalid card index");
    }
    Card card = hand[index];
    hand.erase(hand.begin() + index);
    return card;
}

void Player::showHand() const {
    std::cout << name << "'s hand: ";
    for (size_t i = 0; i < hand.size(); ++i) {
        std::cout << "[" << i+1 << ": " << hand[i].toString() << "] ";
    }
    std::cout << std::endl;
}

int Player::handSize() const {
    return hand.size();
}

std::string Player::getName() const {
    return name;
}

const std::vector<Card>& Player::getHand() const {
    return hand;
} 