/* Coded by:
							Manasij Haldar, B.E.-3rd Year, CSE_AIML, Chandigarh University.
							Language used: Java, Concept Used: Thread.
*/

class Tortoise_Hare_Race
{
    public static void main(String[] args)
    {
        Thread Hare = new Runner(); 
        Thread Tortoise = new Runner();
        System.out.println("\n\n  ****RACE BEGINS***\n");
        System.out.println("\n\nTortoise\tHare\n");
        Hare.setName("Hare"); 
        Hare.setPriority(9); 
        Tortoise.setName("Tortoise");
        Tortoise.start();
        Hare.start(); 
    }
}


class Runner extends Thread
{
    public static String winner;
    public Runner() {}   

    public Runner(String string) {}

    public void race() throws InterruptedException
    {
        int distance;
        for(distance=1;distance <= 50;distance++)
        {
            if(Thread.currentThread().getName()=="Tortoise")
            {
                System.out.print("\nT"+distance);
                Thread.sleep(50);
            }
            else if (Thread.currentThread().getName()=="Hare")
            {
                    System.out.println("\t\tH"+distance);
                    Thread.sleep(25);
            }
            if(distance==25 && Thread.currentThread().getName()=="Hare")
            {
                    System.out.println("\n\nHare is sleeping\n\n"); 
                    Thread.sleep(2100);

                    System.out.println("\n\nHare Started Again\n\n"); 
            }
            if(distance==50)
            {
                if(Thread.currentThread().getName()=="Tortoise")
                {
                    System.out.print("\n___");
                    System.out.println("\n\nTortoise Completed the Race...WON...\n\n");
                }
                else if (Thread.currentThread().getName()=="Hare")
                {
                        System.out.println("\t\t___");
                        System.out.println("\n\nHare Completed the Race...LOST...\n\n");
                }
            }
            boolean isRaceWon = this.isRaceWon(distance);
            if(isRaceWon){}
            Thread.sleep(50);
        }        
    }
            
    private boolean isRaceWon(int totalDistanceCovered)
    {
        boolean isRaceWon = false;        
        if((Runner.winner==null )&&(totalDistanceCovered==100))
        {
            String winnerName = Thread.currentThread().getName(); 
            Runner.winner = winnerName; //setting the winner name 
            System.out.println("Winner is :"+Runner.winner); isRaceWon = true;
        }
            
        else if(Runner.winner==null)
        {
            isRaceWon = false;
        }
        else if(Runner.winner!=null)
        {
            isRaceWon = true;
        }
        return isRaceWon;
    }
            
    @Override
    public void run()
    {
        try 
        { 
            this.race();
        } 
        catch (InterruptedException e) 
        { 
            e.printStackTrace();
        }
        
    }
            
}
