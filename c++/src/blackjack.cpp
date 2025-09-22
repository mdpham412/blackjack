#include "blackjack.hpp"
Blackjack::Blackjack() {
  m_deck.clear();
  m_deck = Deck();
  m_deck.shuffle();
  for (int i = 0; i < size; i++) {
    m_hands.push_back({});
    m_money.push_back(startingCash);
  }
  for (auto& player : m_hands) {
    player.clear();
  }
}
void Blackjack::deal(Players player) {
  m_hands[player].push_back(m_deck.getTopCard());
  m_deck.removeTopCard();
}

int Blackjack::handValue(Players player) {
  int result{};
  int aces{};

  for (auto& card : m_hands[player]) {
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
  int maxHandSize = std::max(game.m_hands[Blackjack::dealer].size(),
                             game.m_hands[Blackjack::player1].size());

  stream << std::setw(game.width) << "Player's hand:";
  stream << std::setw(game.width) << "Dealer's hand:\n";
  for (int i = 0; i < maxHandSize; i++) {
    if (i >= game.m_hands[Blackjack::player1].size()) {
      stream << std::setw(game.width) << "";
      stream << std::setw(game.width) << game.m_hands[Blackjack::dealer][i];
    } else if (i >= game.m_hands[Blackjack::dealer].size()) {
      stream << std::setw(game.width) << game.m_hands[Blackjack::player1][i];
      stream << std::setw(game.width) << "";
    } else {
      stream << std::setw(game.width) << game.m_hands[Blackjack::player1][i];
      stream << std::setw(game.width) << game.m_hands[Blackjack::dealer][i];
    }
    stream << '\n';
  }

  stream << std::setw(10) << "Value: ";
  stream << std::setw(game.width - 10) << game.handValue(Blackjack::player1);
  stream << std::setw(game.width) << game.handValue(Blackjack::dealer) << '\n';

  stream << std::setw(10) << "Money: ";
  stream << std::setw(game.width - 10) << game.money(Blackjack::player1);
  stream << std::setw(game.width) << "" << '\n';

  return stream;
}

void Blackjack::newRound() {
  m_deck.clear();
  m_deck = Deck();
  m_deck.shuffle();
  for (int i = 0; i < size; i++) {
    m_hands.push_back({});
  }
  for (auto& player : m_hands) {
    player.clear();
  }
}
