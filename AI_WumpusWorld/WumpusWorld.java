import java.util.*;


class Cell{

    int stench, wumpus, breeze,pit,gold;
    int visited,pWumpus,pPit;

    Cell(){
        this.stench=0;
        this.wumpus=0;
        this.breeze=0;
        this.pit=0;
        this.gold=0;
        this.visited=0;
        this.pWumpus=0;
        this.pPit=0;
    }

}


public class WumpusWorld {
    int n=4,m=4,p=3;
    Cell [][]board=new Cell[n][m];
    Scanner sc = new Scanner(System.in);


    WumpusWorld() {
        for (int i = 0; i < n; i++) {
            for(int j=0;j<n;j++){
                board[i][j]=new Cell();
            }
        }
    }

    void fillWumpus(int i,int j){
        board[i][j].wumpus=1;

        if(i+1<=n-1) board[i+1][j].stench=1;
        if(j+1<=m-1) board[i][j+1].stench=1;
        if(i-1>=0) board[i-1][j].stench=1;
        if(j-1>=0) board[i][j-1].stench=1;
    }

    void fillPit(int i,int j){
        board[i][j].pit=1;

        if(i+1<=n-1) board[i+1][j].breeze=1;
        if(j+1<=m-1) board[i][j+1].breeze=1;
        if(i-1>=0) board[i-1][j].breeze=1;
        if(j-1>=0) board[i][j-1].breeze=1;
    }

    void fillBoard(){
        int x,y;
        System.out.println("Enter position of Wumpus");
        x=sc.nextInt();
        y=sc.nextInt();
        fillWumpus(x,y);

        System.out.println("Enter position of p");
        for(int i=0;i<p;i++){
            System.out.println(" pit "+(i+1)+" : ");
            x=sc.nextInt();
            y=sc.nextInt();
            fillPit(x,y);
        }

        System.out.println("Enter position of gold");
        x=sc.nextInt();
        y=sc.nextInt();
        board[x][y].gold=1;

        System.out.println("Printing the Environment");
        printBoard();
        System.out.println("\n");
    }

    void printBoard(){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j].gold == 1)
                    System.out.print(" G ");
                else if(board[i][j].wumpus==1)
                    System.out.print(" W ");
                else if(board[i][j].pit==1)
                    System.out.print(" P ");
                else if (board[i][j].stench == 1)
                    System.out.print(" s ");
                else if (board[i][j].breeze == 1)
                    System.out.print(" b ");

                else
                    System.out.print(" . ");
            }
            System.out.println();
        }
    }


    boolean isSafe(int x, int y)
    {
        // if (x, y outside maze) return false
        return (x >= 0 && x < n && y >= 0&& y < n &&
                ((board[x][y].pWumpus^board[x][y].pPit)==0));
    }

    void printSolution(int[][] sol)
    {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                System.out.print(
                        " " + sol[i][j] + " ");
            System.out.println();
        }
    }

    boolean solveMaze()
    {
        int [][]sol = new int[n][n];
        int score=0;
        board[n-1][0].visited=1;

        if (!solveMazeUtil(score, n-1, 0, sol)) {
            System.out.print("Solution doesn't exist");
            return false;
        }


        return true;
    }

    boolean solveMazeUtil(int score,int x, int y, int sol[][])
    {
        // if (x, y is goal) return true
        if (x >= 0 && x < n && y >= 0&& y < n &&
                board[x][y].gold==1) {
            sol[x][y] = 1;
            score = score -1 + 1000;
            printSolution(sol);
            System.out.println("Total Score: "+score);
            sol[x][y] = 1;
            return true;
        }

        if (isSafe(x, y)) {

            if (sol[x][y] == 1)
                return false;

            score-=1;
            if (board[x][y].gold==1) {
                sol[x][y] = 1;
                board[x][y].visited=1;
                return true;
            }

            sol[x][y] = 1;
            board[x][y].visited=1;

            printSolution(sol);
            System.out.println("x----------------------------x");


            if(board[x][y].breeze==1){
                if(x +1<=n-1 && board[x +1][y].visited!=1) board[x +1][y].pPit=1;
                if(y +1<=m-1 && board[x][y +1].visited!=1) board[x][y +1].pPit=1;
                if(x -1>=0 && board[x -1][y].visited!=1) board[x -1][y].pPit=1;
                if(y -1>=0 && board[x][y -1].visited!=1) board[x][y -1].pPit=1;
            }

            if(board[x][y].stench==1){
                if(x +1<=n-1 && board[x +1][y].visited!=1) board[x +1][y].pWumpus=1;
                if(y +1<=m-1 && board[x][y +1].visited!=1) board[x][y +1].pWumpus=1;
                if(x -1>=0 && board[x -1][y].visited!=1) board[x -1][y].pWumpus=1;
                if(y -1>=0 && board[x][y -1].visited!=1) board[x][y -1].pWumpus=1;
            }

            if (solveMazeUtil(score, x-1, y, sol))
                return true;
            if (solveMazeUtil(score, x, y+1, sol))
                return true;
            if (solveMazeUtil(score, x - 1, y, sol))
                return true;
            if (solveMazeUtil(score, x+1, y-1, sol))
                return true;
            sol[x][y] = 0;
            return false;
        }

        return false;
    }

    public static void main(String[] args) {
        WumpusWorld w = new WumpusWorld();
        w.fillBoard();
        w.solveMaze();
    }
}

