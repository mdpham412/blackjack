#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
#include <string>

class Card {
 public:
  enum Suits { uninitializedSuit, clubs, diamonds, hearts, spades, suitSize };
  enum Ranks {
    uninitializedRank,
    ace,
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king,
    rankSize
  };

 private:
  Suits m_suit{uninitializedSuit};
  Ranks m_rank{uninitializedRank};

 public:
  Card(Suits suit, Ranks rank) : m_suit{suit}, m_rank{rank} {}
  Suits getSuit() const { return m_suit; }
  Ranks getRank() const { return m_rank; }
};

std::string getName(const Card& card);
std::ostream& operator<<(std::ostream& stream, const Card& card);

#endif
