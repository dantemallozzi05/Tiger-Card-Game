// Note: There is no Player.cpp file.
// The player class is simple enough to
// implement everything in Player.h

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Hand.h"

class Player
{
public:
  Hand hand; // object of hand needed to access hand of each player.
  int score = 0; // score variable used to keep score.

  Player() = default; 
  Player(Deck& deck, int N) : hand(deck, N) {}
};

#endif // PLAYER_H_
