package PJ4;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/*
 * Ref: http://en.wikipedia.org/wiki/Video_poker
 *      http://www.google.com/ig/directory?type=gadgets&url=www.labpixies.com/campaigns/videopoker/videopoker.xml
 *
 *
 * Short Description and Poker rules:
 *
 * Video poker is also known as draw poker. 
 * The dealer uses a 52-card deck, which is played fresh after each currentHand. 
 * The player is dealt one five-card poker currentHand. 
 * After the first draw, which is automatic, you may hold any of the cards and draw 
 * again to replace the cards that you haven't chosen to hold. 
 * Your cards are compared to a table of winning combinations. 
 * The object is to get the best possible combination so that you earn the highest 
 * payout on the bet you placed. 
 *
 * Winning Combinations
 *  
 * 1. Jacks or Better: a pair pays out only if the cards in the pair are Jacks, 
 * 	Queens, Kings, or Aces. Lower pairs do not pay out. 
 * 2. Two Pair: two sets of pairs of the same card denomination. 
 * 3. Three of a Kind: three cards of the same denomination. 
 * 4. Straight: five consecutive denomination cards of different suit. 
 * 5. Flush: five non-consecutive denomination cards of the same suit. 
 * 6. Full House: a set of three cards of the same denomination plus 
 * 	a set of two cards of the same denomination. 
 * 7. Four of a kind: four cards of the same denomination. 
 * 8. Straight Flush: five consecutive denomination cards of the same suit. 
 * 9. Royal Flush: five consecutive denomination cards of the same suit, 
 * 	starting from 10 and ending with an ace
 *
 */

/* This is the main poker game class.
 * It uses Decks and Card objects to implement poker game.
 * Please do not modify any data fields or defined methods
 * You may add new data fields and methods
 * Note: You must implement defined methods
 */

public class MyPokerGame {

	// default constant values
	private static final int startingBalance = 100;
	private static final int numberOfCards = 5;

	// default constant payout value and currentHand types
	private static final int[] multipliers = { 1, 2, 3, 5, 6, 9, 25, 50, 250 };
	private static final String[] goodHandTypes = { "Royal Pair", "Two Pairs",
			"Three of a Kind", "Straight", "Flush\t", "Full House",
			"Four of a Kind", "Straight Flush", "Royal Flush" };

	// must use only one deck
	private static final Decks oneDeck = new Decks(1);

	// holding current poker 5-card hand, balance, bet
	private List<Card> currentHand;
	private int balance;
	private int bet;
	private int multiplier;

	/**
	 * default constructor, set balance = startingBalance
	 */
	public MyPokerGame() {
		this(startingBalance);
	}

	/**
	 * constructor, set given balance
	 */
	public MyPokerGame(int balance) {
		this.balance = balance;
	}

	/**
	 * This display the payout table based on multipliers and goodHandTypes
	 * arrays
	 */
	private void showPayoutTable() {
		System.out.println("\n\n");
		System.out.println("Payout Table              Multiplier   ");
		System.out.println("=======================================");
		int size = multipliers.length;
		for (int i = size - 1; i >= 0; i--) {
			System.out.println(goodHandTypes[i] + "\t|\t" + multipliers[i]);
		}
		System.out.println("\n\n");
	}

