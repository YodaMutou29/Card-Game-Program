/**
* @author Jenna McDonnell <jenna.mcdonnell@uleth.ca>
* @author David Neufeld <dj.neufeld@uleth.ca>
* @author Fairooz Afia Saiyara <fairoozafia.saiyara@uleth.ca>
* @author Julie Wojtiw-Quo <wojtiwquoj@uleth.ca>
* @date 2021-03
*/

#include <string>
#include "Player.h"
//#include "Game.h"
//#include "Hand.h"
//#include "Exceptions.h"

Player::Player(std::string name, int number) : name{name} {
  playerNumber = number;
}

Player::~Player() {}

void Player::changeName(std::string newName) {
/*
  try {
    if(name == newName) {
      throw (1);
    }
    else if((newName == "") || (onlySpaces == 1)) {
      throw (2);
    }
    else {
    */
      name == newName;
      /*
    }
  }
  catch(int 1) {
    throw invalid_name_error("Name changed to same string.");
    std::cout << "Name is already set to " << newName << endl;
  }
  catch(int 2) {
    throw invalid_name_error("Name set to blank string.");
    std::cout << "Name cannot be set to nothing!" << endl;
  }
  */
}

std::string Player::getName() {
  return name;
}

int Player::getPlayerNumber() {
  return playerNumber;
}

bool Player::onlySpaces(std::string newName) {
  std::size_t found = newName.find_last_not_of(" \t\f\v\n\r");
  if (found != std::string::npos) {
    return false;
  } else {
    return true;
  }
}

Hand Player::getCurrentHand() {
  return currentHand;
}

void Player::addCardCurrentHand(Card* c) {
  currentHand.addCard(c);
}

void Player::removeCardCurrentHand(int cardNumber) {
  currentHand.removeCard(cardNumber);
}
