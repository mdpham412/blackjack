#ifndef BLACKJACK_HPP
#define BLACKJACK_HPP
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
  std::vector<Card>& getPlayersHand() { return m_playersHand; }
  std::vector<Card>& getDeakersHand() { return m_dealersHand; }
  int getHandValue();
};

#endif
