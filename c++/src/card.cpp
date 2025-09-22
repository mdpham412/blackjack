#include "card.hpp"

// Get the name of a card as an std::string
std::string getName(const Card& card) {
  std::string name{};
  switch (card.getRank()) {
    case Card::ace:
      name += "A";
      break;
    case Card::two:
      name += "2";
      break;
    case Card::three:
      name += "3";
      break;
    case Card::four:
      name += "4";
      break;
    case Card::five:
      name += "5";
      break;
    case Card::six:
      name += "6";
      break;
    case Card::seven:
      name += "7";
      break;
    case Card::eight:
      name += "8";
      break;
    case Card::nine:
      name += "9";
      break;
    case Card::ten:
      name += "10";
      break;
    case Card::jack:
      name += "J";
      break;
    case Card::queen:
      name += "Q";
      break;
    case Card::king:
      name += "K";
      break;
    case Card::uninitializedRank:
      return name;
  }
  switch (card.getSuit()) {
    case Card::clubs:
      name += " of Clubs";
      break;
    case Card::diamonds:
      name += " of Diamonds";
      break;
    case Card::hearts:
      name += " of Hearts";
      break;
    case Card::spades:
      name += " of Spades";
      break;
    default:
      return name;
  }
  return name;
}

// << operator overloading to make outputting card values easier
std::ostream& operator<<(std::ostream& stream, const Card& card) {
  stream << getName(card);
  return stream;
}
