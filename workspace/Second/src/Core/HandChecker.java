package Core;

public class HandChecker {
	private static void sort(Hand sort){
		boolean changed = false;
		do{
			changed = false;
			for(int i = 0; i<sort.Cards.size()-1;i++)
			{
				if (sort.Cards.get(i).Value > sort.Cards.get(i+1).Value)
				{
					Card temp = sort.Cards.get(i);
					sort.Cards.set(i, sort.Cards.get(i+1));
					sort.Cards.set(i+1, temp);
					changed = true;
				}
			}
		}while(changed);
	}
	private static boolean isFlush(Hand hand)
	{
		Card.Suit suit = hand.Cards.get(0).CardSuit;
		for (int i =0;i<hand.Cards.size();i++)
		{
			if (hand.Cards.get(i).CardSuit != suit) return false;
			suit = hand.Cards.get(i).CardSuit;
		}
		hand.Kicker = hand.Cards.get(hand.Cards.size()-1).Value;
		return true;
	}
	private static boolean isStraight(Hand hand)
	{
		boolean isstraight = true;
		for(int i =0;i<hand.Cards.size()-1;i++)
		{
			
			if (hand.Cards.get(i).Value+1 != hand.Cards.get(i+1).Value) isstraight = false;
			
			if (hand.Cards.get(4).Value == 14 && !isstraight) {
				if (hand.Cards.get(0).Value == 2 && hand.Cards.get(1).Value == 3 && hand.Cards.get(2).Value == 4 && hand.Cards.get(3).Value == 5)
					return true;
			}
			if (!isstraight){return false;} 
		}
		hand.Kicker = hand.Cards.get(hand.Cards.size()-1).Value;
		return true;
	}
	private static boolean isFourOfAKind(Hand hand)
	{
		return hasMatches(hand, 4); 
	}
	private static boolean isThreeOfAKind(Hand hand)
	{
		return hasMatches(hand, 3);
	}
	private static boolean hasMatches(Hand hand, int matchreq)
	{
		for (int i =0;i<hand.Cards.size();i++)
		{
			int matchnum = 0;
			int j;
			for (j = 0; j<hand.Cards.size();j++)
				{
					if (hand.Cards.get(i).Value == hand.Cards.get(j).Value) matchnum++;
				}
			if (matchnum == matchreq){ 
				hand.Kicker = hand.Cards.get(i).Value;
				return true;
				}
		}
		return false;
	}
	private static boolean isFullHouse(Hand hand)
	{
		if(hasMatches(hand, 2))
		{
			hand.Kicker2 = hand.Kicker;
			if (hasMatches(hand, 3)){
				return true;
			}
		}
		return false;
	}
	private static int getPairs(Hand hand)
	{
		int k = 0;
		int pairs = 0;
		for(int i = 0; i < hand.Cards.size()-1;i++)
		{
			for (int j = i+1; j < hand.Cards.size(); j++)
			{
				if (hand.Cards.get(i).Value == hand.Cards.get(j).Value)
				{
					if (hand.Cards.get(i).Value > k)
					{
						hand.Kicker = k;
						k = hand.Cards.get(i).Value;
					}
					pairs++;
				}
			}
		}
		return pairs;
	}
	private static boolean isTwoPair(Hand hand)
	{
		return (getPairs(hand) == 2);
	}
	private static boolean isOnePair(Hand hand)
	{
		return (getPairs(hand) == 1);
	}
	private static boolean isHighCard(Hand hand)
	{
		int val = hand.Cards.get(hand.Cards.size()-1).Value;
		hand.Kicker = hand.Cards.get(hand.Cards.size()-1).Value;
		return (val == 1 || val >= 7);
	}
	public static HandType GetHandType(Hand hand)
	{
		sort(hand);
		if (isStraight(hand) && isFlush(hand)) return HandType.StraightFlush;
		else if (isFourOfAKind(hand)) return HandType.FourOfAKind;
		else if (isFullHouse(hand)) return HandType.FullHouse;
		else if (isFlush(hand)) return HandType.Flush;
		else if (isStraight(hand)) return HandType.Straight;
		else if (isThreeOfAKind(hand)) return HandType.ThreeOfAKind;
		else if (isTwoPair(hand)) return HandType.TwoPair;
		else if (isOnePair(hand)) return HandType.OnePair;
		else if (isHighCard(hand))return HandType.HighCard; 
		return HandType.None;
	}
}