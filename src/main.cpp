#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "blackjack.hpp"

#define CLEARTERM "\033[2J\033[1;1H"
#define PRINTGAMESTATE                            \
  std::cout << CLEARTERM << game << std::setw(10) \
            << "Bet: " << std::setw(width - 10) << bet << '\n'
constexpr int width{40};

int main() {
  Blackjack game;
  char action;

  std::cout << CLEARTERM;
  // Game loop
  while (true) {
    if (game.money(Blackjack::player1) == 0) {
      std::cout << "You ran out of money! :`(\n";
      break;
    }

    game.newRound();

    int bet{0};
    std::cout << "Your cash: " << game.money(Blackjack::player1) << '\n';
    std::cout << "Enter your bet: ";

    // Get bet from the player until valid
    while (bet == 0 || bet > game.money(Blackjack::player1)) std::cin >> bet;

    // Change the money to fit the bet
    game.changeMoney(Blackjack::player1, game.money(Blackjack::player1) - bet);

    // Deal the appropriate amount of cards
    game.deal(Blackjack::player1);
    game.deal(Blackjack::player1);
    game.deal(Blackjack::dealer);

    PRINTGAMESTATE;

    // Game action loops
    while (true) {
      std::cout << "Type 'h' to hit, 's' to stay\n";
      std::cin >> action;
      if (action == 'h') {
        game.deal(Blackjack::player1);
        PRINTGAMESTATE;
        if (game.handValue(Blackjack::player1) > 21) {
          std::cout << "Your hand busted, you lost!\n";
          break;
        }
      } else if (action == 's') {
        while (game.handValue(Blackjack::dealer) < 17) {
          game.deal(Blackjack::dealer);
          PRINTGAMESTATE;
        }
        if (game.handValue(Blackjack::dealer) > 21 ||
            game.handValue(Blackjack::dealer) <
                game.handValue(Blackjack::player1)) {
          std::cout << "YOU WON!";
          game.changeMoney(Blackjack::player1,
                           game.money(Blackjack::player1) + 2 * bet);
        } else if (game.handValue(Blackjack::dealer) >
                   game.handValue(Blackjack::player1)) {
          std::cout << "YOU LOST!";
        } else {
          std::cout << "YOU TIED THE DEALER!";
          game.changeMoney(Blackjack::player1,
                           game.money(Blackjack::player1) + bet);
        }
        std::cout << '\n';
        break;
      } else
        continue;
    }
  }
  // Require user input before quitting
  std::cin.seekg(0, std::ios::end);
  std::cin.clear();
  std::cout << "Press enter to quit: ";
  while (std::cin.get() != '\n') {
    continue;
  }
  return 0;
}
