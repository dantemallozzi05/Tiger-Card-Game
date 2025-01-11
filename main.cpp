#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include <iostream>
using namespace std;

int gameIntro() // Provides an intro to the game, as well as getting how many rounds
                // are to be played.
{
  int r;
  cout << "-----------------------" << endl;
  cout << " Welcome to Tiger Game " << endl;
  cout << "-----------------------" << endl << endl;
  cout << "How many rounds would " << endl << "you like to play (1-15)? ";
  cin >> r;

  while (r < 1 || r > 15)
  {
    cout << "Error. Please enter a valid integer (1-15): ";
    cin >> r;
  }

  return r;
}

void printRound(int r) // Prints current round.
{
  cout << "--Round " << r << "--" << endl;
  cout << "__________" << endl;
}

int cardValidate(int choice, Player& human) // Validates that user input is a valid choice.
{

  while (choice < 1 || choice > human.hand.getHandSize())
  {
    cout << "Error. Please make a valid card selection." << endl;
    cout << "Which card do you want to play? ";
    cin >> choice;
  }
  return choice;
}

bool checkTiger(int v) // Checks if passed card value is 50 points (aka Tiger Card).
{
  if (v == 50)
  {
    return true;
  }

  return false;
}

void displayScore(Player& h, Player& c) // Displays score after each round.
{
  cout << endl << "Current Scores:" << endl;
  cout << "Human - " << h.score << endl;
  cout << "Computer - " << c.score << endl;
  cout << endl;
}

void finalScore(Player& h, Player& c) // Displays the score at the end of the game.
{
  cout << endl << "FINAL SCORES: " << endl;
  cout << "Human - " << h.score << endl;
  cout << "Computer - " << c.score << endl;

  if (h.score > c.score)
  {
    cout << "Human has won, Congratulations!" << endl;
  }
  else if (h.score < c.score)
  {
    cout << "Computer has won, better luck next time!" << endl;
  }
  else
  {
    cout << "A tie?" << endl;
  }
  cout << endl;

}

int main() {

  // Seeded randomness
  srand(time(0)); 


  // Variables
  int rCount;
  int cardChoice;

  rCount = gameIntro();

  // 1. Create a deck of cards and shuffle it.
  Deck deckOfCards;
  deckOfCards.shuffle();
  // 2. Create two players, each one with 6 cards in their hand.
  Player human(deckOfCards, rCount);
  Player computer(deckOfCards, rCount);
  // 3. Play six rounds. In each round:

  for (int r = 1; r <= rCount; r++)
  {

    printRound(r);

    //    - Have computer deal a card from their hand.
    Card computerCard = computer.hand.dealCard(0);

    // See if computer had Tiger card.
    if ( checkTiger(computerCard.getValue()) )
    {
      cout << "The computer plays: " << computerCard.strCard() << endl;
      cout << "The computer played the tiger card! Game Over!" << endl;
      computer.score += 50;

      finalScore(human, computer);

      return 0;

    }

    cout << "The computer plays: " << computerCard.strCard() << endl;

    //    - Show human their hand of cards so that they can make a selection.
    cout << "Your Hand: " << human.hand.strHand() << endl;

    //    - Have human deal their card.
    cout << "Which card do you want to play? ";
    cin >> cardChoice;
    // Input validation for card selection.

    cardChoice = cardValidate(cardChoice, human);

    Card humanCard = human.hand.dealCard(cardChoice - 1);

    // Check if human played tiger card
    if ( checkTiger(humanCard.getValue()) )
    {
      cout << "You played: " << humanCard.strCard() << endl;
      cout << "You played the tiger card! Game Over!" << endl;
      human.score += 50;

      finalScore(human, computer);

      return 0;
    }

    // Display what card was played by human.

    cout << "You played: " << humanCard.strCard() << endl;

    //    - Determine who won the round and update points accordingly
     if ( humanCard.getValue() > computerCard.getValue() )
     {
       cout << "You win this round!" << endl;
       human.score += humanCard.getValue() + computerCard.getValue();
     }
     else if ( humanCard.getValue() < computerCard.getValue() )
     {
       cout << "You lost this round!" << endl;
       computer.score += humanCard.getValue() + computerCard.getValue();
     }
     else
     {
       cout << "It's a tie!" << endl;
     }

     //    - Print results for current round.
     displayScore(human, computer);
  }
  // 4. Print final game results.
  finalScore(human, computer);

  return 0;
}
