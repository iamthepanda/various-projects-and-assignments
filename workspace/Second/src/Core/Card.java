package Core;

public class Card {

	public enum Suit{
		Spades, Hearts, Diamonds, Clubs
	}
	public Suit CardSuit;
	public int Value;
	public String toString()
	{
		String valuestr = null;
		switch (this.Value)
		{
			case 14:
				valuestr = "Ace";
				break;
			case 11:
				valuestr = "Jack";
				break;
			case 12:
				valuestr = "Queen";
				break;
			case 13: 
				valuestr = "King";
				break;
			default:
				valuestr = Integer.toString(this.Value);
		}
		return valuestr + " of " + this.CardSuit.toString();
	}
	public Card(int suit, int val)
	{
		switch (suit)
		{
			case 1:
				this.CardSuit = Suit.Spades;
				break;
			case 2:
				this.CardSuit  = Suit.Hearts;
				break;
			case 3:
				this.CardSuit  = Suit.Diamonds;
				break;
			case 4:
				this.CardSuit  = Suit.Clubs;
				break;
			default:
		}
		
		this.Value = val;
		if (val == 1)
		{
			this.Value = 14;
		}
	}
	public String getCardFileName(){
		String base = "/cards/Playing_card_";
		String extension = "jpg";
		String suit = this.CardSuit.toString().toLowerCase().substring(0, this.CardSuit.toString().length()-1);
		String rnk = "";
		switch (this.Value)
		{
			case 11:
				rnk = "J";
				break;
			case 12:
				rnk = "Q";
				break;
			case 13:
				rnk = "K";
				break;
			case 14:
				rnk = "A";
				break;
			default:
					rnk = Integer.toString(this.Value);
		}
		return this.getClass().getResource(base + suit + "_" + rnk + "." + extension).getFile();
	}
	public Card()
	{
		
	}
}
