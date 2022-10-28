package TicTacToe;

import java.util.Scanner;

//manager class
public class TicTacToe {

private Player player1, player2; // classes have implemented
private Board board;

public void startGame() {
	Scanner sc = new Scanner(System.in);
	// Players input
	player1 = takePlayerInput(1);
	player2 = takePlayerInput(2); // now their might be chance that symbols of player may same
	while (player1.getSymbol() == player2.getSymbol()) {
		System.out.println("Symbol Already taken !! Pick another symbol !!");
		char symbol = sc.next().charAt(0);
		player2.setSymbol(symbol); // may be again the entered symbol is same then again prompt the message : so
									// use while loop
	}

	// Create board
	board = new Board(player1.getSymbol(), player2.getSymbol());

	// Conduct Game
	// player will enter repeatedly then use while loop

	boolean player1Turn = true; // to know which player Turn now
//	let 1: player 1 win, 2: player 2 win, 3: draw, 4: incomplete, 5: invalid move
	int status = Board.INCOMPLETE;

	while (status == Board.INCOMPLETE || status == Board.INVALID) {
		if (player1Turn) {
			System.out.println("Player 1 - " + player1.getName() + "'s turn");
			System.out.println("Enter x:");
			int x = sc.nextInt();
			System.out.println("Enter y:");
			int y = sc.nextInt();

			status = board.move(player1.getSymbol(), x, y); // to check wheather move valid or not if yes then move
															// done else tell what the status

			if (status != board.INVALID) { // easy to read also
//			invalid = if x and y are out of 2d array or it have been already filled
				player1Turn = false; // player 1 made a move
				board.print();
			} else {
				System.out.println("Invalid Move !! Try Again !!");
			}
		}

		else { // for player 2
			System.out.println("Player 2 - " + player2.getName() + "'s turn");
			System.out.println("Enter x:");
			int x = sc.nextInt();
			System.out.println("Enter y:");
			int y = sc.nextInt();
			status = board.move(player2.getSymbol(), x, y); // to check wheather move valid or not if yes then move
															// done else tell what the status
			if (status != board.INVALID) { // easy to read also
				player1Turn = true; // now its time for player 1 move
				board.print();
			} else {
				System.out.println("Invalid Move !! Try Again !!");
			}
		}
	}

	if (status == Board.PLAYER_1_WINS) {
		System.out.println("Player 1 - " + player1.getName() + " wins !!");
	} else if (status == Board.PLAYER_2_WINS) {
		System.out.println("Player 2 - " + player2.getName() + " wins !!");
	} else {
		System.out.println("Draw !!");
	}
}

private Player takePlayerInput(int num) {
	Scanner sc = new Scanner(System.in);
	System.out.print("Enter Player " + num + " name : ");
	String name = sc.nextLine();
	System.out.print("Enter Player " + num + " symbol : ");
	char symbol = sc.next().charAt(0);
	Player p = new Player(name, symbol);
	return p;
}

public static void main(String[] args) {
	TicTacToe t = new TicTacToe();
	t.startGame();
}
}