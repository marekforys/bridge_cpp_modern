#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Player.h"
#include "Deck.h"

class Game {
public:
    Game();
    void play();
private:
    std::vector<Player> players;
    Deck deck;
    int teamNS_tricks;
    int teamEW_tricks;
    void dealCards();
    void playTrick(int trickNumber);
    int getTrickWinner(const std::vector<Card>& trick, int leadPlayer) const;
    void showScores() const;
};

#endif // GAME_H 