package PJ4;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Table {

	// Index represents player's position
	private List<Player> players;
	private Deck deck;
	private Card[] board;
	private int bb, startStk;
	private ActionHandler handler;
	private boolean isFolded;

	public Table(int eachPlayerStack, int bigBlind) {

		startStk = eachPlayerStack;
		players = new ArrayList<Player>();
		randomizePlayerPos(players, eachPlayerStack);
		deck = new Deck();
		deck.shuffle();
		bb = bigBlind;
		board = new Card[5];
		handler = new ActionHandler(this);
		isFolded = false;
		dealCards();
		takeBlinds();

	}
	
	public boolean isFolded(){
		return isFolded;
	}
	
	public void setIsFolded(boolean b){
		isFolded = b;
	}
	
	private void randomizePlayerPos(List<Player> players, int eachPlayerStack) {

		if (new Random().nextInt(2) == 0) {
			players.add(new ComputerPlayer(eachPlayerStack, "Comp"));
			players.add(new Player(eachPlayerStack, "Player"));
		} else {
			players.add(new Player(eachPlayerStack, "Player"));
			players.add(new ComputerPlayer(eachPlayerStack, "Comp"));
		}

	}

	public void setUpNewRound(boolean isFolded) {
		if (!this.handler().isOver()) {
			movePlayerPositions();
			deck = new Deck();
			deck.shuffle();
			dealCards();
			takeBlinds();
			handler = new ActionHandler(this);
			this.isFolded = isFolded;
		}
	}

	public List<Player> getPlayers() {
		return players;
	}

	/**
	 * Move players' positions by one
	 */
	public void movePlayerPositions() {

		Player temp = players.get(0);
		players.set(0, players.get(1));
		players.set(1, temp);
	}

	public void takeBlinds() {

		players.get(0).take(bb / 2);
		players.get(1).take(bb);
	}

	public void dealCards() {

		for (Player p : players) {
			p.setCards(deck.popCard(), deck.popCard());
		}

		for (int i = 0; i < 5; i++) {
			board[i] = deck.popCard();
		}
	}

	public void shuffleDeck() {

		deck.shuffle();
	}

	public Player getPlayer(int pos) {
		return players.get(pos);
	}

	public int getBb() {
		return bb;
	}

	public int getSb() {
		return bb / 2;
	}

	public Card[] getBoard() {
		return board;
	}

	public int getPlayerPos() {

		if (players.get(0) instanceof ComputerPlayer) {
			return 1;
		} else {
			return 0;
		}

	}

	public int getComputerPos() {

		if (players.get(0) instanceof ComputerPlayer) {
			return 0;
		} else {
			return 1;
		}
	}

	public Player getPlayer() {

		return players.get(getPlayerPos());

	}

	public Player getComptuer() {
		return players.get(getComputerPos());
	}

	public int getStartingStk() {
		return startStk;
	}

	public ActionHandler handler() {
		return handler;
	}

	public void handleAction(String action) {
		handler.handleAction(action);
	}

	public static void main(String[] agrs) {

	}
}
