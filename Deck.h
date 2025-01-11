#ifndef DECK_H_
#define DECK_H_

#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

#include "Card.h"

class Deck
{
private:
  std::vector<Card> deck; // Deck vector

public:
  Deck();

  void shuffle();
  Card drawCard();
  int getDeckSize() const;
};


#endif // DECK_H_
