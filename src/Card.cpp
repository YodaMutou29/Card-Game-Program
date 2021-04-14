#include <iostream>
#include "Card.h"

Card::Card(Suit s, int num, CardType t) {
  suit = s;
  number = num;
  type = t;
}

Card::Card(Suit s, Face f, CardType t) {
  suit = s;
  face = f;
  type = t;
}

Card::Card(Colour c, int num, CardType t) {
  colour = c;
  number = num;
  type = t;
}

Card::Card(Colour c, Action a, CardType t) {
  colour = c;
  action = a;
  type = t;
}


void Card::setNumber(int n) {
  number = n;
}

int Card::getNumber() {
  return number;
}

Card::Suit Card::getSuit() {
  return suit;
}

Card::Face Card::getFace() {
  return face;
}

Card::Colour Card::getColour() {
  return colour;
}

Card::Action Card::getAction() {
  return action;
}

Card::CardType Card::getCardType() {
  return type;
}

std::ostream& operator<< (std::ostream& out, Card* c) {
  out << "+----------+" << std::endl;
  out << "|          |" << std::endl;
  out << "|          |" << std::endl;
  if (c->getCardType() == Card::UNO) {
    if (c->getColour() == Card::BLACK) {
      out << "|  black   |" << std::endl;
    } else if (c->getColour() == Card::BLUE) {
      out << "|   blue   |" << std::endl;
    } else if (c->getColour() == Card::YELLOW) {
      out << "|  yellow  |" << std::endl;
    } else if (c->getColour() == Card::GREEN) {
      out << "|  green   |" << std::endl;
    } else {
      out << "|   red    |" << std::endl;
    }
    if (c->getAction() != Card::NONE) {
      if (c->getAction() == Card::REVERSE) {
        out << "| reverse  |" << std::endl;
      } else if (c->getAction() == Card::SKIP) {
        out << "|   skip   |" << std::endl;
      } else if (c->getAction() == Card::PLUSTWO) {
        out << "|    +2    |" << std::endl;
      } else if (c->getAction() == Card::WILD) {
        out << "|   wild   |" << std::endl;
      } else {
        out << "| wild +4  |" << std::endl;
      }
    } else {
      if (c->getNumber() == 10) {
        out << "|    " << c->getNumber() << "    |" << std::endl;
      } else {
        out << "|    " << c->getNumber() << "     |" << std::endl;
      }
    }
  } else {
    if (c->getSuit() == Card::HEARTS) {
      out << "|  hearts  |" << std::endl;
    } else if (c->getSuit() == Card::DIAMONDS) {
      out << "| diamonds |" << std::endl;
    } else if (c->getSuit() == Card::SPADES) {
      out << "|  spades  |" << std::endl;
    } else {
      out << "|  clubs   |" << std::endl;
    }
    if (c->getFace() != Card::NOFACE) {
      if (c->getFace() == Card::ACE) {
        out << "|   ace    |" << std::endl;
      } else if (c->getFace() == Card::JACK) {
        out << "|   jack   |" << std::endl;
      } else if (c->getFace() == Card::QUEEN) {
        out << "|  queen   |" << std::endl;
      } else {
        out << "|   king   |" << std::endl;
      }
    } else {
      if (c->getNumber() == 10) {
        out << "|    " << c->getNumber() << "    |" << std::endl;
      } else {
        out << "|    " << c->getNumber() << "     |" << std::endl;
      }
    }
  }
  out << "|          |" << std::endl;
  out << "|          |" << std::endl;
  out << "+----------+" << std::endl;
  return out;
}
