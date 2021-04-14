/**
* @author Jenna McDonnell <jenna.mcdonnell@uleth.ca>
* @author David Neufeld <dj.neufeld@uleth.ca>
* @author Fairooz Afia Saiyara <fairoozafia.saiyara@uleth.ca>
* @author Julie Wojtiw-Quo <wojtiwquoj@uleth.ca>
* @date 2021-03
*/

#ifndef GOFISH_H
#define GOFISH_H

#include <vector>
#include <iostream>
#include "CardGame.h"
#include "Player.h"
#include "Card.h"
#include "Book.h"

/**
* Class for implementing GoFish
*/
class GoFish : public CardGame {
 public:
  /**
  * Default constructor, sets initial values for GoFish
  */
  GoFish();

  /**
  * Destructor
  */
  ~GoFish() {}

  void setUp();

  void play();

  /**
  * used by the player who has been requested to give up their card if they do
  * not have the requested card
  * @param p the player to return turn to
  */
  void sayGoFish(Player* p);

  /**
  * used by the player who's turn it is to request a card from another player
  * @param p the player which the current player requests a card from
  * @param c a Card* that the current player requests from another player
  */
  bool askForCard(Player* p, Card* c);

  /**
  * used by the player who has been requested to give up their card if they have
  * the requested card
  * @param p the player who is requesting a card
  * @param c the Card* being given to p
  */
  void giveCard(Player* p, Card* c);

  /**
  * diplays the books of the player who's turn it is
  * @param p the player to get books from
  * @return a vector of the values of the books
  */
  std::vector<Book*> getGoFishBooks(Player* p);

  /**
  * initializes player hands with a starting hand
  */
  void dealHand();

 private:
  Deck* deck;
  int numBooks;
};
#endif //GOFISH_H
