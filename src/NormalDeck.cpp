#include "NormalDeck.h"
#include <vector>

NormalDeck::NormalDeck() {
  setCurrentDeck(buildNormalDeck());
}

NormalDeck::~NormalDeck() {
  //for (Card* c : deck)
    //delete c;
}

std::vector<Card*> NormalDeck::buildNormalDeck() {
  std::vector<Card*> d;
  for (int i = 2; i < 11; i++) {
    d.push_back(new Card(Card::HEARTS, i, Card::NORMAL));
    d.push_back(new Card(Card::CLUBS, i, Card::NORMAL));
    d.push_back(new Card(Card::DIAMONDS, i, Card::NORMAL));
    d.push_back(new Card(Card::SPADES, i, Card::NORMAL));
  }
  d.push_back(new Card(Card::HEARTS, Card::JACK, Card::NORMAL));
  d.push_back(new Card(Card::CLUBS, Card::JACK, Card::NORMAL));
  d.push_back(new Card(Card::DIAMONDS, Card::JACK, Card::NORMAL));
  d.push_back(new Card(Card::SPADES, Card::JACK, Card::NORMAL));
  d.push_back(new Card(Card::HEARTS, Card::QUEEN, Card::NORMAL));
  d.push_back(new Card(Card::CLUBS, Card::QUEEN, Card::NORMAL));
  d.push_back(new Card(Card::DIAMONDS, Card::QUEEN, Card::NORMAL));
  d.push_back(new Card(Card::SPADES, Card::QUEEN, Card::NORMAL));
  d.push_back(new Card(Card::HEARTS, Card::KING, Card::NORMAL));
  d.push_back(new Card(Card::CLUBS, Card::KING, Card::NORMAL));
  d.push_back(new Card(Card::DIAMONDS, Card::KING, Card::NORMAL));
  d.push_back(new Card(Card::SPADES, Card::KING, Card::NORMAL));
  d.push_back(new Card(Card::HEARTS, Card::ACE, Card::NORMAL));
  d.push_back(new Card(Card::CLUBS, Card::ACE, Card::NORMAL));
  d.push_back(new Card(Card::DIAMONDS, Card::ACE, Card::NORMAL));
  d.push_back(new Card(Card::SPADES, Card::ACE, Card::NORMAL));
  return d;
}
