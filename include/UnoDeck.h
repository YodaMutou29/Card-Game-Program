#ifndef UNODECK_H
#define UNODECK_H

// Header files

#include "Card.h"
#include "Deck.h"
#include <vector>

/**
* Uno Deck
* @param buildUnoDeck, getDeck & std::vector<Card*>
* @return buildUnoDeck() & getDeck()
*/
class UnoDeck : public Deck {
 public:
  UnoDeck();
  ~UnoDeck();
  std::vector<Card*> buildUnoDeck();

 private:
};
#endif
