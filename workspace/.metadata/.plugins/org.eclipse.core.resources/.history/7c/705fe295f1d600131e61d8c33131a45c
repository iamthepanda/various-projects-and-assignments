package PJ4;
import java.util.Arrays;

public class HandRank {

	public static int compareHands(Card[] board, Card[] hc1, Card[] hc2) {

		int[] hand1 = determineHand(board, hc1);
		int[] hand2 = determineHand(board, hc2);

		return compare(hand1, hand2);

	}

	public static int[] getHandRank(Card[] cards) {
		int[] ranks = new int[6];

		if (isStraightFlush(cards) != null) {
			ranks = isStraightFlush(cards);
		} else if (isFourKind(cards) != null) {
			ranks = isFourKind(cards);
		} else if (isFullHouse(cards) != null) {
			ranks = isFullHouse(cards);
		} else if (isFlush(cards) != null) {
			ranks = isFlush(cards);
		} else if (isStraight(cards) != null) {
			ranks = isStraight(cards);
		} else if (isTrips(cards) != null) {
			ranks = isTrips(cards);
		} else if (isTwoPair(cards) != null) {
			ranks = isTwoPair(cards);
		} else if (isOnePair(cards) != null) {
			ranks = isOnePair(cards);
		} else {
			ranks = isHighCard(cards);
		}
		return ranks;
	}

	public static int[] determineHand(Card[] board, Card[] holeCards) {
		// Given 7 cards there are 21 (board and hc) combinations to put it
		// as 5 cards
		String[] combinations = getCombinations(board.length);

		Card[] combo = new Card[5];
		int[] maxRank = { 0, 0, 0, 0, 0, 0 };
		int j = 0;

		for (String comb : combinations) {
			for (char c : comb.toCharArray()) {
				if (c == '6') {
					combo[j] = (holeCards[0]);
				} else if (c == '7') {
					combo[j] = holeCards[1];
				} else {
					combo[j] = board[Integer.parseInt(Character.toString(c)) - 1];
				}
				j++;
			}
			j = 0;
			if ((compare(maxRank, getHandRank(combo)) == 1)) {
				maxRank = getHandRank(combo);
			}
		}
		return maxRank;
	}

	public static String[] getCombinations(int boardSize) {
		if (boardSize == 5) {
			String[] combinations = { "12345", "12346", "12347", "12356",
					"12357", "12367", "12456", "12457", "12467", "12567",
					"13456", "13457", "13467", "13567", "14567", "23456",
					"23457", "23467", "23567", "24567", "34567" };
			return combinations;
		} else if (boardSize == 4) {
			String[] combinations = { "12345", "12346", "12356", "12456",
					"13456", "23456" };
			return combinations;
		} else if (boardSize == 3) {
			String[] combinations = { "12345" };
			return combinations;
		}
		return null;
	}

	public static int[] isStraightFlush(Card[] cards) {
		int[] result = new int[2];
		result[0] = 8;

		if (isStraight(cards) != null && isFlush(cards) != null) {
			result[1] = max(cards);
			return result;
		} else {
			return null;
		}
	}

	public static int[] isFourKind(Card[] cards) {
		int[] result = new int[3];
		result[0] = 7;

		if (isKind(4, cards) > 0) {
			result[1] = isKind(4, cards);
			result[2] = isKind(1, cards);
			return result;
		} else {
			return null;
		}

	}

	public static int[] isFullHouse(Card[] cards) {
		int[] result = new int[3];
		result[0] = 6;

		if (isKind(3, cards) > 0 && isKind(2, cards) > 0) {
			result[1] = isKind(3, cards);
			result[2] = isKind(2, cards);
			return result;
		} else {
			return null;
		}
	}

	public static int[] isFlush(Card[] cards) {
		int[] result = new int[6];
		result[0] = 5;
		Arrays.sort(cards, new CardComparator());
		if (cards[0].getSuit() == cards[1].getSuit()
				&& cards[1].getSuit() == cards[2].getSuit()
				&& cards[2].getSuit() == cards[3].getSuit()
				&& cards[3].getSuit() == cards[4].getSuit()) {
			System.arraycopy(isHighCard(cards), 1, result, 0, 5);
			return result;
		} else {
			return null;
		}
	}

