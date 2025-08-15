#include <iostream>
#include <vector>

#include "blackjack.hpp"

int main() {
  Blackjack game;
  game.dealPlayer();
  game.dealPlayer();
  for (auto& card : game.getPlayersHand()) {
    std::cout << card << '\n';
  }
  std::cout << game.getHandValue();
}