	/**
	 * Check current currentHand using multipliers and goodHandTypes arrays Must
	 * print yourHandType (default is "Sorry, you lost") at the end of function.
	 * This can be checked by testCheckHands() and main() method.
	 */
	private void checkHands() {
		// implement this method!
		int rank = 0;
		String ranks;
		if (isRoyalPair() == true) {
			rank = 1;
			multiplier = multipliers[rank - 1];
		} else if (isTwoPair() == true) {
			rank = 2;
			multiplier = multipliers[rank - 1];
		}
		if (isThreeOfAKind() == true) {
			rank = 3;
			multiplier = multipliers[rank - 1];
		}
		if (isStraight() == true) {
			rank = 4;
			multiplier = multipliers[rank - 1];
		}
		if (isFlush() == true) {
			rank = 5;
			multiplier = multipliers[rank - 1];
		}
		if (isFullHouse() == true) {
			rank = 6;
			multiplier = multipliers[rank - 1];
		}
		if (isFourOfAKind() == true) {
			rank = 7;
			multiplier = multipliers[rank - 1];
		}
		if (isStraightFlush() == true) {
			rank = 8;
			multiplier = multipliers[rank - 1];
		}
		if (isRoyalFlush() == true) {
			rank = 9;
			multiplier = multipliers[rank - 1];
		}
		rank -= 1;
		if (rank < 0) {
			ranks = "Sorry, you lost!";
		} else {
			ranks = goodHandTypes[rank];
		}
		System.out.println("" + ranks);
	}

	/**
	 * *********************************************** add new private methods
	 * here ....
	 * 
	 ************************************************ 
	 */

	private boolean isRoyalFlush() {
		if (isFlush() == true) {
			for (int i = 0; i < 5; i++) {
				if (currentHand.get(i).getRank() == 1) {
					int[] array = new int[numberOfCards - 1];
					for (int j = 0; j < array.length; j++)
						array[j] = j + 1;
					Arrays.sort(array);
					int[] cardArray = new int[numberOfCards];
					for (int j = 0; j < cardArray.length; j++)
						cardArray[0] = currentHand.get(0).getRank();
					cardArray[1] = currentHand.get(1).getRank();
					cardArray[2] = currentHand.get(2).getRank();
					cardArray[3] = currentHand.get(3).getRank();
					cardArray[4] = currentHand.get(4).getRank();
					Arrays.sort(cardArray);
					if (cardArray[0] == 1 && cardArray[1] == cardArray[2] - 1
							&& cardArray[2] == cardArray[3] - 1
							&& cardArray[3] == cardArray[4] - 1) {
						if (cardArray[4] == 13) {
							return true;
						}
					} else {
						return false;
					}

				} else {
					return false;
				}
			}
			return false;
		} else {
			return false;
		}
	}

	private boolean isStraightFlush() {
		if (isStraight() == true && isFlush() == true) {
			return true;
		}
		return false;
	}

	private boolean isFourOfAKind() {
		if (isOnePair() == true || isThreeOfAKind() == true) {
			for (int i = 0; i < 5;) {
				int[] array = new int[numberOfCards - 1];
				for (int j = 0; j < array.length; j++)
					array[j] = j + 1;
				Arrays.sort(array);
				int[] cardArray = new int[numberOfCards];
				for (int j = 0; j < cardArray.length; j++)
					cardArray[0] = currentHand.get(0).getRank();
				cardArray[1] = currentHand.get(1).getRank();
				cardArray[2] = currentHand.get(2).getRank();
				cardArray[3] = currentHand.get(3).getRank();
				cardArray[4] = currentHand.get(4).getRank();
				Arrays.sort(cardArray);
				if (cardArray[0] == cardArray[1]
						&& cardArray[1] == cardArray[2]
						&& cardArray[2] == cardArray[3]) {
					return true;
				} else {
					return false;
				}
			}
			return false;
		} else {
			return false;
		}
	}

	private boolean isFullHouse() {
		if (isThreeOfAKind() == true && isOnePair() == true) {
			int[] array = new int[numberOfCards - 1];
			for (int j = 0; j < array.length; j++)
				array[j] = j + 1;
			Arrays.sort(array);
			int[] cardArray = new int[numberOfCards];
			for (int k = 0; k < cardArray.length; k++)
				cardArray[0] = currentHand.get(0).getRank();
			cardArray[1] = currentHand.get(1).getRank();
			cardArray[2] = currentHand.get(2).getRank();
			cardArray[3] = currentHand.get(3).getRank();
			cardArray[4] = currentHand.get(4).getRank();
			Arrays.sort(cardArray);
			if (cardArray[0] == cardArray[1] && cardArray[1] == cardArray[2]
					&& cardArray[3] == cardArray[4]) {
				return true;
			} else if (cardArray[2] == cardArray[3]
					&& cardArray[3] == cardArray[4]
					&& cardArray[0] == cardArray[1]) {
				return true;
			} else {
				return false;
			}
		} else {
			return false;
		}
	}

