/**
* @author Jenna McDonnell <jenna.mcdonnell@uleth.ca>
* @author David Neufeld <dj.neufeld@uleth.ca>
* @author Fairooz Afia Saiyara <fairoozafia.saiyara@uleth.ca>
* @author Julie Wojtiw-Quo <wojtiwquoj@uleth.ca>
* @date 2021-03
*/

#ifndef GAME_H
#define GAME_H

// Header files

#include <string>
#include <vector>
#include "Player.h"
#include "Exceptions.h"

/**
* Interface for Game
*/
class Game {
 public:
  /**
  * The different games
  */
  enum CurrentGame {GOFISH, CRAZYEIGHTS, UNO};

  /**
  * Default constructor, sets initial values for the game
  */
  Game();

  Game(CurrentGame);

  /**
  * Destructor
  */
  virtual ~Game() {}

  /**
  * Returns the instructions for the game
  * @return a string containing game instructions
  */
  std::string getInstructions();

  /**
  * adds a new player to the game
  * @param name a string containing the name for the new player
  */
  void addPlayer(std::string name);

  /**
  * removes a player from the game
  * @param name a string containing the name of the player to be removed
  */
  void removePlayer(std::string name);

  /**
  * starts the game, the game is also run inside this function
  * @param gameNumber a int indicating the game being played
  */
  //void startGame(int gameNumber);

  Player* playerTurn;
  std::vector<Player*> players;
  int score;
  int numPlayers;

 protected:
  CurrentGame currentGame;

 private:
  std::string instructions;
};
#endif //GAME_H
