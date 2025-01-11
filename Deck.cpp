#include "Deck.h"
#include "Card.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>

Deck::Deck() // Fills cards with appropiate ranks
{

  for (int i = 1; i <= 15; i++) // 1-15 for black
  {
    deck.push_back(Card(i, Card::purple));
  }

  for (int i = 1; i <= 10; i++) // 1-10 for orange
  {
    deck.push_back(Card(i, Card::orange));
  }

  for (int i = 6; i <= 10; i++) // 6-10 for black
  {
    deck.push_back(Card(i, Card::black));
  }

  deck.push_back(Card(10, Card::tiger)); // Tiger Card

}
// Method for shuffling deck via random_shuffle.
void Deck::shuffle()
{
  std::random_shuffle(deck.begin(), deck.end());
}
// Method for drawing card from deck.
Card Deck::drawCard()
{
    Card c = deck.front();
    deck.erase(deck.begin()); // Removes this card from deck.
    return c; // Returns the first card in the deck.

}
// Method for returning deck size.
int Deck::getDeckSize() const
{
  return deck.size();
}
