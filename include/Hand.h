/**
* @author Jenna McDonnell <jenna.mcdonnell@uleth.ca>
* @author David Neufeld <dj.neufeld@uleth.ca>
* @author Fairooz Afia Saiyara <fairoozafia.saiyara@uleth.ca>
* @author Julie Wojtiw-Quo <wojtiwquoj@uleth.ca>
* @date 2021-03
*/

#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include "Exceptions.h"
#include "Book.h"
#include <vector>

/**
* Class to implement the hand of a player
*/
class Hand {
 public:
  /**
  * Default constructor of Hand
  */
  Hand();

  /**
  * Destructor
  */
  virtual ~Hand() {}

  /**
  * used to a add a card to the hand
  * @param c the Card* to be put into the player's hand
  */
  void addCard(Card* c);

  /**
  * used to a remove a card from the hand
  * @param c the Card* to be removed from the player's hand
  */
  void removeCard(int);

  /**
  * returns the number of cards in a player's hand
  */
  int getNumberOfCards();

  std::vector<Book*> getBooks();

  /**
  * checks if a card is in the hand
  * @param c the Card* to be checked for in the hand
  */
  bool checkForCard(Card* c);

  bool checkForBooks();

  /**
  * returns the gameHand
  * @return vector<Card*> representing gameHand
  */
  std::vector<Card*> getGameHand();

 protected:
  int numberOfCards;
  std::vector<Card*> gameHand;
  std::vector<Book*> books;
};
std::ostream& operator<< (std::ostream&, Hand);
#endif //HAND_H
