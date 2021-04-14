/**
* @author Jenna McDonnell <jenna.mcdonnell@uleth.ca>
* @author David Neufeld <dj.neufeld@uleth.ca>
* @author Fairooz Afia Saiyara <fairoozafia.saiyara@uleth.ca>
* @author Julie Wojtiw-Quo <wojtiwquoj@uleth.ca>
* @date 2021-03
*/

#ifndef CARDGAME_H
#define CARDGAME_H

// Header files

#include "Game.h"
#include "Deck.h"
#include "Card.h"

/**
* Intiates a card game
*/

class CardGame : public Game {
 public:
  /**
  * Default constructor, sets initial values for the card game
  */
  CardGame() : Game() {}

  /**
  * Destructor
  */
  virtual ~CardGame() {}

  /**
  * used by player to pick up a card from the deck
  * @return the Card* picked up from Deck
  */
  Card* pickUpCard();

 protected:
  /**
  * used to check if a card is in the player's hand
  * @param p the player who's hand is being checked
  * @param c the Card* to be checked
  */
  bool cardInHand(Player* p, Card* c);
  Deck* gameDeck;
};

#endif //CARDGAME_H
