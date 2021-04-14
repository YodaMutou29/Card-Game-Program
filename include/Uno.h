#ifndef UNO_H
#define UNO_H

#include <stack>
#include <iostream>
#include <array>
#include "Game.h"
#include "Hand.h"
#include "Player.h"
#include "Deck.h"
#include "UnoDeck.h"

class Uno : public Game {
 public:
  Uno();
  ~Uno();
  void setUp();
  void play();
  void sayUno(Player*);
  bool playCard(Player*);
  void pickUpCard(Player*);
  void pickUpMultipleCards(Player*, int);
  void cardFunction(Card::Action, Player*);
  bool checkValidPlay(Card*);
  int calcScore(Player*);
  Deck* getDeck();

 private:
  Deck* deck;
  bool winner = false;
  bool skipTurn = false;
  int pickUp = false;
  bool reverse = false;
  bool unoSaid = false;
  std::stack<Card*> discardPile;
  Card::Colour discardColour;
};
#endif
