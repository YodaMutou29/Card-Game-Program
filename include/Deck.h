/**
* @author Jenna McDonnell <jenna.mcdonnell@uleth.ca>
* @author David Neufeld <dj.neufeld@uleth.ca>
* @author Fairooz Afia Saiyara <fairoozafia.saiyara@uleth.ca>
* @author Julie Wojtiw-Quo <wojtiwquoj@uleth.ca>
* @date 2021-03
*/

#ifndef DECK_H
#define DECK_H

// Header files

#include "Card.h"
#include "Game.h"
#include <vector>

/**
* Maintains a deck of cards for the game
*/
class Deck {
 public:
  //constructor

  /**
  * Deck of cards
  */
  Deck();
  /**
  * Deck of cards for the current game
  * @param Game:: CurrentGame
  */
  Deck(Game::CurrentGame);

  /**
  * destructor
  */
  ~Deck();

  //deck functions

  /**
  * Shuffes a deck
  */

  void shuffleDeck();

  //getters

  /**
  * Gets the current deck for the game
  * @return std::vector<Card*>
  */
  std::vector<Card*> getCurrentDeck();

  /**
  * Initiates current game
  * @return game
  */
  Game::CurrentGame getGame();

  /**
  * Gets the card on top of the pile
  * @return Game::CurrentGame
  */
  Card* getTopCard();

  /**
  * Gets the number of cards
  * @return an integer
  */
  int getNumberOfCards();

  //setters

  /**
  * Distributes a deck of cards to players for the current game
  * @param gets card
  * @return cards for the players
  */
  void setCurrentDeck(std::vector<Card*>);

  /**
  * Sets a top card randomly from the pile
  * @param sets card
  * @return an integer number of cards
  */
  //void setTopCard(Card*);
  void setNumberOfCards(int);

 private:
  std::vector<Card*> currentDeck;
  Game::CurrentGame game;
  int numberOfCards;
};
#endif // DECK_H
