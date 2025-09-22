package org.example;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

public class Deck {
    private ArrayList<Card> cards = new ArrayList<>();
    private Random random = new Random(System.currentTimeMillis());
    private final static int shuffleCount = 1000;

    public Deck() {
        for(Card.Suit suit : Card.Suit.values()) {
            for(Card.Rank rank : Card.Rank.values()) {
                cards.add(new Card(suit, rank));
            }
        }
    }
    public void shuffle() {
        for(int i = 0; i < shuffleCount; i++) {
            Collections.swap(cards, random.nextInt(cards.toArray().length), random.nextInt(cards.toArray().length));
        }
    }
    public Card deal() {
        Card card = cards.getLast();
        cards.removeLast();
        return card;
    }
}
