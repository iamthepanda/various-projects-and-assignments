public package PokerGUI;
import java.util.*;
import Core.Card;
import Core.Player;

public class GUI {
	public GUI(Player player1, Player player2){
		this.gameWindow = new GameWindow();
		gameWindow.p1Label.setText(player1.Name);
		gameWindow.p2Label.setText(player2.Name);
		updateCards(player1.Hand.Cards, player2.Hand.Cards);
		this.gameWindow.setVisible(true);
	}
	public GameWindow gameWindow;
	public void updateWinner(Player p1){
		if (p1 != null)
		{
			gameWindow.winLabel.setText(p1.Name + " wins with: " + p1.Hand.getHandType().toString());
		}
		else
		{
			gameWindow.winLabel.setText("There was a Tie");
		}
	}
	public void updateRound(int round){
		gameWindow.lblRound.setText("Round: " + round);
	}
	public void updateCards(List<Card> cards, List<Card> cards2){
		gameWindow.p1Panel.removeAll();
		gameWindow.p2Panel.removeAll();
		for (int i = 0; i<cards.size();i++)
		{
			CardButton cb = new CardButton(cards.get(i));
			cb.setLocation(i*200, 0);
			gameWindow.p1Panel.add(cb);
		}
		for (int i = 0; i<cards2.size();i++)
		{
			CardButton cb = new CardButton(cards2.get(i));
			cb.setLocation(i*200, 300);
			gameWindow.p2Panel.add(cb);
		}
		gameWindow.repaint();
		gameWindow.p1Panel.revalidate();
		gameWindow.p2Panel.revalidate();
		
	} 
}
