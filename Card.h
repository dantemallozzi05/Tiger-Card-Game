#ifndef CARD_H_
#define CARD_H_

#include <string>

class Card
{
public:

  enum Color { purple, orange, black, tiger }; // enum var for card color

  Card();
  Card(int rank, Color color);

  std::string strCard();

  int getRank();
  Color getColor();
  int getValue();

private:

  int rank;
  Color color;
  int value;

};

#endif // CARD_H_
