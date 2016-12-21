package PJ4;


/**
 * class PlayingCardException: It is used for errors related to Card and Deck
 * objects Do not modify this class!
 */
class PlayingCardException extends Exception {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	/* Constructor to create a PlayingCardException object */
	PlayingCardException() {
		super();
	}

	PlayingCardException(String reason) {
		super(reason);
	}
}
