/**
* @author Jenna McDonnell <jenna.mcdonnell@uleth.ca>
* @author David Neufeld <dj.neufeld@uleth.ca>
* @author Fairooz Afia Saiyara <fairoozafia.saiyara@uleth.ca>
* @author Julie Wojtiw-Quo <wojtiwquoj@uleth.ca>
* @date 2021-03
*/

#ifndef CARD_H
#define CARD_H

#include <iostream>
/**
* Gets the number of a card
*/
class Card {
 public:
   /**
   * The type of the suit cards in the game.
   */
  enum Suit {HEARTS, CLUBS, DIAMONDS, SPADES};
   /**
   * The type of the face cards in the game.
   */
  enum Face {NOFACE, JACK, QUEEN, KING, ACE};
   /**
   * The colours for the cards
   */
  enum Colour {RED, BLUE, YELLOW, GREEN, BLACK};

   /**
   * The different action cards
   */
  enum Action {NONE, REVERSE, PLUSTWO, SKIP, WILD, WILDPLUSFOUR};
  enum CardType {UNO, NORMAL};
  Card() {}
  Card(Suit, int, CardType);
  Card(Suit, Face, CardType);
  Card(Colour, int, CardType);
  Card(Colour, Action, CardType);
  ~Card() {}

/**
* Sets the number of a card
* @param integer value on the card
* @return an integer
*/
  void setNumber(int);

/**
* Gets the number of a card
*/
  int getNumber();

  Suit getSuit();

  Face getFace();
  /**
  * Get colour
  */
  Colour getColour();
  /**
  * Get action
  */
  Action getAction();

  CardType getCardType();

 private:
  int number;
  Suit suit;
  Face face = NOFACE;
  Colour colour;
  Action action = NONE;
  CardType type;
};
std::ostream& operator<< (std::ostream&, Card*);
#endif // CARD_H