	private boolean isFlush() {
		if (currentHand.get(0).getSuit() == currentHand.get(1).getSuit()
				&& currentHand.get(1).getSuit() == currentHand.get(2).getSuit()
				&& currentHand.get(2).getSuit() == currentHand.get(3).getSuit()
				&& currentHand.get(3).getSuit() == currentHand.get(4).getSuit()) {
			return true;
		} else {
			return false;
		}
	}

	private boolean isStraight() {
		for (int i = 0; i < 5;) {
			if (currentHand.get(i).getRank() != 1) {
				int[] array = new int[numberOfCards - 1];
				for (int j = 0; j < array.length; j++)
					array[j] = j + 1;
				Arrays.sort(array);
				int[] cardArray = new int[numberOfCards];
				for (int j = 0; j < cardArray.length; j++)
					cardArray[0] = currentHand.get(0).getRank();
				cardArray[1] = currentHand.get(1).getRank();
				cardArray[2] = currentHand.get(2).getRank();
				cardArray[3] = currentHand.get(3).getRank();
				cardArray[4] = currentHand.get(4).getRank();
				Arrays.sort(cardArray);
				if (cardArray[0] == cardArray[1] - 1
						&& cardArray[1] == cardArray[2] - 1
						&& cardArray[2] == cardArray[3] - 1
						&& cardArray[3] == cardArray[4] - 1) {
					return true;
				} else {
					return false;
				}
			} else {
				return false;
			}
		}
		return false;
	}

	private boolean isThreeOfAKind() {
		int[] array = new int[numberOfCards - 1];
		for (int j = 0; j < array.length; j++)
			array[j] = j + 1;
		Arrays.sort(array);
		int[] cardArray = new int[numberOfCards];
		for (int k = 0; k < cardArray.length; k++)
			cardArray[0] = currentHand.get(0).getRank();
		cardArray[1] = currentHand.get(1).getRank();
		cardArray[2] = currentHand.get(2).getRank();
		cardArray[3] = currentHand.get(3).getRank();
		cardArray[4] = currentHand.get(4).getRank();
		Arrays.sort(cardArray);
		if (cardArray[0] == cardArray[1] && cardArray[1] == cardArray[2]) {
			return true;
		} else if (cardArray[1] == cardArray[2] && cardArray[2] == cardArray[3]) {
			return true;
		} else if (cardArray[2] == cardArray[3] && cardArray[3] == cardArray[4]) {
			return true;
		} else {
			return false;
		}
	}

	private boolean isTwoPair() {
		// check if it is four of a kind or two pair))
		if (isFourOfAKind() == true) {
			return false;
		}
		for (int i = 0; i < 5;) {
			int[] array = new int[numberOfCards - 1];
			for (int j = 0; j < array.length; j++)
				array[j] = j + 1;
			Arrays.sort(array);
			int[] cardArray = new int[numberOfCards];
			for (int j = 0; j < cardArray.length; j++)
				cardArray[0] = currentHand.get(0).getRank();
			cardArray[1] = currentHand.get(1).getRank();
			cardArray[2] = currentHand.get(2).getRank();
			cardArray[3] = currentHand.get(3).getRank();
			cardArray[4] = currentHand.get(4).getRank();
			Arrays.sort(cardArray);
			if (cardArray[0] == cardArray[1] && cardArray[2] == cardArray[3]) {
				return true;
			} else if (cardArray[0] == cardArray[1]
					&& cardArray[3] == cardArray[4]) {
				return true;
			} else if (cardArray[1] == cardArray[2]
					&& cardArray[3] == cardArray[4]) {
				return true;
			} else {
				return false;
			}
		}
		return false;
	}

