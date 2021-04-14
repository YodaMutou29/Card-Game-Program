#ifndef CRAZYEIGHTS_H
#define CRAZYEIGHTS_H

#include "Deck.h"

class CrazyEights : public Game {
 public:
  CrazyEights();
  void setUp();
  void play();
  Deck* getDeck();

 private:
  Deck* deck;
};
#endif
