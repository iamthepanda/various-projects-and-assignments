package PJ4;
import java.util.Comparator;

public class CardComparator implements Comparator<Card> {

	@Override
	public int compare(Card one, Card two) {
		int cardOneRank = "23456789TJQKA".indexOf(one.getRank());
		int cardTwoRank = "23456789TJQKA".indexOf(two.getRank());
		if (cardOneRank < cardTwoRank) {
			return -1;
		} else if (cardOneRank > cardTwoRank) {
			return 1;
		} else {
			return 0;
		}

	}
}
