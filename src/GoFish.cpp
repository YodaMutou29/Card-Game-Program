/**
* @author Jenna McDonnell <jenna.mcdonnell@uleth.ca>
* @author David Neufeld <dj.neufeld@uleth.ca>
* @author Fairooz Afia Saiyara <fairoozafia.saiyara@uleth.ca>
* @author Julie Wojtiw-Quo <wojtiwquoj@uleth.ca>
* @date 2021-03
*/

#include <vector>
#include <iostream>
#include <string>
#include "GoFish.h"
#include "Player.h"
#include "Card.h"
#include "Game.h"
#include "Deck.h"
#include "NormalDeck.h"
#include "Book.h"

GoFish::GoFish() {
  currentGame = GOFISH;
  numBooks = 0;
  gameDeck = new Deck(currentGame);
  setUp();
  play();
}

void GoFish::setUp() {
  std::string name;
  std::string answer;
  deck = new NormalDeck();
  deck->shuffleDeck();
  while (answer != "no" && players.size() < 4) {
    std::cout << "Enter player name(s):" << std::endl;
    std::cin >> name;
    players.push_back(new Player(name));
    for (int i = 0; i < 7; i++) {
      players[players.size() - 1]->addCardCurrentHand(deck->getTopCard());
    }
    std::cout << "Do you want to add another player?" << std::endl;
    std::cin >> answer;
  }
}

void GoFish::play() {
  std::string ready;
  int act;
  bool winner = false;
  while (!winner) {
    for (int i = 0; i < players.size(); i++) {
      std::cout << players[i]->getName() << "'s turn" << std::endl;
      std::cout << "Enter any letter when ready." << std::endl;
      std::cin >> ready;
      std::cout << players[i]->getCurrentHand() << std::endl;
    }
  }
}

void GoFish::sayGoFish(Player* p) {
  playerTurn = p;
}

bool GoFish::askForCard(Player* p, Card* c) {
  playerTurn = p;
  return cardInHand(p, c);
}

void GoFish::giveCard(Player* p, Card* c) {
  for (int i = 0; i < playerTurn->getCurrentHand().getNumberOfCards(); i++) {
    if (playerTurn->getCurrentHand().getGameHand()[i]->getNumber()
        == c->getNumber()) {
      p->addCardCurrentHand(playerTurn->getCurrentHand().getGameHand()[i]);
      playerTurn->removeCardCurrentHand(i);
    }
  }
  p->getCurrentHand().checkForBooks();
  playerTurn = p;
}

std::vector<Book*> GoFish::getGoFishBooks(Player* p) {
  return p->getCurrentHand().getBooks();
}

void GoFish::dealHand() {
  for (Player* p : players) {
    if (numPlayers < 4) {
      for (int i = 0; i < 7; i++)
        p->addCardCurrentHand(pickUpCard());
    } else {
      for (int i = 0; i < 5; i++)
        p->addCardCurrentHand(pickUpCard());
    }
  }
}
