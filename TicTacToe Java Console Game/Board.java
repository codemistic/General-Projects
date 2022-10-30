package TicTacToe;

public class Board {

	private char board[][];
	private int boardSize = 3;
	private char p1Symbol,p2Symbol;
	private int count; // number of cells that have been marked
	
	public final static int PLAYER_1_WINS = 1; // TO BE ACCESSED ON WHOLE CLASS
	public final static int PLAYER_2_WINS = 2;
	public final static int DRAW = 3;
	public final static int INCOMPLETE = 4;
	public final static int INVALID = 5;

	public Board(char p1Symbol, char p2Symbol) {
		board = new char[boardSize][boardSize];
		for (int i = 0; i < boardSize; i++) {
			for (int j = 0; j < boardSize; j++) {
				board[i][j] = ' '; // initially whole 3X3 array is filled with spaces
			}
		}
		this.p1Symbol = p1Symbol;
		this.p2Symbol = p2Symbol;
	}

	public int move(char symbol, int x, int y) {
		if (x < 0 || x >= boardSize || y < 0 || y >= boardSize || board[x][y] != ' ') {
			return INVALID;
		}
		board[x][y] = symbol;
		count++;

//		check wheather any conditions matches or not

//		Check Row
		if (board[x][0] == board[x][1] && board[x][0] == board[x][2]) {
			return symbol == p1Symbol ? PLAYER_1_WINS : PLAYER_2_WINS;
		}

//		Check coloumn
		if (board[0][y] == board[1][y] && board[0][y] == board[2][y]) {
			return symbol == p1Symbol ? PLAYER_1_WINS : PLAYER_2_WINS;
		}

//		Check first diagonal : upper left to bottom right
//		checking spaces because may be initially after move position of diagonal filled with spaces 
//		then it may lead to win
		if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
			return symbol == p1Symbol ? PLAYER_1_WINS : PLAYER_2_WINS;
		}

//		Check first diagonal : upper right to bottom left
		if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
			return symbol == p1Symbol ? PLAYER_1_WINS : PLAYER_2_WINS;
		}

		if (count == boardSize * boardSize) {
			return DRAW;
		}
		return INCOMPLETE;
	}

	public void print() {
		System.out.println("---------------------");
		for (int i = 0; i < boardSize; i++) {
			for (int j = 0; j < boardSize; j++) {
				System.out.print("| "+board[i][j]+" |");
			}
			System.out.println();
		}
		System.out.println("---------------------");
	}
}
