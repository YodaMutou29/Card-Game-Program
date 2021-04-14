/**
* @author Jenna McDonnell <jenna.mcdonnell@uleth.ca>
* @author David Neufeld <dj.neufeld@uleth.ca>
* @author Fairooz Afia Saiyara <fairoozafia.saiyara@uleth.ca>
* @author Julie Wojtiw-Quo <wojtiwquoj@uleth.ca>
* @date 2021-03
*/

#ifndef GOFISHHAND_H
#define GOFISHHAND_H

#include "Hand.h"
#include "Card.h"
#include <vector>

class GoFishHand : public Hand {
 public:
  /**
  * Default constructor for GoFishHand
  */
  GoFishHand() : Hand() {}

  /**
  * Destructor
  */
  ~GoFishHand() {}

  /**
  * checks the hand for books, if found they are removed from the hand
  * and put into books
  */
  void checkForBooks();

  /**
  * returns the books from hand
  */
  std::vector<char> getBooks();

 private:
  std::vector<Card*> gameHand;
  std::vector<char> books;
};

#endif //GOFISHHAND_H