	private boolean isOnePair() {
		for (int i = 0; i < 5; i++) {
			int[] array = new int[numberOfCards - 1];
			for (int j = 0; j < array.length; j++)
				array[j] = j + 1;
			Arrays.sort(array);
			int[] cardArray = new int[numberOfCards];
			for (int j = 0; j < cardArray.length;) {
				cardArray[0] = currentHand.get(0).getRank();
				cardArray[1] = currentHand.get(1).getRank();
				cardArray[2] = currentHand.get(2).getRank();
				cardArray[3] = currentHand.get(3).getRank();
				cardArray[4] = currentHand.get(4).getRank();
				Arrays.sort(cardArray);
				if (cardArray[0] == cardArray[1]) {
					return true;
				} else if (cardArray[1] == cardArray[2]) {
					return true;
				} else if (cardArray[2] == cardArray[3]) {
					return true;
				} else if (cardArray[3] == cardArray[4]) {
					return true;
				} else {
					return false;
				}
			}
		}
		return false;
	}

	public boolean isRoyalPair() {
		if (isOnePair() == true && isTwoPair() != true) {
			for (int i = 0; i < 5; i++) {
				int[] array = new int[numberOfCards - 1];
				for (int j = 0; j < array.length; j++)
					array[j] = j + 1;
				Arrays.sort(array);
				int[] cardArray = new int[numberOfCards];
				for (int j = 0; j < cardArray.length;) {
					cardArray[0] = currentHand.get(0).getRank();
					cardArray[1] = currentHand.get(1).getRank();
					cardArray[2] = currentHand.get(2).getRank();
					cardArray[3] = currentHand.get(3).getRank();
					cardArray[4] = currentHand.get(4).getRank();
					Arrays.sort(cardArray);
					if (cardArray[0] == cardArray[1] && cardArray[0] >= 11) {
						return true;
					} else if (cardArray[1] == cardArray[2]
							&& cardArray[1] >= 11) {
						return true;
					} else if (cardArray[2] == cardArray[3]
							&& cardArray[2] >= 11) {
						return true;
					} else if (cardArray[3] == cardArray[4]
							&& cardArray[3] >= 11) {
						return true;
					} else {
						return false;
					}
				}
			}
			return false;
		} else {
			return false;
		}
	}

	public void play() {
		/**
		 * The main algorithm for single player poker game
		 * 
		 * Steps: showPayoutTable()
		 * 
		 * ++ show balance, get bet verify bet value, update balance reset deck,
		 * shuffle deck, deal cards and display cards ask for position of cards
		 * to keep get positions in one input line update cards check hands,
		 * display proper messages update balance if there is a payout if
		 * balance = O: end of program else ask if the player wants to play a
		 * new game if the answer is "no" : end of program else :
		 * showPayoutTable() if user wants to see it goto ++
		 */

		// implement this method!
		String position;
		boolean match = false;
		boolean keepGoing = true;
		boolean rightBet = false;
		char input;

		List<Integer> list = new ArrayList<Integer>();
		Scanner scan = new Scanner(System.in);
		oneDeck.shuffle();
		showPayoutTable();

		do {
			System.out.println("-----------------------------------");
			System.out.println("Balance:$" + balance);
			rightBet = false;
			while (!rightBet) {
				System.out.print("Enter bet:");
				bet = scan.nextInt();
				if (bet > balance) {
					System.out.println("insufficient fund!");
					rightBet = false;
				} else {
					rightBet = true;
				}
			}

			balance = balance - bet;

			try {
				currentHand = oneDeck.deal(5);
			} catch (PlayingCardException e) {
				System.out.println("Error");
			}

			System.out.println("Hand " + currentHand);
			scan.nextLine();
			System.out.print("Enter positions of cards to keep (e.g. 1 4 5 ):");
			position = scan.nextLine();
			for (String s : position.split("\\s")) {
				list.add(Integer.parseInt(s));
			}
			list.toArray();

			for (int i = 0; i < currentHand.size(); i++) {
				for (int j = 0; j < list.size(); j++) {
					if (i == list.get(j) - 1) {
						match = true;
					}
				}

				if (!match) {
					try {
						currentHand.set(i, oneDeck.deal(1).get(0));

					} catch (PlayingCardException e) {
						System.out.println("oops");

					}
				}

				match = false;

			}

			System.out.println("Hand " + currentHand);

			checkHands();

			balance = (bet * multiplier) + balance;
			if (balance == 0) {
				System.out.println("\nYour balance is " + balance);
				keepGoing = false;
			} else {

				System.out.print("\nYour balance:$" + balance);
				System.out.print(", one more game (y or n)?");

				input = scan.next().charAt(0);

				if (input == 'n') {
					keepGoing = false;
				} else if (input == 'y') {
					System.out.print("\nWant to see payout table (y or n)");
					input = scan.next().charAt(0);
					if (input == 'y') {
						showPayoutTable();
					} else if (input == 'n') {
						keepGoing = true;
					}
				}
			}
		} while (keepGoing);

		System.out.println("Bye!");
		scan.close();
	}

