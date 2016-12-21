package Core;
import java.util.ArrayList;
public class Hand {
	public ArrayList<Card> Cards = new ArrayList<Card>();
	public int Kicker = 0;
	public int Kicker2 = 0;
	public int getValue(){
		return getHandType().getValue();
	}
	public HandType getHandType(){
		return HandChecker.GetHandType(this);
	}
}
