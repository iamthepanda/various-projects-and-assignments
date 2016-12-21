import Core.Deck;
import Core.Game;


public class Program {
	public static void main(String[] args) {
		Deck deck = new Deck();
		for (int i = 0;i<deck.Cards.size();i++)
		{
			System.out.println(deck.Cards.get(i).toString() + "\t File: " + deck.Cards.get(i).getCardFileName());
		}
		Game game = new Game();
		game.Start();
	}
}
