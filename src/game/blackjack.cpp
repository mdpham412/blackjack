#include "blackjack.hpp"
Blackjack::Blackjack() {
  m_deck.clear();
  m_deck = Deck();
  m_deck.shuffle();
}
void Blackjack::dealPlayer() {
  m_playersHand.push_back(m_deck.getTopCard());
  m_deck.removeTopCard();
}
void Blackjack::dealDealer() {
  m_dealersHand.push_back(m_deck.getTopCard());
  m_deck.removeTopCard();
}
int Blackjack::getHandValue() {
  int result{};
  int aces{};

  for (auto& card : m_playersHand) {
    switch (card.getRank()) {
      case Card::two:
        result += 2;
        break;
      case Card::three:
        result += 3;
        break;
      case Card::four:
        result += 4;
        break;
      case Card::five:
        result += 5;
        break;
      case Card::six:
        result += 6;
        break;
      case Card::seven:
        result += 7;
        break;
      case Card::eight:
        result += 8;
        break;
      case Card::nine:
        result += 9;
        break;
      case Card::ten:
        result += 10;
        break;
      case Card::jack:
        result += 10;
        break;
      case Card::queen:
        result += 10;
        break;
      case Card::king:
        result += 10;
        break;
    }
    if (card.getRank() == Card::ace) {
      aces++;
    }
  }
  if (aces > 0)
    while (aces--) {
      if (result + 11 > 21)
        result += 1;
      else
        result += 11;
    }
  return result;
}
