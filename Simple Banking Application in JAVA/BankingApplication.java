import java.util.Scanner;

public class BankingApplication {
    public static void main(String[]args)
    {
        BankAccount obj=new BankAccount("XYZ","BA0001");
        obj.showMenu();
    }
}


class BankAccount
{
    int balance;
    int previousTransaction;
    String customerName;
    String customerId;


    BankAccount(String Name,String CID)
    {
        customerName=Name;
        customerId=CID;
    }

    void deposit(int amount)
    {
        if(amount!=0)
        {
            balance=balance+amount;
            previousTransaction=amount;
        }
    }

    void withdraw(int amount)
    {
        if(amount!=0)
        {
            balance=balance-amount;
            previousTransaction=-amount;
        }
    }

   void getPreviousTransaction()
   {
       if(previousTransaction>0)
       {
           System.out.println("Deposited: "+previousTransaction);
       }
       else if(previousTransaction<0)
       {
           System.out.println("Withdrwan"+Math.abs(previousTransaction));
       }
       else
       {
           System.out.println("No Transactions occured");
       }
   }

   void showMenu()
   {
       char option='\0';
       Scanner scan=new Scanner(System.in);

       System.out.println("Welcome"+customerName);
       System.out.println("Your's Customer ID is:"+customerId);
       System.out.println("\n");
       System.out.println("A.Check Balance");
       System.out.println("B.Deposit");
       System.out.println("C.Withdraw");
       System.out.println("D.Previous Transaction");
       System.out.println("E.Exit");


       do
       {
           System.out.println("=======================================================================");
           System.out.println("Enter an option");
           System.out.println("=======================================================================");
           option=scan.next().charAt(0);
           System.out.println("\n");

           switch (option)
           {
               case 'A':
                   System.out.println("Balance="+balance);
                   break;

               case 'B':
                   System.out.println("Enter an amount to Deposit:");
                   int amount=scan.nextInt();
                   deposit(amount);
                   System.out.println("\n");
                   break;
                   
               case 'C':
                   System.out.println("Enter an amount to to Withdraw");
                   int amount2=scan.nextInt();
                   withdraw(amount2);
                   System.out.println("\n");
                   break;

               case 'D':
                   System.out.println(" ");
                   getPreviousTransaction();
                   System.out.println("\n");
                   break;

               case 'E':
                   System.out.println("***********************************************");
                   break;


               default:
                   System.out.println("Invalid Option..!!! Please Enter Again....!!!");
                   break;

           }
       }           while(option!='E');

       System.out.println("Thank You for Using Our Services");
   }
}