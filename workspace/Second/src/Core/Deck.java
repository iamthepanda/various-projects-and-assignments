package Core;
import java.util.*;

 public class Deck {
	public List<Card> Cards = new ArrayList<Card>();
	public void Shuffle()
	{
		Cards.clear();
		for (int i = 1;i<=4;i++)
		{
			for (int j = 1;j<=13;j++)
			{
				int suit = i;
				int val = j;
				Card card = new Card(suit, val);
				Cards.add(card);
			}
		}
	}
	public void dealCard(Player player)
	{
		Random gen = new Random();
		int index = gen.nextInt(Cards.size()-1);
		player.Hand.Cards.add(this.Cards.get(index));
		this.Cards.remove(index);
	}
	public void dealCard(Player player, int numOfCards)
	{
		for (int i = 0;i<numOfCards;i++)
		{
			dealCard(player);
		}
	}
	public Deck()
	{
		Shuffle();
	}
}
