package Pieces;

public class Knight {

	public Knight(int x, int y, Player player) {
		super(x, y, player);
	}
	
	public boolean pathValid(int finalX, int finalY) {
		int xDisp = Math.abs(finalX-this.x);
		int yDisp = Math.abs(finalY-this.y);
		
		return ((xDisp==2 && yDisp==1)||(xDisp==1 && yDisp==2));
	}
	
}
