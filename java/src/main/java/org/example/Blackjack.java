package org.example;

import java.util.Scanner;

public class Blackjack {
    private final static int startingMoney = 5000;


    private Deck deck = new Deck();
    private Hand dealer = new Hand();
    private Hand player = new Hand();
    private int bet;
    private int playerMoney = startingMoney;
    private Scanner scanner = new Scanner(System.in);



    private static enum Hands {
        DEALER, PLAYER
    }
    private void reset() {
        deck = new Deck();
        deck.shuffle();
        dealer.clear();
        player.clear();
    }
    private void deal(Hands hand) {
        switch(hand) {
            case DEALER: {
                dealer.deal(deck.deal());
                break;
            }
            case PLAYER: {
                player.deal(deck.deal());
                break;
            }
            default: break;
        }
    }
    private void print() {
        // Clear console
        System.out.print("\033[H\033[2J");
        System.out.flush();

        System.out.printf("Dealer (%s): ", dealer.valueAsString());
        dealer.print();
        System.out.printf("Player (%s): ", player.valueAsString());
        player.print();
        System.out.printf("Bet: %d\n", bet);
        System.out.printf("Money: %d\n", playerMoney);
    }
    private void checkResult() {
        if (dealer.value() > 21) {
            System.out.println("The dealer busted, you won!");
            playerMoney += bet * 2;
        } else if (dealer.value() > player.value()) {
            System.out.println("Your hand value was too low, you lost.");
        } else if (dealer.value() == player.value()){
            System.out.println("Your hand value was equal to the dealer's, it's a tie!");
            playerMoney += bet;
        } else {
            System.out.println("Your hand value beat the dealer's, you won!");
            playerMoney += bet * 2;
        }
    }
    private void end() {
        System.out.println("You're out of money :`(");
        System.out.print("Closing in ");
        for(int i = 5; i > 0; i--) {
            System.out.print(i + "...");
            try {
                Thread.sleep(1000);
            } catch (Exception _) {}
        }
        System.out.print("0");
    }


    public void play() {
        while(playerMoney > 0) {
            this.reset();
            bet = Integer.MAX_VALUE;

            // Get bet
            System.out.printf("Your money: %d\n", playerMoney);
            System.out.print("Enter a bet: ");
            while (!scanner.hasNextInt()) scanner.next();
            do {
                bet = scanner.nextInt();
            } while (bet > playerMoney);

            playerMoney -= bet;

            // Initial cards
            this.deal(Hands.PLAYER);
            this.deal(Hands.PLAYER);
            this.deal(Hands.DEALER);
            this.print();

            System.out.println("Type 'h' to hit, 's' to stand: ");
            char action = scanner.next().charAt(0);
            while(action != 's') {
                if (action == 'h') {
                    this.deal(Hands.PLAYER);
                    this.print();
                    if (player.value() > 21) break;
                }
                action = scanner.next().charAt(0);
            }

            if (player.value() > 21) {
                System.out.println("Your hand busted, you lost.");
                break;
            }

            // Deal to dealer's hand until enough
            while(dealer.value() < 17) {
                this.deal(Hands.DEALER);
            }
            this.print();
            this.checkResult();
            System.out.println();
        }

        this.end();
        scanner.close();
    }
}
