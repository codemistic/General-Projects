package Pieces;

public class Rook extends Piece {

	public Rook(String color) {
		super(color);
		if (color.equals("white")) {
			id = 'R';
		} else {
			id = 'r';
		}
	}
	
	public int[][] tracePaths(int sourceX, int sourceY, int destX, int destY) {
		int pairs;
		
		if (sourceX==destX) {
			pairs = Math.abs(destX-sourceX);
		} else {
			pairs = Math.abs(destY-sourceY);
		}
		int[][] path = new int[2][pairs+1];
		
		
		if (sourceX==destX) {
			for (int i=0; i<pairs+1; i++) {
				path[0][i]=sourceX;
				if (sourceY<destY) {
					path[1][i]=sourceY+i;
				} else {
					path[1][i]=sourceY-i;
				}
			}
		} else {
			for (int i=0; i<pairs+1; i++) {
				path[1][i]=sourceY;
				if (sourceX<destX) {
					path[0][i]=sourceX+i;
				} else {
					path[0][i]=sourceX-i;
				}
			}
		}
		
		return path;
		
	}
	
}
