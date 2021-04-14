#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "Game.h"
#include "Player.h"
#include "Deck.h"
#include "Card.h"
#include "Uno.h"

Uno::Uno() {
  setUp();
  play();
}

Uno::~Uno() {
  delete deck;
}

void Uno::setUp() {
  std::string name;
  std::string answer;
  deck = new UnoDeck();
  deck->shuffleDeck();
  int j = 1;
  while (answer != "no" && players.size() < 4) {
    std::cout << "Enter player name(s):" << std::endl;
    std::cin >> name;
    players.push_back(new Player(name, j));
    j++;
    for (int i = 0; i < 7; i++) {
      players[players.size() - 1]->addCardCurrentHand(deck->getTopCard());
    }
    std::cout << "Do you want to add another player?" << std::endl;
    std::cin >> answer;
  }
  discardPile.push(deck->getTopCard());
}

void Uno::play() {
  std::string ready;
  int act;
  int turnCounter = 0;
  while (!winner) {
      if (skipTurn == true) {
        std::cout << "SKIP!" << std::endl;
        skipTurn = false;
        goto Reverse;
      } else if (pickUp > 0) {
        pickUpMultipleCards(players[turnCounter], pickUp);
        pickUp = 0;
        goto Reverse;
      }
      std::cout << "Discard pile: " << std::endl;
      std::cout << discardPile.top() << std::endl;
      std::cout << players[turnCounter]->getName() << "'s turn" << std::endl;
      std::cout << "Enter any letter when ready." << std::endl;
      std::cin >> ready;
      std::cout << players[turnCounter]->getCurrentHand() << std::endl;
    PickAction:
      std::cout << "Choose an action number:" << std::endl;
      std::cout << "  1. Play card" << std::endl;
      std::cout << "  2. Pick up card" << std::endl;
      std::cout << "  3. Say Uno" << std::endl;
      std::cin >> act;
      if (act == 1) {
        if (playCard(players[turnCounter]) == false) {
          goto PickAction;
        }
      } else if (act == 2) {
        pickUpCard(players[turnCounter]);
      } else {
        sayUno(players[turnCounter]);
      }
    Reverse:
      if (reverse == true) {
        if (turnCounter == 0) {
          turnCounter = players.size() - 1;
        } else {
          turnCounter--;
        }
      } else {
        if (turnCounter == players.size() - 1) {
          turnCounter = 0;
        } else {
          turnCounter++;
        }
      }
  }
}

bool Uno::playCard(Player* p) {
  int cardNumber;
  std::cout << "Which card do you want to play?" << std::endl;
  std::cout << "(options are: ";
  for (int i = 1; i <= ((p->getCurrentHand()).getGameHand()).size(); i++) {
    std::cout << i << " ";
  }
  std::cout << ")" << std::endl;
  std::cin >> cardNumber;
  if (cardNumber > ((p->getCurrentHand()).getGameHand()).size() ||
  cardNumber < 0) {
    std::cout << "Card number " << cardNumber << " does not exist" << std::endl;
    return false;
  }
  if (checkValidPlay(((p->getCurrentHand()).getGameHand())[cardNumber - 1])) {
    if ((((p->getCurrentHand()).getGameHand())[cardNumber - 1])->
      getAction() != Card::NONE) {
        cardFunction((((p->getCurrentHand()).getGameHand())
        [cardNumber - 1])->getAction(), p);
    }
    discardPile.push(((p->getCurrentHand()).getGameHand())[cardNumber - 1]);
    p->removeCardCurrentHand(cardNumber - 1);
    if (((p->getCurrentHand()).getGameHand()).size() == 0) {
      winner = true;
      std::cout << p->getName() << " is the winner!" << std::endl;
      std::cout << "Final scores: " << std::endl;
      for (int s = 0; s < players.size(); s++) {
        std::cout << players[s]->getName() << ": " << calcScore(players[s]) <<
        " ";
      }
      std::cout << std::endl;
    } else if (((p->getCurrentHand()).getGameHand()).size() == 1) {
      if (!unoSaid) {
        std::cout << "You must say UNO before playing the second last card!" <<
        std::endl;
        std::cout << "Pick up two cards." << std::endl;
        pickUpMultipleCards(players[p->getPlayerNumber() - 1], 2);
      } else {
        unoSaid == false;
      }
    }
  } else {
    std::cout << "You cannot play that card." << std::endl;
    return false;
  }
  return true;
}

