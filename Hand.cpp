#include "Hand.h"
#include <iostream>

Hand::Hand() = default; // Default constructor.

Hand::Hand(Deck& deck, int N) // Constructor which initializes the human / computer hand.
{
  for (int i = 0; i < N; i++) // fills # of cards for appropiate rounds at the start.
  {
    hand.push_back(deck.drawCard());
  }
}
// Method for returning the user's hand.
std::string Hand::strHand()
{
  std::string humanHand;

  for (int i = 1; i <= hand.size(); i++)
  {
    humanHand += " [" + std::to_string(i) + "] " + hand[i - 1].strCard();
  }
  return humanHand;
}
// Method for dealing user card.
Card Hand::dealCard(int num)
{
  Card c = hand[num];
  hand.erase(hand.begin() + (num));
  return c;
}
// Getter for the hand size.
int Hand::getHandSize() const
{
  return hand.size();
}
