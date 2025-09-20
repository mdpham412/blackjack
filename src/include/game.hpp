#ifndef GAME_HPP
#define GAME_HPP
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "blackjack.hpp"

#define CLEARTERM "\033[2J\033[1;1H"

class Game {
 private:
  Blackjack blackjack{};
  int width{};
  int bet{};

 public:
  Game(const int w = 40) : width{w} { blackjack.width = width; }
  void loop();
  void end();

 private:
  void printState();
  bool playerHit();
  void playerStay();
  void start();
  bool action();
};
#endif
