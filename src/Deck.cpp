/**
* @author Jenna McDonnell <jenna.mcdonnell@uleth.ca>
* @author David Neufeld <dj.neufeld@uleth.ca>
* @author Fairooz Afia Saiyara <fairoozafia.saiyara@uleth.ca>
* @author Julie Wojtiw-Quo <wojtiwquoj@uleth.ca>
* @date 2021-03
*/

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
#include "Deck.h"
#include "UnoDeck.h"
#include "NormalDeck.h"

Deck::Deck() {}

Deck::Deck(Game::CurrentGame g) {
  game = g;
  //buildDeck();
}

Deck::~Deck() {
  for (Card* c : currentDeck)
    delete c;
}

void Deck::shuffleDeck() {
  int n = currentDeck.size();
  for (int i = 0; i < n; i++) {
    srand(time(NULL));
    int r = i + (std::rand() % (n - i));
    Card* temp = currentDeck[r];
    currentDeck[r] = currentDeck[i];
    currentDeck[i] = temp;
  }
}

void Deck::setCurrentDeck(std::vector<Card*> d) {
  currentDeck = d;
}

std::vector<Card*> Deck::getCurrentDeck() {
  return currentDeck;
}

Game::CurrentGame Deck::getGame() {
  return game;
}

Card* Deck::getTopCard() {
  Card* temp = currentDeck[0];
  currentDeck.erase(currentDeck.begin());
  return temp;
}

int Deck::getNumberOfCards() {
  return numberOfCards;
}
/*
void Deck::setTopCard(Card* c) {
  topCard = c;
}
*/
void Deck::setNumberOfCards(int n) {
  numberOfCards = n;
}
