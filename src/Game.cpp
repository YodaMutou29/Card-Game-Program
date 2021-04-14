/**
* @author Jenna McDonnell <jenna.mcdonnell@uleth.ca>
* @author David Neufeld <dj.neufeld@uleth.ca>
* @author Fairooz Afia Saiyara <fairoozafia.saiyara@uleth.ca>
* @author Julie Wojtiw-Quo <wojtiwquoj@uleth.ca>
* @date 2021-03
*/

#include "Game.h"
#include <string>
#include <iostream>

Game::Game() {
  score = 0;
  numPlayers = 0;
}

Game::Game(Game::CurrentGame g) {
  currentGame = g;
  score = 0;
  numPlayers = 0;
}

std::string Game::getInstructions() {
  return instructions;
}

void Game::addPlayer(std::string name) {
  if (numPlayers >= 5)
    throw game_limit_error("The max number of players (5) are already in game");
  for (int i = 0; i < numPlayers; i++) {
    if (players[i]->getName() == name)
      throw invalid_name_error("Name is already taken by another player");
  }
  if (name.size() > 20)
    throw invalid_name_error("Name cannot be longer than 20 characters");
  Player* newPlayer = new Player(name);
  players.push_back(newPlayer);
  numPlayers++;
}

void Game::removePlayer(std::string name) {
  if (numPlayers <= 0)
    throw game_limit_error("There are no players to remove");
  int initialNumPlayers = numPlayers;
  for (int i = 0; i < numPlayers; i++) {
    if (players[i]->getName() == name) {
      players.erase(players.begin() + i);
      numPlayers--;
    }
  }
  if (initialNumPlayers == numPlayers)
    throw invalid_name_error("Player does not exist & could not be removed");
}