	/**
	 * Do not modify this. It is used to test checkHands() method checkHands()
	 * should print your current hand type
	 */

	public void testCheckHands() {
		try {
			currentHand = new ArrayList<Card>();

			// set Royal Flush
			currentHand.add(new Card(1, 3));
			currentHand.add(new Card(10, 3));
			currentHand.add(new Card(12, 3));
			currentHand.add(new Card(11, 3));
			currentHand.add(new Card(13, 3));
			System.out.println(currentHand);
			checkHands();
			System.out.println("-----------------------------------");

			// set Straight Flush
			currentHand.set(0, new Card(9, 3));
			System.out.println(currentHand);
			checkHands();
			System.out.println("-----------------------------------");

			// set Straight
			currentHand.set(4, new Card(8, 1));
			System.out.println(currentHand);
			checkHands();
			System.out.println("-----------------------------------");

			// set Flush
			currentHand.set(4, new Card(5, 3));
			System.out.println(currentHand);
			checkHands();
			System.out.println("-----------------------------------");

			// "Royal Pair" , "Two Pairs" , "Three of a Kind", "Straight",
			// "Flush	",
			// "Full House", "Four of a Kind", "Straight Flush", "Royal Flush"
			// };

			// set Four of a Kind
			currentHand.clear();
			currentHand.add(new Card(8, 3));
			currentHand.add(new Card(8, 0));
			currentHand.add(new Card(12, 3));
			currentHand.add(new Card(8, 1));
			currentHand.add(new Card(8, 2));
			System.out.println(currentHand);
			checkHands();
			System.out.println("-----------------------------------");

			// set Three of a Kind
			currentHand.set(4, new Card(11, 3));
			System.out.println(currentHand);
			checkHands();
			System.out.println("-----------------------------------");

			// set Full House
			currentHand.set(2, new Card(11, 1));
			System.out.println(currentHand);
			checkHands();
			System.out.println("-----------------------------------");

			// set Two Pairs
			currentHand.set(1, new Card(9, 1));
			System.out.println(currentHand);
			checkHands();
			System.out.println("-----------------------------------");

			// set Royal Pair
			currentHand.set(0, new Card(3, 1));
			System.out.println(currentHand);
			checkHands();
			System.out.println("-----------------------------------");

			// non Royal Pair
			currentHand.set(2, new Card(3, 3));
			System.out.println(currentHand);
			checkHands();
			System.out.println("-----------------------------------");
		} catch (Exception e) {
			System.out.println("exception" + e.getMessage());
		}
	}

	/* Quick testCheckHands() */
	public static void main(String args[]) {
		MyPokerGame mypokergame = new MyPokerGame();
		mypokergame.testCheckHands();
	}
}
