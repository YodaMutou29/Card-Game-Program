/**
* @author Jenna McDonnell <jenna.mcdonnell@uleth.ca>
* @author David Neufeld <dj.neufeld@uleth.ca>
* @author Fairooz Afia Saiyara <fairoozafia.saiyara@uleth.ca>
* @author Julie Wojtiw-Quo <wojtiwquoj@uleth.ca>
* @date 2021-03
*/

#include "GoFishHand.h"
#include <vector>

void GoFishHand::checkForBooks() {
  int cardCount = 0;
  for (int i = 2; i < 10; i++) {
    for (int j = 0; j < gameHand.size(); j++) {
      if (gameHand[j]->getFace() == Card::NOFACE) {
        if (gameHand[j]->getNumber() == i)
          cardCount++;
        }
    }
    if (cardCount == 4) {
      for (int j = 0; j < gameHand.size(); j++) {
        if (gameHand[j]->getFace() == Card::NOFACE) {
          if (gameHand[j]->getNumber() == i)
            removeCard(j);
        }
      }
      books.push_back(i);
    }
    cardCount = 0;
  }
  for (int i = 0; i < gameHand.size(); i++) {
    if (gameHand[i]->getFace() == Card::JACK)
      cardCount++;
  }
  if (cardCount == 4) {
    for (int i = 0; i < gameHand.size(); i++) {
      if (gameHand[i]->getFace() == Card::JACK)
        removeCard(i);
    }
    books.push_back('J');
  }
  cardCount = 0;
  for (int i = 0; i < gameHand.size(); i++) {
    if (gameHand[i]->getFace() == Card::QUEEN)
      cardCount++;
  }
  if (cardCount == 4) {
    for (int i = 0; i < gameHand.size(); i++) {
      if (gameHand[i]->getFace() == Card::QUEEN)
        removeCard(i);
    }
    books.push_back('Q');
  }
  cardCount = 0;
  for (int i = 0; i < gameHand.size(); i++) {
    if (gameHand[i]->getFace() == Card::KING)
      cardCount++;
  }
  if (cardCount == 4) {
    for (int i = 0; i < gameHand.size(); i++) {
      if (gameHand[i]->getFace() == Card::KING)
        removeCard(i);
    }
    books.push_back('K');
  }
  cardCount = 0;
  for (int i = 0; i < gameHand.size(); i++) {
    if (gameHand[i]->getFace() == Card::ACE)
      cardCount++;
  }
  if (cardCount == 4) {
    for (int i = 0; i < gameHand.size(); i++) {
      if (gameHand[i]->getFace() == Card::ACE)
        removeCard(i);
    }
    books.push_back('A');
  }
}

std::vector<char> GoFishHand::getBooks() {
  return books;
}
