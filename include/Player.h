/**
* @author Jenna McDonnell <jenna.mcdonnell@uleth.ca>
* @author David Neufeld <dj.neufeld@uleth.ca>
* @author Fairooz Afia Saiyara <fairoozafia.saiyara@uleth.ca>
* @author Julie Wojtiw-Quo <wojtiwquoj@uleth.ca>
* @date 2021-03
*/

#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

//#include "Game.h"
#include <string>
#include "Hand.h"

/**
* A class to implement player information.
*/
class Player {
 public:
  /**
  * Default constructor, defualt name is "Jill".
  * @param name the name of the player.
  */
  Player(std::string name = "Jill", int number = 1);

  /**
  * Destructor
  */
  virtual ~Player();

  /**
  * Change the name of the player to the inputted string.
  * @param newName the new name of the player.
  */
  void changeName(std::string newName);

  /**
  * returns the player's name
  * @return a string representing the player's name
  */
  std::string getName();

  int getPlayerNumber();

  /**
  * returns the currentHand
  * @return the currentHand
  */
  Hand getCurrentHand();

  /**
  * adds a card to the player's hand
  * @param c a Card* which is to be added to the player's hand
  */
  void addCardCurrentHand(Card* c);

  /**
  * removes a card to the player's hand
  * @param c a Card* which is to be removed from the player's hand
  */
  void removeCardCurrentHand(int);

 protected:
  int playerNumber;
  Hand currentHand;
  int points;

 private:
   /**
   * Checks whether the inputted name only contains spaces. If so,
   * returns a true value.
   * @param newName the new name of the player.
   */
  bool onlySpaces(std::string newName);
  std::string name;
};

#endif //PLAYER_H_INCLUDED
