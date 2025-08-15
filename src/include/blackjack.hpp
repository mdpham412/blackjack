#ifndef BLACKJACK_HPP
#define BLACKJACK_HPP
#include <cmath>
#include <iomanip>
#include <iostream>

#include "deck.hpp"
class Blackjack {
 private:
  Deck m_deck{};
  std::vector<Card> m_playersHand{};
  std::vector<Card> m_dealersHand{};

 public:
  Blackjack();
  void dealPlayer();
  void dealDealer();
  void dealPlayer(Card card);
  void dealDealer(Card card);
  std::vector<Card>& getPlayersHand() { return m_playersHand; }
  std::vector<Card>& getDealersHand() { return m_dealersHand; }
  int getPlayersHandValue();
  int getDealersHandValue();
  friend std::ostream& operator<<(std::ostream& stream, Blackjack& game);
};

#endif
