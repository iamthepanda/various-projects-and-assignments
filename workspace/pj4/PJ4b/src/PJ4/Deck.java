package PJ4;

import java.util.Collections;
import java.util.LinkedList;

public class Deck {

	private LinkedList<Card> deck;

	public Deck() {
		try {
			deck = getNewDeck();
		} catch (PlayingCardException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	private LinkedList<Card> getNewDeck() throws PlayingCardException {
		LinkedList<Card> newDeck = new LinkedList<Card>();
		for (char rank : "23456789TJQKA".toCharArray()) {
			for (char suit : "scdh".toCharArray()) {
				newDeck.add(new Card(rank, suit));
			}
		}
		return newDeck;
	}

	public void shuffle() {
		Collections.shuffle(deck);
	}

	public Card popCard() {
		return deck.removeFirst();
	}

	public boolean isEmpty() {
		return deck.isEmpty();
	}

}
