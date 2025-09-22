#ifndef BLACKJACK_HPP
#define BLACKJACK_HPP
#include <cmath>
#include <iomanip>
#include <iostream>

#include "deck.hpp"

constexpr int startingCash = 5000;

class Blackjack {
 public:
  enum Players { dealer, player1, size };

 private:
  Deck m_deck{};
  std::vector<std::vector<Card>> m_hands{};
  std::vector<int> m_money{};

 public:
  int width{};
  Blackjack();
  void newRound();
  void deal(Players player);
  int handValue(Players player);
  std::vector<Card>& hand(int player) { return m_hands[player]; }
  friend std::ostream& operator<<(std::ostream& stream, Blackjack& game);
  int money(Players player) { return m_money[player]; }
  void changeMoney(Players player, int value) { m_money[player] = value; }
};

#endif
