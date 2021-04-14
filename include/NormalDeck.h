#ifndef NORMALDECK_H
#define NORMALDECK_H

//Header files

#include "Card.h"
#include "Deck.h"
#include <vector>

/**
* Normal Deck
*/
class NormalDeck : public Deck {
 public:
  NormalDeck();
  ~NormalDeck();
/**
* @param build normal deck
* @return build normal deck
*/
  std::vector<Card*> buildNormalDeck();


 private:
  std::vector<Card*> deck;
};
#endif
