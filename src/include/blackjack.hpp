#ifndef BLACKJACK_HPP
#define BLACKJACK_HPP
#include <cmath>
#include <iomanip>
#include <iostream>

#include "deck.hpp"
class Blackjack {
 public:
  enum Players { dealer, player1, size };

 private:
  Deck m_deck{};
  std::vector<std::vector<Card>> m_hands{};

 public:
  Blackjack();
  void deal(Players player);
  int handValue(Players player);
  std::vector<Card>& hand(int player) { return m_hands[player]; }
  friend std::ostream& operator<<(std::ostream& stream, Blackjack& game);
};

#endif
