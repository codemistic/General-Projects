package Game;
import Pieces.*;

public class Game {
	public Board chessBoard;
    public Player player1;
    public Player player2;

    /**
     * Create new instances of game properties.
     */
    public Game(Player player1, Player player2) {
        chessBoard = new Board();
        player1 = new Player("white");
        player2 = new Player("black");
        setupTeam(player1);
        setupTeam(player2);
    }

    /**
     * Sets up pieces for each player.
     * @param side Starting side of the player
     * @param player String of the player
     */
    private void setupTeam(Player player) {
        int pawn_disp = 1; //if white, we need to add the pawn above, hence positive.
        int side = 0; //if white, we need to add pieces to bottom side
        if (player.color.equals("black")) {
        	pawn_disp = -1; //else black, so we'd need to add pawn below, hence negative
        	side = 7; //else black, so we need to add pieces to top side
        }
        
        //just a faster way to iterate through for ease of typing (since I can just copy-paste each piece definition)
        int colIncrement = 0;
        
        // Rook
        
        colIncrement += 1;

        // Knight
        
        colIncrement += 1;

        // Bishop
        
        colIncrement += 1;

        // King & Queen
        
        // Pawns
        
    }


}
