#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "blackjack.hpp"

#define CLEARTERM "\033[2J\033[1;1H"

int main() {
  Blackjack game;
  game.dealPlayer();
  game.dealPlayer();
  game.dealDealer();
  game.dealDealer();
  while (true) {
    std::cout << CLEARTERM;
    std::cout << game;
    std::cin.ignore();
    game.dealPlayer();
  }
}
