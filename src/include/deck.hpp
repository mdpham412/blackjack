#ifndef DECK_HPP
#define DECK_HPP
#include <vector>

#include "card.hpp"

class Deck {
 private:
  std::vector<Card> m_cards;

 public:
  Deck();
  void clear() { m_cards.clear(); }

  int size() { return m_cards.size(); }

  Card getTopCard() const { return m_cards.back(); }
  void removeTopCard() { m_cards.pop_back(); }

  static constexpr int shuffleCount{1000};
  void shuffle();
};
#endif
