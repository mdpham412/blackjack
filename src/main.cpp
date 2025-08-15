#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "blackjack.hpp"

#define CLEARTERM "\033[2J\033[1;1H"

int main() {
  Blackjack game;
  game.deal(Blackjack::player1);
  game.deal(Blackjack::player1);
  game.deal(Blackjack::dealer);
  game.deal(Blackjack::dealer);
  while (true) {
    std::cout << CLEARTERM;
    std::cout << game;
    std::cin.ignore();
    game.deal(Blackjack::player1);
  }
}
