package org.example;

import java.util.ArrayList;

public class Hand {
    private ArrayList<Card> cards = new ArrayList<>();

    public void deal(Card card) {
        cards.add(card);
    }

    public void clear() {
        cards.clear();
    }

    public void print() {
        for (int i = 0; i < cards.toArray().length - 1; i++) {
            System.out.print(cards.get(i).toString() + ", ");
        }
        System.out.print(cards.getLast().toString());
        System.out.print("\n");
    }

    public int value() {
        int aces = 0, result = 0;
        for (Card card : cards) {
            if (card.getRank() == Card.Rank.ACE) {
                aces++;
            } else {
                result += card.value();
            }
        }

        while (aces-- > 0) {
            if (result + 11 > 21)
                result += 1;
            else
                result += 11;
        }
        return result;
    }

    // soft or hard hand + value
    public String valueAsString() {
        int aces = 0, result = 0;
        boolean hardValue = true;
        for (Card card : cards) {
            if (card.getRank() == Card.Rank.ACE) {
                aces++;
            } else {
                result += card.value();
            }
        }

        while (aces-- > 0) {
            if (result + 11 > 21) {
                result += 1;
            } else {
                result += 11;
                hardValue = false;
            }
        }
        if (hardValue)
            return "hard " + result;
        else
            return "soft " + result;
    }
}
