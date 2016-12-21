package PJ4;
public class Player {

	private Card[] holeCards = new Card[2];
	private int stack;
	private String username;

	public Player(int startingStack, String un) {
		stack = startingStack;
		username = un;
	}

	public void setCards(Card one, Card two) {
		holeCards[0] = one;
		holeCards[1] = two;
	}

	public Card[] getCards() {
		return holeCards;
	}

	public void add(int chips) {
		stack += chips;
	}

	public void take(int chips) {
		stack -= chips;
	}

	public boolean hasNoChips() {
		return (stack == 0);
	}

	public int getStack() {
		return stack;
	}

	public String getUsername() {
		return username;
	}
}
