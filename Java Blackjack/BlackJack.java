import java.util.Scanner;
 

public class BlackJack{
   public static Scanner scan = new Scanner(System.in);
    public static void main(String[] args) {
        System.out.println("Welcome to the Java Casino:)");
        System.out.println("Are you ready to play Blackjack?");
        System.out.println("press enter to Start the game");
        
        scan.nextLine();
        //scan.close();
        int card1 = drawCard();
        int card2 = drawCard();
        System.out.println("Your two cards are\n"+getCard(card1)+"\n"+getCard(card2));
        int total = Math.min(card1,10)+Math.min(card2,10);
        System.out.println("Your total is:"+ total+"\n\n");
        int dcard1 = drawCard();
        int dcard2 = drawCard();
        int dealerTotal = Math.min(10,dcard1) + Math.min(10,dcard2);
        System.out.println("The dealer cards are\n"+getCard(dcard1)+"\n"+facedown());
        System.out.println("the other card of dealer is hidden!\n\n");

        while (true){
            String option = hitOrStay();
            if (option.equals("stay")){
               break;
            }
            int newCard = drawCard();
            total += Math.min(newCard,10);
            System.out.println("\nYou get a \n"+ getCard(newCard));
            System.out.println("Your total is: "+ total);
            if (total >21){
               System.out.println("\n****************");
               System.out.println("YOU LOSE!");
               System.out.println("DEALER WIN!");
               System.out.println("****************");
               System.exit(0);
            }
        }
        System.out.println("\nDealer's turn");
        System.out.println("\nThe dealer cards are\n"+getCard(dcard1)+"\n"+getCard(dcard2));
        System.out.println("Dealer's total is "+dealerTotal);
        while (dealerTotal<17){
         int newCard = drawCard();
         dealerTotal += Math.min(10,newCard);
         System.out.println("Dealer gets\n"+ getCard(newCard));
         System.out.println("Dealer's total is:"+dealerTotal);
        }
        if (dealerTotal>21){
         System.out.println("\n****************");
         System.out.println("YOU WIN!");
         System.out.println("DEALER LOSES!");
         System.out.println("****************");
         System.exit(0);
        }
        if (dealerTotal>total){
         System.out.println("\n****************");
         System.out.println("YOU LOSE!");
         System.out.println("DEALER WIN!");
         System.out.println("****************");
        }
        else if (dealerTotal<total){
         System.out.println("\n****************");
         System.out.println("YOU WIN!");
         System.out.println("DEALER LOSES!");
         System.out.println("****************");
        }
        else{
         System.out.println("\n****************");
         System.out.println("IT'S A TIE!");
         System.out.println("****************");
        }
    }


    public static int drawCard(){
        double cardNumber = (Math.random()*13) +1;
        return (int)cardNumber;
    }


    public static String getCard(int cardNumber){
        switch(cardNumber){
            case 1 :
               return       "   _____\n"+
                            "  |A _  |\n"+ 
                            "  | ( ) |\n"+
                            "  |(_'_)|\n"+
                            "  |  |  |\n"+
                            "  |____V|\n";
            case 2 :
               return       "   _____\n"+              
                            "  |2    |\n"+ 
                            "  |  o  |\n"+
                            "  |     |\n"+
                            "  |  o  |\n"+
                            "  |____2|\n";
            case 3 :
               return       "   _____\n" +
                            "  |3    |\n"+
                            "  | o o |\n"+
                            "  |     |\n"+
                            "  |  o  |\n"+
                            "  |____3|\n";
            case 4 :
               return       "   _____\n" +
                            "  |4    |\n"+
                            "  | o o |\n"+
                            "  |     |\n"+
                            "  | o o |\n"+
                            "  |____4|\n";
            case 5 :
               return       "   _____ \n" +
                            "  |5    |\n" +
                            "  | o o |\n" +
                            "  |  o  |\n" +
                            "  | o o |\n" +
                            "  |____5|\n";

            case 6 :
               return        "   _____ \n" +
                                "  |6    |\n" +
                                "  | o o |\n" +
                                "  | o o |\n" +
                                "  | o o |\n" +
                                "  |____6|\n";
            case 7 :
               return
               "   _____ \n" +
               "  |7    |\n" +
               "  | o o |\n" +
               "  |o o o|\n" +
               "  | o o |\n" +
               "  |____7|\n";

            case 8 :
               return    
               "   _____ \n" +
               "  |8    |\n" +
               "  |o o o|\n" +
               "  | o o |\n" +
               "  |o o o|\n" +
               "  |____8|\n";
            case 9 :
               return
               "   _____ \n" +
               "  |9    |\n" +
               "  |o o o|\n" +
               "  |o o o|\n" +
               "  |o o o|\n" +
               "  |____9|\n";
            case 10 :
               return 
               "   _____ \n" +
               "  |10  o|\n" +
               "  |o o o|\n" +
               "  |o o o|\n" +
               "  |o o o|\n" +
               "  |___10|\n";

            case 11 :
               return
               "   _____\n" +
               "  |J    |\n"+ 
               "  |     |\n"+ 
               "  |     |\n"+ 
               "  |     |\n"+ 
               "  |____J|\n";

            case 12 :
               return
               "   _____\n" +
               "  |Q    |\n"+ 
               "  |     |\n"+ 
               "  |     |\n"+ 
               "  |     |\n"+ 
               "  |____Q|\n";

            case 13 :
               return  "   _____\n" +
               "  |K    |\n"+ 
               "  |     |\n"+ 
               "  |     |\n"+ 
               "  |     |\n"+ 
               "  |____K|\n";

            default: return "This is not possible"; 
        }
    }


   public static String facedown(){
      return   "   _____ \n" +
               "  |     |\n" +
               "  |Black|\n" +
               "  |jack |\n" +
               "  |card |\n" +
               "  |_____|\n";
   }



   public static String hitOrStay(){
      System.out.println("Would you like to hit or stay");
      String response = scan.nextLine();
      response.toLowerCase();
      boolean validOrNot = !(response.equals("hit")||response.equals("stay"));
      while (validOrNot){
         System.out.println("Please enter hit or stay");
         response = scan.nextLine();
      }
      return response;
   }
}