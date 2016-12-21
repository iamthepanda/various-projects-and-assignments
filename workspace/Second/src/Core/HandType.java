package Core;

public enum HandType
{
	StraightFlush(9, "Straight Flush"),
	FourOfAKind(8, "Four Of A Kind"),
	FullHouse(7, "Full House"),
	Flush(6, "Flush"),
	Straight(5, "Straight"),
	ThreeOfAKind(4, "Three of A Kind"),
	TwoPair(3, "Two Pair"),
	OnePair(2, "One Pair"),
	HighCard(1, "High Card"),
	None(0);
	private int value;
	private String name;
	public int getValue()
	{
		return this.value;
	}
	public String toString()
	{
		return name;
	}
	private HandType(int val)
	{
		this.value = val;
	}
	private HandType(int val, String name)
	{
		this.value = val;
		this.name = name;
	}
}