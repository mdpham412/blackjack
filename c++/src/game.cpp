#include "game.hpp"
void Game::printState() {
  std::cout << CLEARTERM << blackjack << std::setw(10)
            << "Bet: " << std::setw(width - 10) << bet << '\n';
}
bool Game::playerHit() {
  blackjack.deal(Blackjack::player1);
  this->printState();
  if (blackjack.handValue(Blackjack::player1) > 21) {
    std::cout << "Your hand busted, you lost!\n";
    return false;
  }
  return true;
}
void Game::playerStay() {
  while (blackjack.handValue(Blackjack::dealer) < 17) {
    blackjack.deal(Blackjack::dealer);
    printState();
  }
  if (blackjack.handValue(Blackjack::dealer) > 21 ||
      blackjack.handValue(Blackjack::dealer) <
          blackjack.handValue(Blackjack::player1)) {
    std::cout << "YOU WON!";
    blackjack.changeMoney(Blackjack::player1,
                          blackjack.money(Blackjack::player1) + 2 * bet);
  } else if (blackjack.handValue(Blackjack::dealer) >
             blackjack.handValue(Blackjack::player1)) {
    std::cout << "YOU LOST!";
  } else {
    std::cout << "YOU TIED THE DEALER!";
    blackjack.changeMoney(Blackjack::player1,
                          blackjack.money(Blackjack::player1) + bet);
  }
  std::cout << '\n';
}

void Game::start() {
  blackjack.newRound();

  std::cout << "Your cash: " << blackjack.money(Blackjack::player1) << '\n';
  std::cout << "Enter your bet: ";

  // Get bet from the player until valid
  bet = 0;
  while (bet == 0 || bet > blackjack.money(Blackjack::player1)) std::cin >> bet;

  // Change the money to fit the bet
  blackjack.changeMoney(Blackjack::player1,
                        blackjack.money(Blackjack::player1) - bet);

  // Deal the appropriate amount of starting cards
  blackjack.deal(Blackjack::player1);
  blackjack.deal(Blackjack::player1);
  blackjack.deal(Blackjack::dealer);

  this->printState();
}

bool Game::action() {
  char action{};
  std::cout << "Type 'h' to hit, 's' to stay\n";
  std::cin >> action;
  if (action == 's') {
    this->playerStay();
    return false;
  } else if (action == 'h') {
    if (!this->playerHit()) return false;
  }
  return true;
}

void Game::loop() {
  while (blackjack.money(Blackjack::player1) != 0) {
    this->start();
    while (this->action());
  }
  std::cout << "You ran out of money! (T_T)\n";
}

void Game::end() {
  std::cin.seekg(0, std::ios::end);
  std::cin.clear();
  std::cout << "Press enter to quit: ";
  while (std::cin.get() != '\n') {
    continue;
  }
}
