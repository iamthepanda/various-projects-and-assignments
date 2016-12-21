package PokerGUI;
import java.awt.*;

import javax.swing.*;

import net.miginfocom.swing.MigLayout;
import Core.*;

@SuppressWarnings("serial")
public class GameWindow extends JFrame {
	public JLabel p1Label = new JLabel();
	public JLabel p2Label = new JLabel();
	public JLabel winLabel = new JLabel();
	public JButton btnRestart = new JButton("New Round");
	public JPanel p1Panel = new JPanel();
	public JPanel p2Panel = new JPanel();
	public JPanel topPanel = new JPanel();
	public JPanel cPanel = new JPanel();
	public JLabel lblP1Score = new JLabel();
	public JLabel lblP2Score = new JLabel();
	public JLabel lblRound = new JLabel();
	public void updateScore(Player p1, Player p2){
		lblP1Score.setText(" (Score: " + p1.Score + ")");
		lblP2Score.setText(" (Score: " + p2.Score + ")");
	}
	public GameWindow(){
		setResizable(false);
		setTitle("Jonathan's Poker");
		setSize(1060, 800);
		setLocationRelativeTo(null);
	    setDefaultCloseOperation(EXIT_ON_CLOSE);
	    MigLayout layout = new MigLayout();
	    this.setLayout(layout);
	    this.p1Panel.setLayout(new GridLayout(1, 5));
	    this.p1Panel.setSize(1000, 250);
	    this.p2Panel.setLayout(new GridLayout(1, 5));
	    this.p2Panel.setSize(1000, 250);
	    this.topPanel.setLayout(new MigLayout());
	    this.lblRound.setFont(lblRound.getFont().deriveFont(30.0f));
	    this.topPanel.add(lblRound, "span");
	    this.topPanel.add(p1Label);
	    this.topPanel.add(lblP1Score, "span");
	    this.add(topPanel, "span");
	    this.add(p1Panel, "span");
	    this.add(p2Label);
	    this.add(lblP2Score, "span");
	    this.add(p2Panel, "span");
	    cPanel.add(winLabel);
	    cPanel.add(btnRestart);
	    this.add(cPanel, "south");
	}
}
