package Core;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import PokerGUI.*;
public class Game{
	private int round;
	private GUI gui;
	private Deck deck;
	private Player player1;
	private Player player2;
	private final int ROUND_LIMIT = 5;
	public void Start(){
		round = 1;
		deck = new Deck();
		player1 = new Player("Player 1");
		player2 = new Player("Player 2");
		deck.dealCard(player1, 5);
		deck.dealCard(player2, 5);
		gui = new GUI(player1, player2);
		gui.gameWindow.btnRestart.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				newRound();
			}
		});
		updateGUI();
		round++;
	}
	public void updateGUI(){
		Player winner = getWinner(player1, player2);
		if (winner != null){
			winner.Score++;
		}
		gui.gameWindow.updateScore(player1, player2);
		gui.updateWinner(winner);
		gui.updateCards(player1.Hand.Cards, player2.Hand.Cards);
		gui.updateRound(round);
	}
	public void newRound(){
		if (round > ROUND_LIMIT){
			round = 1;
			deck = new Deck();
			player1 = new Player("Player 1");
			player2 = new Player("Player 2");
		}
		player1.Hand.Cards.clear();
		player2.Hand.Cards.clear();
		deck.dealCard(player1, 5);
		deck.dealCard(player2, 5);
		updateGUI();
		round++;
	}
	public Player getWinner(Player p1, Player p2){
		if (p1.Hand.getValue() > p2.Hand.getValue()){
			return p1;
		}
		else if(p2.Hand.getValue() > p1.Hand.getValue())
		{
			return p2;
		}
		else {
			if (p1.Hand.Kicker > p2.Hand.Kicker){
				return p1;
			}
			else if(p2.Hand.Kicker > p1.Hand.Kicker)
			{
				return p2;
			}
			else {
				if (p1.Hand.Kicker2 > p2.Hand.Kicker2){
					return p1;
				}
				else if(p2.Hand.Kicker2 > p1.Hand.Kicker)
				{
					return p2;
				}
			return null;
			}
		}
	}
}