void Uno::sayUno(Player* p) {
  std::cout << p->getName() << " yells UNO!" << std::endl;
  unoSaid = true;
  playCard(p);
}

void Uno::pickUpCard(Player* p) {
  std::string answer;
  std::cout << "Picking up card" << std::endl;
  p->addCardCurrentHand(deck->getTopCard());
  std::cout << "Deck is now:" << std::endl;
  std::cout << p->getCurrentHand() << std::endl;
  std::cout << "Play a card?" << std::endl;
  std::cin >> answer;
  if (answer == "yes") {
    playCard(p);
  } else {}
}

void Uno::pickUpMultipleCards(Player* p, int numCards) {
  std::cout << p->getName() << "picks up " << numCards << " cards." <<
  std::endl;
  for (int i = 0; i < numCards; i++) {
    p->addCardCurrentHand(deck->getTopCard());
  }
  std::cout << "Hand is now:" << std::endl;
  std::cout << p->getCurrentHand() << std::endl;
}

void Uno::cardFunction(Card::Action act, Player* p) {
  int playerPunished;
  if (p->getPlayerNumber() == players.size()) {
    playerPunished = 0;
  } else {
    playerPunished = p->getPlayerNumber();
  }
  if (act == Card::WILD || act == Card::WILDPLUSFOUR) {
    std::string colour;
    std::cout << "Pick a colour: " << std::endl;
    std::cout << "  1. blue" << std::endl;
    std::cout << "  2. red" << std::endl;
    std::cout << "  3. yellow" << std::endl;
    std::cout << "  4. green" << std::endl;
    std::cin >> colour;

    if (colour == "blue" || colour == "1") {
      std::cout << "The colour is now blue." << std::endl;
      discardColour = Card::BLUE;
    } else if (colour == "red" || colour == "2") {
      std::cout << "The colour is now red." << std::endl;
      discardColour = Card::RED;
    } else if (colour == "yellow" || colour == "3") {
      std::cout << "The colour is now yellow." << std::endl;
      discardColour = Card::YELLOW;
    } else {
      std::cout << "The colour is now green." << std::endl;
      discardColour = Card::GREEN;
    }
    if (act == Card::WILDPLUSFOUR) {
      pickUp = 4;
    }
  } else if (act == Card::REVERSE) {
    std::cout << "Play order has been reversed!" << std::endl;
    if (reverse == true) {
      reverse = false;
    } else {
      reverse = true;
    }
  } else if (act == Card::SKIP) {
    skipTurn = true;
  } else {
    pickUp = 2;
  }
}

bool Uno::checkValidPlay(Card* c) {
  if (c->getColour() == (discardPile.top())->getColour()) {
    return true;
  } else if (discardColour == c->getColour()) {
      discardColour = Card::BLACK;
      return true;
  } else if (c->getAction() == Card::WILD || c->getAction() ==
    Card::WILDPLUSFOUR) {
      return true;
  } else if (c->getAction() != Card::NONE) {
      if (c->getAction() == (discardPile.top())->getAction()) {
        return true;
      }
  } else if (c->getNumber() == (discardPile.top())->getNumber()) {
      return true;
  } else {
    return false;
  }
  return false;
}

int Uno::calcScore(Player* p) {
  int score = 0;
  if (((p->getCurrentHand()).getGameHand()).size() == 0) {
    return 0;
  }
  for (int i = 0; i < ((p->getCurrentHand()).getGameHand()).size(); i++) {
    if (((p->getCurrentHand()).getGameHand())[i]->getAction() != Card::NONE) {
      if (((p->getCurrentHand()).getGameHand())[i]->getAction() == Card::WILD ||
      ((p->getCurrentHand()).getGameHand())[i]->getAction() ==
      Card::WILDPLUSFOUR) {
        score += 50;
      } else {
        score += 20;
      }
    } else {
      score += ((p->getCurrentHand()).getGameHand())[i]->getNumber();
    }
  }
  return score;
}

Deck* Uno::getDeck() {
  return deck;
}
