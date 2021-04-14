#include <string>
#include <iostream>
#include "NormalDeck.h"
#include "CrazyEights.h"

CrazyEights::CrazyEights() {
  setUp();
  play();
}

void CrazyEights::setUp() {
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

void CrazyEights::play() {
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

Deck* CrazyEights::getDeck() {
  return deck;
}
