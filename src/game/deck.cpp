#include "deck.hpp"

#include "random.hpp"

// Deck initializer
Deck::Deck() {
  for (int suit = Card::uninitializedSuit + 1; suit < Card::suitSize; suit++) {
    for (int rank = Card::uninitializedRank + 1; rank < Card::rankSize;
         rank++) {
      m_cards.push_back({(Card::Suits)suit, (Card::Ranks)rank});
    }
  }
}

void Deck::shuffle() {
  for (int i = 1; i <= shuffleCount; i++) {
    std::swap(m_cards[getRandomCard()], m_cards[getRandomCard()]);
  }
}
