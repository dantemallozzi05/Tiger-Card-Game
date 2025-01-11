#include "Card.h"
#include <string>

Card::Card() : rank(0), color(purple), value(0) {} // Default constructor to initialize card.

Card::Card(int rank, Color color)
{
  // Initialize rank and color via this pointer.
  this->rank = rank;
  this->color = color;

  // Sets value of card based on color & rank.
  if (this->color == purple)
  {
    value = this->rank;
  }
  else if (this->color == orange)
  {
    value = (this->rank) * 2;
  }
  else if (this->color == black)
  {
    value = (this->rank) * 3;
  }
  else
  {
    value = (this->rank) * 5;
  }

}
// Concatenates card color with rank
std::string Card::strCard()
{
  std::string card;

  switch (color)
  {
    case purple: { card = "purple"; break; }
    case orange: { card = "orange"; break; }
    case black: { card = "black"; break; }
    case tiger: { card = "tiger"; break; }
  }

  card += ":" + std::to_string(rank);

  return card;

}
// Getter for rank
int Card::getRank()
{
  return rank;
}
// Getter for color
Card::Color Card::getColor()
{
  return color;
}
// Getter for value
int Card::getValue()
{
  return value;
}
