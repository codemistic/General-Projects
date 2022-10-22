package Pieces;

public abstract class Piece {
	
	public String color;
	public char id;
	
	public Piece(String color) {
		this.color=color;
	}
	
	public abstract int[][] tracePaths(int sourceX, int sourceY, int destX, int destY);
	
	
	
}
