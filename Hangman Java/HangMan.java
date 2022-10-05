import java.util.Scanner;
import java.util.Arrays;


public class HangMan{
    public static String[] words = {"ant", "baboon", "badger", "bat", "bear","beaver", "camel", "cat", "clam", "cobra", "cougar", "coyote", "crow", "deer", "dog", "donkey", "duck", "eagle", "ferret", "fox", "frog", "goat", "goose", "hawk", "lion", "lizard", "llama", "mole", "monkey", "moose", "mouse", "mule", "newt", "otter", "owl", "panda", "parrot", "pigeon", "python", "rabbit", "ram", "rat", "raven","rhino", "salmon", "seal", "shark", "sheep", "skunk", "sloth", "snake", "spider", "stork", "swan", "tiger", "toad", "trout", "turkey","turtle", "weasel", "whale", "wolf", "wombat", "zebra"};
    public static int misses;
    public static String wrongLetters = new String();
    public static int wrongs=0;
    public static int wordNum;
    public static String actualWord;
    static Scanner scan = new Scanner(System.in);
    public static char[] displayWord;
    public static char[] array;
    public static void main(String[] args) {
        wordNum= (int)(Math.random()* (words.length));
        actualWord = words[wordNum];
        array = splitWord();
        System.out.println("=======================================\n\tWELCOME TO HANGMAN!\n=======================================\n");
        System.out.println("LET'S PLAY!\nClick Enter to start the game!");
        scan.nextLine();
        displayWord = new char[actualWord.length()];
        for (int i = 0; i < displayWord.length; i++) {
            displayWord[i] = '_';
        }


       while(true){
                printHangMan();
                printDisplayWord();
                System.out.println("Wrong guesses: "+wrongLetters);
                System.out.print("Please Enter Your guesses:");
                checkChar((scan.next().charAt(0)));
                checkWord();
                System.out.println(displayWord);
                System.out.println("=========================\n");
        }

    }
    public static void checkWord(){
        
        if(Arrays.equals(array,displayWord)){
            System.out.println("\nYou are Correct!, The word is "+actualWord+"!");
            System.out.println("\n\n============================\n\tYOU WIN!!!!\n============================\n");
            System.exit(0);
        }
        if(wrongs==6){
            System.out.println("\nThe correct word is: "+actualWord+"\n");
            printHangMan();
            System.out.println("\n\n============================\n\tYOU LOSE!!!!\n============================\n");
           
            System.exit(0);
        }
    }
    public static void checkChar(char check){
        check = Character.toLowerCase(check);
        for (int i = 0; i < array.length; i++) {
            if(check == array[i]){
                displayWord[i] = check;
            }
        }
        if(actualWord.indexOf(check)==-1){
            wrongLetters += check;
            wrongs++;
        }
    }


    public static char[] splitWord(){
        char[] array = new char[actualWord.length()];
        for (int i = 0; i < array.length; i++) {
            array[i] = actualWord.charAt(i);
        }
        return array;
    }

    public static void printDisplayWord(){
        for (int i = 0; i < displayWord.length; i++) {
            System.out.print(displayWord[i]+" ");
        }
        System.out.println("\n");
    }

    public static void printHangMan(){
        switch(wrongs){
            case 0: System.out.println("+---+\n" +
            "|   |\n" +
            "    |\n" +
            "    |\n" +   //if the user didn't miss any guesses.
            "    |\n" +
            "    |\n" +
            "=========\n");break;
            case 1: System.out.println("+---+\n" +
            "|   |\n" +
            "O   |\n" +   //if the user missed one guess.
            "    |\n" +
            "    |\n" +
            "    |\n" +
            "=========\n"); break;
            case 2: System.out.println("+---+\n" +
            "|   |\n" +
            "O   |\n" +   //if the user missed one guess.
            "|   |\n" +
            "    |\n" +
            "    |\n" +
            "=========\n"); break;
            case 3: System.out.println(" +---+\n" +
            " |   |\n" +
            " O   |\n" +   //if the user missed three guesses.
            "/|   |\n" +
            "     |\n" +
            "     |\n" +
            " =========\n"); break;
            case 4: System.out.println(" +---+\n" +
            " |   |\n" +
            " O   |\n" +   //if the user missed three guesses.
            "/|\\  |\n" +
            "     |\n" +
            "     |\n" +
            " =========\n"); break;
            case 5: System.out.println(" +---+\n" +
            " |   |\n" +
            " O   |\n" +   //if the user missed three guesses.
            "/|\\  |\n" +
            "/    |\n" +
            "     |\n" +
            " =========\n"); break;
            case 6: System.out.println(" +---+\n" +
            " |   |\n" +
            " O   |\n" +   //if the user missed three guesses.
            "/|\\  |\n" +
            "/ \\  |\n" +
            "     |\n" +
            " =========\n"); break;
            default:System.out.println("Error!!");

            }
        }
}