	public static int[] isStraight(Card[] cards) {
		Arrays.sort(cards, new CardComparator());
		int[] result = new int[2];
		result[0] = 4;
		if (isHighCard(cards) != null) {
			if (rank(cards[4]) - rank(cards[0]) == 4) {
				result[1] = max(cards);
				return result;
			} else if (cards[4].getRank() == 'A' && cards[3].getRank() == '5') { // Wheel
				result[1] = 5;
				return result;
			} else {
				return null;
			}
		} else {
			return null;
		}
	}

	public static int[] isTrips(Card[] cards) {
		if (isKind(3, cards) < 0 || isKind(1, cards) < 0) {
			return null;
		}

		int[] result = new int[4];
		result[0] = 3;
		Card[] reducedCards = getReducedCards(cards, 3);
		Arrays.sort(reducedCards, new CardComparator());
		result[1] = isKind(3, cards);
		result[2] = rank(reducedCards[1]);
		result[3] = rank(reducedCards[0]);
		return result;
	}

	public static int[] isTwoPair(Card[] cards) {
		int[] result = new int[4];
		result[0] = 2;

		if (isKind(2, cards) > 0 && secPair(cards) > 0) {
			result[1] = Math.max(isKind(2, cards), secPair(cards));
			result[2] = Math.min(isKind(2, cards), secPair(cards));
			result[3] = isKind(1, cards);
			return result;
		} else {
			return null;
		}
	}

	public static int[] isOnePair(Card[] cards) {
		int[] result = new int[5];
		result[0] = 1;

		if (isKind(2, cards) > 0) {
			Card[] reducedCards = getReducedCards(cards, 2);
			Arrays.sort(reducedCards, new CardComparator());
			result[1] = isKind(2, cards);
			result[2] = rank(reducedCards[2]);
			result[3] = rank(reducedCards[1]);
			result[4] = rank(reducedCards[0]);
			return result;
		} else {
			return null;
		}
	}

	public static int[] isHighCard(Card[] cards) {
		for (Card c : cards) {
			if (cardCount(c, cards) != 1) {
				return null;
			}
		}

		Arrays.sort(cards, new CardComparator());
		int[] result = new int[6];
		result[0] = 0;

		for (int i = 0; i < cards.length; i++) {
			result[i + 1] = rank(cards[cards.length - 1 - i]);
		}
		return result;
	}

	private static int secPair(Card[] cards) {
		Arrays.sort(cards, new CardComparator());
		if (isKind(2, cards) == -1) {
			return -1;
		}
		Card[] reducedCards = getReducedCards(cards, 2);
		return isKind(2, reducedCards);
	}

	private static Card[] getReducedCards(Card[] cards, int kind) {
		int firstRank = isKind(kind, cards);
		Card[] reducedCards = new Card[5 - kind];

		int j = 0;
		for (int i = 0; i < cards.length; i++) {
			if (rank(cards[i]) != firstRank) {
				reducedCards[j] = cards[i];
				j++;
			}
		}
		return reducedCards;
	}

	public static int isKind(int freq, Card[] cards) {
		Arrays.sort(cards, new CardComparator());
		for (Card c : cards) {
			if (cardCount(c, cards) == freq) {
				return rank(c);
			}
		}
		return -1;
	}

	public static int cardCount(Card card, Card[] cards) {
		int counter = 0;

		for (Card c : cards) {
			if (card.getRank() == c.getRank()) {
				counter += 1;
			}
		}
		return counter;
	}

	public static int max(Card[] cards) {
		Arrays.sort(cards, new CardComparator());
		return rank(cards[cards.length - 1]);
	}

	public static int rank(Card card) {
		return "..23456789TJQKA".indexOf(card.getRank());
	}

	private static int compare(int[] one, int[] two) {
		for (int i = 0; i < Math.min(one.length, two.length); i++) {
			if (one[i] < two[i]) {
				return 1;
			} else if (one[i] > two[i]) {
				return -1;
			}
		}
		return 0;
	}


	public static String s(Card[] cards) {
		String s = "";
		for (Card c : cards) {
			s += c + " ";
		}
		return s;
	}

	public static void main(String[] agrs) {
		int[] a = { 1, 2, 3, 4, 5 };
		int[] b = new int[7];
		System.arraycopy(a, 0, b, 0, 4);
		System.out.println(b[1]);
	}
}