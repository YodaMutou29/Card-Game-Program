/**
* @author Jenna McDonnell <jenna.mcdonnell@uleth.ca>
* @author David Neufeld <dj.neufeld@uleth.ca>
* @author Fairooz Afia Saiyara <fairoozafia.saiyara@uleth.ca>
* @author Julie Wojtiw-Quo <wojtiwquoj@uleth.ca>
* @date 2021-03
*/

#include <vector>
#include "Card.h"
#include "Hand.h"

Hand::Hand() {
  numberOfCards = 0;
}

void Hand::addCard(Card* c) {
  gameHand.push_back(c);
}

void Hand::removeCard(int cardNumber) {
  /*
  int initialNumberOfCards = numberOfCards;
  for (int i = 0; i < numberOfCards; i++) {
    if (gameHand[i] == c)
  */
      gameHand.erase(gameHand.begin() + cardNumber);
  //}
  /*
  if (initialNumberOfCards == numberOfCards) {
    throw invalid_card_error
    ("Card does not exist in Hand & could not be removed");
  }
  */
}

int Hand::getNumberOfCards() {
  return numberOfCards;
}

std::vector<Book*> Hand::getBooks() {
  return books;
}

bool Hand::checkForCard(Card* c) {
  for (int i = 0; i < numberOfCards; i++) {
    if (gameHand[i] == c)
      return true;
  }
  return false;
}

bool Hand::checkForBooks() {
  return true;
}

std::vector<Card*> Hand::getGameHand() {
  return gameHand;
}

std::ostream& operator<< (std::ostream& out, Hand h) {
  for (int j = 0; j <= ((h.getGameHand()).size() / 7); j++) {
    int maxLength;
    (j == ((h.getGameHand()).size() / 7)) ?
      maxLength = ((h.getGameHand()).size() % 7) : maxLength = 7;
      if (((h.getGameHand()).size() % 7) == 0 &&
        j == ((h.getGameHand()).size() / 7)) {
          maxLength = 0;
        }
    for (int i = 0 + (7 * j); i < maxLength + (7 * j); i++) {
      out << "+----------+     ";
    }
    out << std::endl;
    for (int i = 0 + (7 * j); i < maxLength + (7 * j); i++) {
      out << "|          |     ";
    }
    out << std::endl;
    for (int i = 0 + (7 * j); i < maxLength + (7 * j); i++) {
      out << "|          |     ";
    }
    out << std::endl;
    if (((h.getGameHand())[0])->getCardType() == Card::UNO) {
      for (int i = 0 + (7 * j); i < maxLength+ (7 * j); i++) {
        if ((h.getGameHand())[i]->getColour() == Card::BLACK) {
          out << "|  black   |     ";
        } else if ((h.getGameHand())[i]->getColour() == Card::BLUE) {
          out << "|   blue   |     ";
        } else if ((h.getGameHand())[i]->getColour() == Card::YELLOW) {
          out << "|  yellow  |     ";
        } else if ((h.getGameHand())[i]->getColour() == Card::GREEN) {
          out << "|  green   |     ";
        } else {
          out << "|   red    |     ";
        }
      }
      out << std::endl;
      for (int i = 0 + (7 * j); i < maxLength+ (7 * j); i++) {
        if ((h.getGameHand())[i]->getAction() != Card::NONE) {
          if ((h.getGameHand())[i]->getAction() == Card::REVERSE) {
            out << "| reverse  |     ";
          } else if ((h.getGameHand())[i]->getAction() == Card::SKIP) {
            out << "|   skip   |     ";
          } else if ((h.getGameHand())[i]->getAction() == Card::PLUSTWO) {
            out << "|    +2    |     ";
          } else if ((h.getGameHand())[i]->getAction() == Card::WILD) {
            out << "|   wild   |     ";
          } else {
            out << "| wild +4  |     ";
          }
        } else {
          if ((h.getGameHand())[i]->getNumber() == 10) {
            out << "|    " << (h.getGameHand())[i]->getNumber() <<
              "    |     ";
          } else {
            out << "|    " << (h.getGameHand())[i]->getNumber() <<
              "     |     ";
          }
        }
      }
    } else {
      for (int i = 0 + (7 * j); i < maxLength+ (7 * j); i++) {
        if ((h.getGameHand())[i]->getSuit() == Card::HEARTS) {
          out << "|  hearts  |     ";
        } else if ((h.getGameHand())[i]->getSuit() == Card::DIAMONDS) {
          out << "| diamonds |     ";
        } else if ((h.getGameHand())[i]->getSuit() == Card::SPADES) {
          out << "|  spades  |     ";
        } else {
          out << "|  clubs   |     ";
        }
      }
      out << std::endl;
      for (int i = 0 + (7 * j); i < maxLength+ (7 * j); i++) {
        if ((h.getGameHand())[i]->getFace() != Card::NOFACE) {
          if ((h.getGameHand())[i]->getFace() == Card::ACE) {
            out << "|   ace    |     ";
          } else if ((h.getGameHand())[i]->getFace() == Card::JACK) {
            out << "|   jack   |     ";
          } else if ((h.getGameHand())[i]->getFace() == Card::QUEEN) {
            out << "|  queen   |     ";
          } else {
            out << "|   king   |     ";
          }
        } else {
          if ((h.getGameHand())[i]->getNumber() == 10) {
            out << "|    " << (h.getGameHand())[i]->getNumber() <<
              "    |     ";
          } else {
            out << "|    " << (h.getGameHand())[i]->getNumber() <<
              "     |     ";
          }
        }
      }
    }
    out << std::endl;
    for (int i = 0 + (7 * j); i < maxLength+ (7 * j); i++) {
      out << "|          |     ";
    }
    out << std::endl;
    for (int i = 0 + (7 * j); i < maxLength+ (7 * j); i++) {
      out << "|          |     ";
    }
    out << std::endl;
    for (int i = 0 + (7 * j); i < maxLength+ (7 * j); i++) {
      out << "+----------+     ";
    }
    out << std::endl;
  }
  return out;
}
