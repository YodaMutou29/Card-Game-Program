/**
* @author Jenna McDonnell <jenna.mcdonnell@uleth.ca>
* @author David Neufeld <dj.neufeld@uleth.ca>
* @author Fairooz Afia Saiyara <fairoozafia.saiyara@uleth.ca>
* @author Julie Wojtiw-Quo <wojtiwquoj@uleth.ca>
* @date 2021-03
*/

#include "gtest/gtest.h"
#include "Game.h"
/*
TEST(TestGoFish, DISABLED_defaultConstructor) {
  GoFish game;

  EXPECT_EQ(0, game.numPlayers);
  EXPECT_EQ(0, game.score);
  EXPECT_EQ(GOFISH, game.currentGame);
  EXPECT_EQ(CHANGEME, game.instructions);
}

TEST(TestGoFish, DISABLED_getInstructions) {
  GoFish game;

  EXPECT_EQ(game.instructions, game.getInstructions());
}

TEST(TestGoFish, DISABLED_addPlayer) {
  GoFish game;
  std::string name1 = "John";
  std::string name2 = "George";
  std::string name3 = "Mary";
  game.addPlayer(name1);
  game.addPlayer(name2);
  game.addPlayer(name3);

  EXPECT_EQ(3, game.players.size());
  EXPECT_EQ(3, game.numPlayers);
  EXPECT_EQ(name1, game.players[0]);
  EXPECT_EQ(name2, game.players[1]);
  EXPECT_EQ(name3, game.players[2]);
  EXPECT_NO_THROW(game.addPlayer("Sarah"));
  EXPECT_THROW(game.addPlayer(name1), invalid_name_error);

  std::string name4 = "123456789012345678901"

  EXPECT_THROW(game.addPlayer(name4), invalid_name_error);

  game.numPlayers = 5;

  EXPECT_THROW(game.addPlayer("Steve"), game_limit_error);
}

TEST(TestGoFish, DISABLED_removePlayer) {
  GoFish game;

  EXPECT_THROW(game.removePlayer("Ethan"), game_limit_error);

  std::string name1 = "John";
  std::string name2 = "George";
  std::string name3 = "Mary";
  game.addPlayer(name1);
  game.addPlayer(name2);
  game.addPlayer(name3);
  game.removePlayer(name2);

  EXPECT_EQ(2, game.players.size());
  EXPECT_EQ(2, game.numPlayers);
  EXPECT_THROW(game.removePlayer(name2), invalid_name_error);

  game.removePlayer(name1);
  game.removePlayer(name3);

  EXPECT_EQ(0, game.players.size());
  EXPECT_EQ(0, game.players.size());
}

TEST(TestGoFish, DISABLED_startGame) {

}

TEST(TestGoFish, DISABLED_pickUpCard) {

}

TEST(TestGoFish, DISABLED_cardInHand){

}

TEST(TestGoFish, DISABLED_sayGoFish) {

}

TEST(TestGoFish, DISABLED_askForCard) {

}

TEST(TestGoFish, DISABLED_giveCard) {

}

TEST(TestGoFish, DISABLED_getBooks) {

}
*/
