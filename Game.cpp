#include "Game.h"
#include <iostream>
#include <algorithm>
#include <random>

Game::Game() : teamNS_tricks(0), teamEW_tricks(0)
{
    players.emplace_back("North");
    players.emplace_back("East");
    players.emplace_back("South"); // User
    players.emplace_back("West");
}

void Game::dealCards()
{
    deck = Deck();
    deck.shuffle();
    for (auto &player : players)
    {
        player.addCards(deck.dealHand(13));
    }
}

void Game::play()
{
    dealCards();
    int leadPlayer = 0; // North leads first
    for (int trick = 0; trick < 13; ++trick)
    {
        playTrick(leadPlayer);
        // Winner of the trick leads next
        leadPlayer = (leadPlayer + 1) % 4;
    }
    showScores();
}

void Game::playTrick(int leadPlayer)
{
    std::vector<Card> trick;
    int current = leadPlayer;
    std::cout << "\nNew trick!" << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        Player &player = players[current];
        // Card playedCard;
        if (player.getName() == "South")
        {
            player.showHand();
            int choice = -1;
            while (true)
            {
                std::cout << "Choose a card to play (1-" << player.handSize() << "): ";
                std::cin >> choice;
                if (choice >= 1 && choice <= player.handSize())
                    break;
                std::cout << "Invalid choice. Try again." << std::endl;
            }
            Card playedCard = player.playCard(choice - 1);
            trick.push_back(playedCard);
        }
        else
        {
            // AI: play random card
            std::vector<Card> hand = player.getHand();
            int idx = rand() % hand.size();
            Card playedCard = player.playCard(idx);
            trick.push_back(playedCard);
            std::cout << player.getName() << " plays " << playedCard.toString() << std::endl;
        }

        current = (current + 1) % 4;
    }
    // Determine winner (highest card of lead suit)
    int winner = getTrickWinner(trick, leadPlayer);
    std::cout << players[winner].getName() << " wins the trick!" << std::endl;
    if (winner % 2 == 0)
        teamNS_tricks++;
    else
        teamEW_tricks++;
}

int Game::getTrickWinner(const std::vector<Card> &trick, int leadPlayer) const
{
    Suit leadSuit = trick[0].getSuit();
    int winner = 0;
    Rank highest = trick[0].getRank();
    for (int i = 1; i < 4; ++i)
    {
        if (trick[i].getSuit() == leadSuit && trick[i].getRank() > highest)
        {
            highest = trick[i].getRank();
            winner = i;
        }
    }
    return (leadPlayer + winner) % 4;
}

void Game::showScores() const
{
    std::cout << "\nFinal Scores:" << std::endl;
    std::cout << "North/South: " << teamNS_tricks << " tricks" << std::endl;
    std::cout << "East/West: " << teamEW_tricks << " tricks" << std::endl;
}
