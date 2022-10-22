package Game;
import Pieces.*;

public class Box {

	public Piece piece;
	
	public Box(Piece piece) {
		this.piece = piece;
	}
	
	public char displayBox() {
		return piece.id;
	}
	
}
