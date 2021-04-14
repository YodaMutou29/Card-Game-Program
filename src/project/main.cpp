#include <iostream>
#include <string>
#include "Game.h"
#include "GoFish.h"
#include "CrazyEights.h"
#include "Uno.h"

int main() {
  bool keepPlaying = true;
  std::string answer;
  while (keepPlaying == true) {
    std::cout << "Please pick a game number: " << std:: endl;
    std::cout << "  1. Go Fish" << std:: endl;
    std::cout << "  2. Crazy Eights" << std::endl;
    std::cout << "  3. Uno" << std::endl;
    int n;
    std::cin >> n;
    Game* game;
    if (n == 1) {
      game = new GoFish();
    } else if (n == 2) {
      game = new CrazyEights();
    } else {
      game = new Uno();
    }
    std::cout << "Do you want to play another game?" << std::endl;
    std::cin >> answer;
    if (answer == "no" || answer == "No" || answer == "n") {
      keepPlaying = false;
    }
  }
  std::cout << "Thanks for playing!" << std::endl;
  return 0;
}
