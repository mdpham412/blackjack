package org.example;

public class Card {
    public static enum Suit {
        CLUBS, SPADES, DIAMONDS, HEARTS
    }
    public static enum Rank {
        ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
    }

    private Suit suit;
    private Rank rank;

    public Card(Suit s, Rank r) {
        this.suit = s;
        this.rank = r;
    }
    public Suit getSuit() {
        return this.suit;
    }
    public Rank getRank() {
        return this.rank;
    }
    public int value() {
        return switch (this.rank) {
            case ACE -> 11;
            case TWO -> 2;
            case THREE -> 3;
            case FOUR -> 4;
            case FIVE -> 5;
            case SIX -> 6;
            case SEVEN -> 7;
            case EIGHT -> 8;
            case NINE -> 9;
            case TEN, JACK, QUEEN, KING -> 10;
        };
    }

    @Override
    public String toString() {
        return this.rank.name().toLowerCase() + " of " + this.suit.name().toLowerCase();
    }
}
