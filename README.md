# Console Bridge Card Game (C++)

This is a simple console-based Bridge card game for 4 players (North, East, South, West). You play as South; the other players are AI (random play). The game deals cards, plays 13 tricks, and scores tricks for each team.

## How to Build

```
g++ -std=c++11 -o bridge main.cpp Game.cpp Player.cpp Deck.cpp Card.cpp
```

## How to Run

```
./bridge
```

## Gameplay
- You play as South.
- On your turn, your hand is displayed. Enter the number of the card you want to play.
- The game plays 13 tricks and displays the final score.

## Files
- `main.cpp` - Entry point
- `Game.h/cpp` - Game logic
- `Player.h/cpp` - Player logic
- `Deck.h/cpp` - Deck logic
- `Card.h/cpp` - Card representation
