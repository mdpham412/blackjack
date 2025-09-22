#include "game.hpp"

constexpr int gameWidth{40};

int main() {
  Game game(gameWidth);
  game.loop();
  game.end();
  return 0;
}
