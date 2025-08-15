#include <random>

int getRandomCard(int start = 0, int end = 51) {
  static std::random_device rd{};
  static std::seed_seq ss{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
  static std::mt19937 mt{ss};

  std::uniform_int_distribution card{start, end};
  return card(mt);
};
