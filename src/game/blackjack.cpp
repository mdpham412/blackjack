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
int Blackjack::getPlayersHandValue() {
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
int Blackjack::getDealersHandValue() {
  int result{};
  int aces{};

  for (auto& card : m_dealersHand) {
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
std::ostream& operator<<(std::ostream& stream, Blackjack& game) {
  constexpr int width{40};

  stream << std::setw(width) << "Player's hand:";
  stream << std::setw(width) << "Dealer's hand:\n";
  for (int i = 0;
       i < std::max(game.m_dealersHand.size(), game.m_playersHand.size());
       i++) {
    if (i >= game.m_playersHand.size()) {
      stream << std::setw(width) << "";
      stream << std::setw(width) << game.m_dealersHand[i];
    } else if (i >= game.m_dealersHand.size()) {
      stream << std::setw(width) << game.m_playersHand[i];
      stream << std::setw(width) << "";
    } else {
      stream << std::setw(width) << game.m_playersHand[i];
      stream << std::setw(width) << game.m_dealersHand[i];
    }
    stream << '\n';
  }
  stream << std::setw(10) << "Value: ";
  stream << std::setw(width - 10) << game.getPlayersHandValue()
         << std::setw(width) << game.getDealersHandValue() << '\n';
  return stream;
}
void Blackjack::dealPlayer(Card card) { m_playersHand.push_back(card); }
void Blackjack::dealDealer(Card card) { m_dealersHand.push_back(card); }
