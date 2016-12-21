public package PokerGUI;
import java.awt.Dimension;
import java.awt.Insets;

import javax.swing.*;
import Core.Card;

@SuppressWarnings("serial")
public class CardButton extends JButton{
	public Card card;
	public ImageIcon imageIcon;
	public CardButton(Card card){
		super();
		this.setSize(200, 250);
		this.card = card;
		this.setIcon(new ImageIcon(card.getCardFileName()));
		this.setMaximumSize(new Dimension(200, 250));
		this.setMargin(new Insets(0,0,0,0));
		this.setBorder(null);
		this.setBackground(null);
		this.setToolTipText(card.toString());
	}
}
