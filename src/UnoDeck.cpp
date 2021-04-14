#include "UnoDeck.h"
#include <vector>

UnoDeck::UnoDeck() {
  setCurrentDeck(buildUnoDeck());
}

UnoDeck::~UnoDeck() {
  //for (Card* c : deck)
    //delete c;
}

std::vector<Card*> UnoDeck::buildUnoDeck() {
  std::vector<Card*> d;
  for (int i = 0; i < 10; i++) {
    if (i == 0) {
      d.push_back(new Card(Card::RED, 0, Card::UNO));
      d.push_back(new Card(Card::BLUE, 0, Card::UNO));
      d.push_back(new Card(Card::YELLOW, 0, Card::UNO));
      d.push_back(new Card(Card::GREEN, 0, Card::UNO));
    } else {
      for (int j = 0; j < 2; j++) {
        d.push_back(new Card(Card::RED, i, Card::UNO));
        d.push_back(new Card(Card::BLUE, i, Card::UNO));
        d.push_back(new Card(Card::YELLOW, i, Card::UNO));
        d.push_back(new Card(Card::GREEN, i, Card::UNO));
      }
    }
  }
  for (int i = 0; i < 2; i++) {
    d.push_back(new Card(Card::RED, Card::REVERSE, Card::UNO));
    d.push_back(new Card(Card::BLUE, Card::REVERSE, Card::UNO));
    d.push_back(new Card(Card::YELLOW, Card::REVERSE, Card::UNO));
    d.push_back(new Card(Card::GREEN, Card::REVERSE, Card::UNO));
    d.push_back(new Card(Card::RED, Card::PLUSTWO, Card::UNO));
    d.push_back(new Card(Card::BLUE, Card::PLUSTWO, Card::UNO));
    d.push_back(new Card(Card::YELLOW, Card::PLUSTWO, Card::UNO));
    d.push_back(new Card(Card::GREEN, Card::PLUSTWO, Card::UNO));
    d.push_back(new Card(Card::RED, Card::SKIP, Card::UNO));
    d.push_back(new Card(Card::BLUE, Card::SKIP, Card::UNO));
    d.push_back(new Card(Card::YELLOW, Card::SKIP, Card::UNO));
    d.push_back(new Card(Card::GREEN, Card::SKIP, Card::UNO));
  }
  for (int i = 0; i < 4; i++) {
    d.push_back(new Card(Card::BLACK, Card::WILD, Card::UNO));
    d.push_back(new Card(Card::BLACK, Card::WILDPLUSFOUR, Card::UNO));
  }
  return d;
}
