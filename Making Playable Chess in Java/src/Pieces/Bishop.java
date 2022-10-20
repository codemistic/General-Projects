package Pieces;

public class Bishop extends Piece {
	
	public Bishop(int x, int y, Player player) {
		super(x, y, player);
	}
	
	public boolean pathValid(int finalX, int finalY) {
		int xDisp = Math.abs(finalX-this.x);
		int yDisp = Math.abs(finalY-this.y);
		
		return xDisp==yDisp;
	}
	
	
	
}
