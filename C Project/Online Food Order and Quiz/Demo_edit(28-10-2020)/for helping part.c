#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

void welcome();
int Registration();
int signin();
void  logIn();

void gotoxy(int x,int y);
void st(int in);        //Order Addition
void Breakfast();
void lunch();
void Dinner();
void  teaDrinks();
void Others();

int loading();
int currentStatus ();
int entertainment();
int awaitingFood ();
int information();
void backMenu();
int quiz();
int Exit ();
int payment();
int close();
void contributor();
/*re call all order function */
int  returnMenu();

struct order
{
    char name[50];
    int order_number;
    int number_of_food;
    int cost;
} p[10000];

int order_count = 0, served_count = 0, waiting_now = 0,totalcost=0;
struct signin
{
    char fname[25];
    char lname[25];
    char username[25];
    char address[100];
    int number[11];
    char password[25];
};


int main()
{
    int enter;
    welcome();

    gotoxy(8,32);
    printf("Press any key to continue :......");
    getch();

    logIn();

    scanf("%d",&enter);
    if(enter==1)
    {
        system("CLS");
        Registration();
    }
    else if(enter==2)
    {
        system("CLS");
        signin();
    }
    while (1)
    {
        int in;
        scanf ("%d", &in);
        getchar ();
        switch (in)
        {
        case 1 :
        {
            system("CLS");
            int a;
            printf("\n\n\t\t\tTotal cost = %d\n", totalcost);
            printf("\n\n\t\t\t1: BreakFast  2: Lunch  3: Dinner  4: Others  5: Tea And Drinks \n\t\t\t");
            scanf("%d",&a);
            switch(a)
            {
            case 1:
                //system("CLS");
                Breakfast();
                break;
            case 2 :                           // nested Switch case
                lunch();
                break;
            case 3 :
                Dinner();
                break;
            case 4 :
                Others();
            case 5 :
                teaDrinks();
                break;
            default:
                printf("\n\t\t\tWrong input");

            }

            break;
        }
        case 2 :
        {
            system("CLS");
            awaitingFood();
            break;
        }

        case 3 :
        {
            system("CLS");
            information();
            break;

        }
        case 4 :
        {
            system("CLS");
            Exit();
            break;
        }

        default:
            printf("\n\n\t\t\tWrong input !!!\n");
        }
    }
    return 0;
}
//
int  returnMenu()
{
    int n, in, qu;
    p[order_count].order_number = 10000+order_count;

    p[order_count].number_of_food = n;
    p[order_count].cost = 0;
    p[order_count].number_of_food = 0;

level:

    printf("\n\n\t\t  1: BreakFast  2: Lunch  3: Dinner  4: Others  5: Tea And Drinks \n\t\t\t");
    scanf ("%d", &in);
    getchar();
    switch(in)
    {

    case 1:
        system("CLS");
        Breakfast();
        break;
    case 2 :
        system("CLS");
        lunch();
        break;
    case 3 :
        system("CLS");
        Dinner();
        break;
    case 4 :
        system("CLS");
        Others();
    case 5 :
        system("CLS");
        teaDrinks();
        break;

    default :
    {

        printf ("\n\n\t\t\tInvalid selection try again\n");
        n++;
    }
    }


    char temp;

    printf ("\n\n\t\t\tDo you want to go Main-menu?(y/n)\n ");
    scanf("%c", &temp);

    if (temp == 'y' || temp == 'Y')
        goto level ;

    printf("\n\t\t\tTotal cost = %d\n", totalcost);
    system("CLS");
    printf("\n\t\t\t\tTotal cost = %d\n", totalcost);


    printf ("\n\t\t\tNumber of food ordered %d\n", p[order_count].number_of_food);
    loading();
    system("CLS");
    struct signin f;
    printf("\n\n\n");
    printf("\n\t\t\t\t\t****************************************\n");
    printf("\n\t\t\t\t\t.                                       \n");
    printf("\n\t\t\t\t\t. Thank you Mr.  for your Order          \n");
    printf("\n\t\t\t\t\t.                                       \n");
    printf("\n\t\t\t\t\t.  your total bill = %d Taka            \n",totalcost);
    printf("\n\t\t\t\t\t.                                       \n");
    printf("\n\t\t\t\t\t****************************************\n");

    order_count ++;
    printf("\n\t\t\tPress any key for Payment Option.\n");
    getch();
    system("cls");
    printf("\n\t\t\tPLease select payment method.\n");
    payment ();


}

void gotoxy(int x,int y)   //  use  cordinate
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int signin()
{
    char username[25];
    char password[25];
    FILE*HungryPanda;
    HungryPanda=fopen("HungryPanda1.txt","r");
    struct signin f;

    gotoxy(40,8);
    printf("UserName: ");

    scanf("%s",&username);
    gotoxy(40,10);
    printf("Password: ");
    scanf("%s",&password);

    while (fread(&f,sizeof(f),1,HungryPanda))
    {
        if(strcmp(username,f.username)==0 && strcmp(password,f.password)==0)
        {
            system("CLS");
            loading();
            system("CLS");
            gotoxy(20,6);
            printf("\n\t\t\tCongratulations!! You have successfully logged in...\n ");

            //("Welcome to Hungry Panda");
            welcome();

            printf("\n\n\n\t\t\tChoose any option : ");
            printf("\n\n\t\t\t\t\t1. Order\n");
            printf("\n\t\t\t\t\t2. Awaiting Food List\n");
            printf("\n\t\t\t\t\t3. Information & Quiz \n");
            printf("\n\t\t\t\t\t4. Exit\n");
             printf("\n\t\t\t\t\t Press any key : ");

        }
        else
        {
            system("CLS");
            loading();
            system("CLS");

            gotoxy(10,10);
            printf("\n\t\tOops! Wrong userID or password.Please enter the correct userID and password\n\n");

            gotoxy(10,2);
            signin();
        }
    }
    fclose(HungryPanda);
}

int Registration()
{
    FILE*HungryPanda;
    HungryPanda=fopen("HungryPanda1.txt","w");
    struct signin f;

    gotoxy(40,6);
    printf("Enter Frist name: ");
    scanf("%s",f.fname);

    gotoxy(40,8);
    printf("Enter Last name: ");
    scanf("%s",f.lname);

    gotoxy(40,10);
    printf("Enter username: ");
    scanf("%s",f.username);

    gotoxy(40,12);
    printf("Enter your address: ");
    scanf("%s",f.address);

    gotoxy(40,14);
    printf("Enter your Number: ");
    scanf("%s",f.number);

    gotoxy(40,16);
    printf("Enter your password: ");
    scanf("%s",f.password);
    fwrite(&f,sizeof(f),1,HungryPanda);
    fclose(HungryPanda);

    loading();
    system("CLS");

    printf("\n\n\n");
    printf("\n\n\n\n\n\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n\n\t\t\t\tYour User name is : ' %s ' ",f.username);

    printf("\n\n\t\t\t\tNow Sign-in to Hungry Panda with your user Name and password");
    printf("\n\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

    printf("\n\n\n\n\n\t\t\t\tPress any key to continue : ...");

    getch();
    system("CLS");

    signin();
}

// ORDER list

void Breakfast()
{
    printf("\n\t\t\t\t\t\tBreakfast\n"
           "\n\t\t\tCode  Name                                               Price(taka)\n"
           "\n\t\t\t1.   Roti------------------------------------------------- 5\n"
           "\n\t\t\t2.   Paratha---------------------------------------------- 7\n"
           "\n\t\t\t3.   Special Paratha-------------------------------------- 20\n"
           "\n\t\t\t4.   Egg Omlete-----------------half/full----------------- 15/25\n"
           "\n\t\t\t5.   Moong Dal------------------half/full----------------- 20/35\n"
           "\n\t\t\t6.   Vegetables-----------------half/full----------------- 20/25\n"
           "\n\t\t\t7.   Khichuri--------------------------------------------- 45\n"
           "\n\t\t\t8.   Special Khichuri------------------------------------- 75\n ");

    int n, in, qu;
    p[order_count].order_number = 10000+order_count;
    p[order_count].number_of_food = n;
    p[order_count].cost = 0;
    p[order_count].number_of_food = 0;

    printf ("\n\n\t\t\tHow many items you want to order? ");
    scanf ("%d", &n);
    getchar ();

    while(n--)
    {
        printf ("\n\t\t\tEnter chosen item code :- ");
        scanf("%d",&in);
        getchar();
        st(in);
    }

    printf("\n\t\t\t%d\n",p[order_count].cost);
    totalcost += p[order_count].cost;

    printf("\n\t\t\tTotal cost = %d\n", totalcost);
    printf("\n\t\t\tDo you want to go Main-menu ?(y/n)");

    char temp;
    scanf("%c", &temp);
    if (temp == 'y' || temp == 'Y')
    {
        returnMenu();
    }

    //main();

    printf ("\n\t\t\tNumber of food ordered %d\n", p[order_count].number_of_food);
    system("CLS");
    loading();
    system("CLS");


    printf("\n\n\n");
    printf("\n\t\t\t\t\t****************************************\n");
    printf("\n\t\t\t\t\t.                                       \n");
    printf("\n\t\t\t\t\t.    Thank you for your Order           \n");
    printf("\n\t\t\t\t\t.                                       \n");
    printf("\n\t\t\t\t\t.  your total bill = %d Taka            \n",totalcost);
    printf("\n\t\t\t\t\t.                                       \n");
    printf("\n\t\t\t\t\t****************************************\n");

    order_count ++;
    printf("\n\t\t\tPress any key for Payment..........\n");
    getch();

    system("cls");
    printf("\n\n\t\tPLease select payment method.\n");
    payment ();
}



void lunch()
{
    printf("\n\t\t\t\t\t\tLunch\n"
           "\n\t\t\t Code  Name                                            Price(taka)\n"
           "\n\t\t\t1.  Rice------------------------------------------------ 15 \n"
           "\n\t\t\t2.  Dal-----------------------half/full----------------- 10/20\n"
           "\n\t\t\t3.  Mixed Vegetables------------------------------------ 20\n"
           "\n\t\t\t4.  Boal Fish Curry_------------------------------------ 110\n"
           "\n\t\t\t5.  Rui Fish Curry-------------------------------------- 100\n"
           "\n\t\t\t6.  Katla Fish Curry----------2piece/3piece------------- 60/120\n"
           "\n\t\t\t7.  Pabda Fish Curry----------2piece/3piece------------- 50/110\n"
           "\n\t\t\t8.  Ilish Fish Curry----------2piece/3piece------------- 70/135\n"
           "\n\t\t\t9.  Kalbaus--------------------------------------------- 200\n"
           "\n\t\t\t10. Egg Curry------------------------------------------- 25 \n"
           "\n\t\t\t11. Chicken Curry-------------half/full----------------- 80/130\n"
           "\n\t\t\t12. Chicken Roast-------------1piece/2piece------------- 90/150\n"
           "\n\t\t\t13. Chicken Bhuna--------------------------------------- 90\n"
           "\n\t\t\t14. Mutton Curry---------------------------------------- 110\n"
           "\n\t\t\t15. Mutton Bhuna--------------half/full---------------- -140/220\n");

    int n, in, qu;
    p[order_count].order_number = 10000+order_count;
    p[order_count].number_of_food = n;
    p[order_count].cost = 0;
    p[order_count].number_of_food = 0;
    printf ("\n\n\t\t\tHow many items you want to order?\n ");
    scanf ("%d", &n);
    getchar ();
    while(n--)
    {
        printf ("\n\t\t\tEnter chosen item code :- ");
        scanf("%d",&in);
        getchar();
        st(in+8);
    }
    printf("\n\t\t\t%d\n",p[order_count].cost);

    totalcost+=p[order_count].cost;

    printf("\n\t\t\tTotal cost = %d\n", totalcost);
    printf("\n\t\t\tDo you want to go Main-menu ? (y/n)");

    char temp;
    scanf("%c", &temp);
    if (temp == 'y' || temp == 'Y')
        returnMenu();

    printf ("\n\t\t\tNumber of food ordered %d\n", p[order_count].number_of_food);
    system("CLS");
    loading();
    system("CLS");
    //gotoxy(15,4);
    struct signin f;
    printf ("\t\tThank you %s for your order. Your bill is %d taka.\n\n", p[order_count].name,totalcost);
    printf("\n\n\n");
    printf("\n\t\t\t\t\t****************************************\n");
    printf("\n\t\t\t\t\t.                                       \n");
    printf("\n\t\t\t\t\t.    Thank you for your Order           \n");
    printf("\n\t\t\t\t\t.                                       \n");
    printf("\n\t\t\t\t\t.  your total bill = %d Taka            n\n",totalcost);
    printf("\n\t\t\t\t\t.                                       \n");
    printf("\n\t\t\t\t\t****************************************\n");

    order_count ++;

    printf("\n\t\t\tPress any key for Payment............\n");
    getch();
    system("cls");
    printf("\n\t\tPLease select payment method.\n");
    payment ();
}

void Dinner()
{
    printf("\n\t\t\t\t\t\tDinner\n"
           "\n\t\t\t Code Name                                       Price(taka)\n"
           "\n\t\t\t1.  Rice----------------------------------------- 15\n"
           "\n\t\t\t2.  Dal----------------------half/full----------- 7/14\n"
           "\n\t\t\t3.  Egg Curry------------------------------------ 25\n"
           "\n\t\t\t4.  Chicken Curry------------half/full----------- 80/130\n"
           "\n\t\t\t5.  Chicken Roast----------1piece/2piece--------- 90/150\n"
           "\n\t\t\t6.  Chicken Bhuna-------------------------------- 90\n"
           "\n\t\t\t7.  Mutton Curry--------------------------------- 110\n"
           "\n\t\t\t8.  Mutton Bhuna-------------half/full----------- 140/220\n"
           "\n\t\t\t9.  Chicken Biriyani--------quarter/full---------s 60/120\n"
           "\n\t\t\t10. Mutton Biriyani--------quarter/full---------- 85/150\n"
           "\n\t\t\t11. Kachhi Biriyani--------quarter/full---------- 90/160\n");

    int n, in, qu;
    p[order_count].order_number = 10000+order_count;
    p[order_count].number_of_food = n;
    p[order_count].cost = 0;
    p[order_count].number_of_food = 0;
    printf ("\n\t\t\tHow many items you want to order?\n ");
    scanf ("%d", &n);
    getchar ();
    while(n--)
    {
        printf ("\n\t\t\tEnter chosen item code :- ");
        scanf("%d",&in);
        getchar();
        st(in+23);
    }
    printf("\n\t\t\t%d\n",p[order_count].cost);

    totalcost+=p[order_count].cost;

    printf("\n\t\t\tTotal cost = %d\n", totalcost);
    printf("\n\t\t\tDo you want to go Main-menu? (y/n)");

    char temp;
    scanf("%c", &temp);
    if (temp == 'y' || temp == 'Y')
        returnMenu();

    printf ("\n\t\t\tNumber of food ordered %d\n", p[order_count].number_of_food);
    system("CLS");
    loading();
    system("CLS");
    struct signin f;
    printf("\n\n\n");
    printf("\n\t\t\t\t\t****************************************\n");
    printf("\n\t\t\t\t\t.                                        \n");
    printf("\n\t\t\t\t\t.    Thank you For your Order            \n");
    printf("\n\t\t\t\t\t.                                        \n");
    printf("\n\t\t\t\t\t.  your total bill = %d Taka             \n",totalcost);
    printf("\n\t\t\t\t\t.                                        \n");
    printf("\n\t\t\t\t\t****************************************\n");

    order_count ++;
    printf("\n\t\t\tPress any key for Payment........\n");
    getch();
    system("cls");
    printf("\n\n\t\tPLease select payment method.\n");
    payment ();


}

void Others()
{
    printf("\n\t\t\t\t\t\tOthers\n"
           "\n\t\t\tCode  Name                                       Price(taka)\n"
           "\n\t\t\t1.  Naan---------------------half/full-----------  15/25\n"
           "\n\t\t\t2.  Special Naan-------------half/full-----------  20/40\n"
           "\n\t\t\t3.  Chicken Grill------------half/full----------- 180/350\n"
           "\n\t\t\t4.  Chicken Chap-------------half/full----------- 155/210\n"
           "\n\t\t\t5.  Chicken BBQ--------------half/full----------- 120/240\n"
           "\n\t\t\t6.  Chicken Tikka------------half/full----------- 100/180\n"
           "\n\t\t\t7.  Chicken Korai------------half/full----------- 55/110\n"
           "\n\t\t\t8.  Vegetable Fried Rice-----quarter/full-------- 60/240\n"
           "\n\t\t\t9.  Chicken Fried Rice-------quarter/full-------- 120/480\n");

    int n, in, qu;
    p[order_count].order_number = 10000+order_count;
    p[order_count].number_of_food = n;
    p[order_count].cost = 0;
    p[order_count].number_of_food = 0;
    printf ("\n\t\t\tHow many items you want to order?\n ");
    scanf ("%d", &n);
    getchar ();
    while(n--)
    {
        printf ("\n\t\t\tEnter chosen item code :- ");
        scanf("%d",&in);
        getchar();
        st(in + 34);
    }
    printf("\n\t\t\t%d\n",p[order_count].cost);

    totalcost+=p[order_count].cost;
    //main();


    printf("\n\t\t\tTotal cost = %d\n", totalcost);
    printf("\n\t\t\tDo you want to go Main-menu? (y/n)");

    char temp;
    scanf("%c", &temp);
    if (temp == 'y' || temp == 'Y')
        returnMenu();

    printf ("\n\t\t\tNumber of food ordered %d\n", p[order_count].number_of_food);
    system("CLS");
    loading();
    system("CLS");
    struct signin f;
    printf("\n\n\n");
    printf("\n\t\t\t\t\t****************************************\n");
    printf("\n\t\t\t\t\t.                                        \n");
    printf("\n\t\t\t\t\t.    Thank you For your Order            \n");
    printf("\n\t\t\t\t\t.                                        \n");
    printf("\n\t\t\t\t\t.  your total bill = %d Taka             \n",totalcost);
    printf("\n\t\t\t\t\t.                                        \n");
    printf("\n\t\t\t\t\t****************************************\n");

    order_count ++;

    printf("\n\t\t\tPress any key for Payment.............\n");
    getch();
    system("cls");
    printf("\n\n\t\tPLease select payment method.\n");
    payment ();
}

void  teaDrinks()
{
    printf("\n\t\t\t\t\t\tTea & Drinks\n"
           "\n\t\t\tCode  Name                                               Price\n"
           "\n\t\t\t1.   Tea------------------------------------------------- 15 |=\n"
           "\n\t\t\t2.   Coffee--------------------hot/cold------------------ 30/45 |=\n"
           "\n\t\t\t3.   Cold Drinks---------------250mg/500mg--------------- 20/35 |=\n"
           "\n\t\t\t4.   Lassi----------------------------------------------- 40 |=\n"
           "\n\t\t\t5    Special coffee-------------------------------------- 50 |=\n"
           "\n\t\t\t6.   Special lassi--------------------------------------- 70 |=\n"
           "\n\t\t\t7.   Cappuccino------------------------------------------ 90 |=\n");

    int n, in, qu;
    p[order_count].order_number = 10000+order_count;
    p[order_count].number_of_food = n;
    p[order_count].cost = 0;
    p[order_count].number_of_food = 0;
    printf ("\n\t\t\tHow many items you want to order?\n ");
    scanf ("%d", &n);
    getchar ();
    while(n--)
    {
        printf ("\n\t\t\tEnter chosen item code :- ");
        scanf("%d",&in);
        getchar();
        st(in + 43);
    }
    printf("\n\t\t\t%d\n",p[order_count].cost);

    totalcost+=p[order_count].cost;

    printf("\n\t\t\tTotal cost = %d\n", totalcost);
    printf("\n\t\t\tDo you want to go Main-menu? (y/n)");

    char temp;
    scanf("%c", &temp);
    if (temp == 'y' || temp == 'Y')
        returnMenu();

    printf ("\n\t\t\tNumber of food ordered %d\n", p[order_count].number_of_food);
    system("CLS");
    loading();
    system("CLS");
    struct signin f;
    printf("\n\n\n");
    printf("\n\t\t\t\t\t****************************************\n");
    printf("\n\t\t\t\t\t.                                       \n");
    printf("\n\t\t\t\t\t.     Thank you For your Order          \n");
    printf("\n\t\t\t\t\t.                                       \n");
    printf("\n\t\t\t\t\t.  your total bill = %d Taka            \n",totalcost);
    printf("\n\t\t\t\t\t.                                       \n");
    printf("\n\t\t\t\t\t****************************************\n");

    order_count ++;

    printf("\n\t\t\tPress any key for Payment.............\n");
    getch();
    system("cls");
    printf("\n\n\t\tPLease select payment method.\n");
    payment ();
}

void st(int in)
{
    int qu;
    switch(in)
    {
    case 1 :
    {
        printf ("\n\t\t\t Roti \n");
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food += qu;
        p[order_count].cost += (5*qu);

        break;
    }
    case 2 :
    {
        printf ("\n\t\t\t  Paratha \n");
        printf ("\n\t\t\tPlease enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food +=qu;
        p[order_count].cost += (7*qu);

        break;
    }
    case 3 :
    {
        printf ("\n\t\t\t Special Paratha\n");
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food +=qu;
        p[order_count].cost += (20*qu);

        break;
    }
    case 4 :
    {
        printf ("\n\t\t\t Enter the size of Egg Omlete:  1. half  2. full\n");
        int i;
        scanf ("%d", &i);
        getchar();
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food +=qu;
        if (i==1)
        {
            p[order_count].cost += (15*qu);

        }
        else if (i==2)
        {
            p[order_count].cost += (25*qu);

        }
        break;

    }
    case 5 :
    {
        printf ("\n\t\t\t Enter the size of Moong Dal: 1. half  2. full\n");
        int i;
        scanf ("%d", &i);
        getchar();
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food +=qu;
        if (i==1)
            p[order_count].cost += (20*qu);
        else
            p[order_count].cost += (35*qu);
        break;
    }
    case 6 :
    {

        printf ("\n\t\t\t Enter the size of Vegetables: 1. half  2. full\n");
        int i;
        scanf ("%d", &i);
        getchar();

        printf ("\n\t\t\t Please enter the quantity: ");

        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food +=qu;
        if (i==1)
            p[order_count].cost += (20*qu);
        else
            p[order_count].cost += (25*qu);
        break;
    }
    case 7 :
    {
        printf ("\n\t\t\t Khichuri\n");
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food +=qu;
        p[order_count].cost += (45*qu);
        break;
    }
    case 8 :
    {
        printf ("\n\t\t\t Special khichuri\n");
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food +=qu;
        p[order_count].cost += (75*qu);
        break;
    }
    case 9 :
    {
        printf ("\n\t\t\t Rice\n");
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food +=qu;
        p[order_count].cost += (20*qu);
        break;
    }
    case 10 :
    {
        printf ("\n\t\t\t Enter the size of Dal: 1. half  2. full\n");
        int i;
        scanf ("%d", &i);
        getchar();
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food +=qu;
        if (i==1)
            p[order_count].cost += (10*qu);
        else
            p[order_count].cost += (20*qu);
        break;
    }
    case 11 :
    {
        printf ("\n\t\t\t Mixed Vegetables\n");
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food +=qu;
        p[order_count].cost += (20*qu);
        break;
    }
    case 12 :
    {
        printf ("\n\t\t\t Boal Fish Curry\n");
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food +=qu;
        p[order_count].cost += (110*qu);
        break;
    }
    case 13 :
    {
        printf ("\n\t\t\t Rui Fish Curry\n");
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food +=qu;
        p[order_count].cost += (100*qu);
        break;
    }
    case 14 :
    {
        printf ("\n\t\t\t Enter the size of Katla Fish Curry: 1. 2pice 2.3pice\n");
        int i;
        scanf ("%d", &i);
        getchar();
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food +=qu;
        if (i==1)
            p[order_count].cost += (60*qu);
        else
            p[order_count].cost += (120*qu);
        break;
    }
    case 15 :
    {
        printf ("\n\t\t\t Enter the size of Pabda Fish Curry: 1. 2pice 2.3pice\n");
        int i;
        scanf ("%d", &i);
        getchar();
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food +=qu;
        if (i==1)
        {
            p[order_count].cost += (50*qu);
        }
        else
        {
            p[order_count].cost += (110*qu);
        }
        break;
    }
    case 16 :
    {
        printf ("\n\t\t\t Enter the size of Ilish Fish Curry: 1. 2pice 2.3pice\n");
        int i;
        scanf ("%d", &i);
        getchar();
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food +=qu;
        if (i==1)
            p[order_count].cost += (70*qu);
        else
            p[order_count].cost += (135*qu);
        break;
    }
    case 17 :
    {
        printf ("\n\t\t\t Kalbaus\n");
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food +=qu;
        p[order_count].cost += (200*qu);
        break;
    }
    case 18 :
    {
        printf ("\n\t\t\t Egg Curry\n");
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food +=qu;
        p[order_count].cost += (25*qu);
        break;
    }
    case 19 :
    {
        printf ("\n\t\t\t Enter the size of Chicken Curry: 1.half 2.full\n");
        int i;
        scanf ("%d", &i);
        getchar();
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food +=qu;
        if (i==1)
            p[order_count].cost += (80*qu);
        else
            p[order_count].cost += (130*qu);
        break;
    }
    case 20 :
    {
        printf ("\n\t\t\t Enter the size of Chicken Roast: 1.pice 2.2 pice\n");
        int i;
        scanf ("%d", &i);
        getchar();
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food +=qu;
        if (i==1)
        {
            p[order_count].cost += (90*qu);
        }
        else
        {
            p[order_count].cost += (90*qu);
        }
        break;
    }
    case 21 :
    {
        printf ("\n\t\t\t Chicken Bhuna\n");
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food +=qu;
        p[order_count].cost += (90*qu);
        break;
    }
    case 22 :
    {
        printf ("\n\t\t\t Mutton Curry\n");
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food +=qu;
        p[order_count].cost += (110*qu);
        break;
    }
    case 23 :
    {
        printf ("\n\t\t\t Enter the size of Mutton Bhuna: 1.half 2.full\n");
        int i;
        scanf ("%d", &i);
        getchar();
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food +=qu;
        if (i==1)
            p[order_count].cost += (140*qu);
        else
            p[order_count].cost += (220*qu);
        break;
    }
    case 24 :
    {
        printf ("\n\t\t\t Rice\n");
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food +=qu;
        p[order_count].cost += (15*qu);
        break;




    }
    case 25 :
    {
        printf ("\n\t\t\t Enter the size of Dal: 1. half  2.full\n");
        int i;
        scanf ("%d", &i);
        getchar();
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food += qu;
        if (i==1)
            p[order_count].cost += (7*qu);
        else
            p[order_count].cost += (14*qu);
        break;
    }
    case 26 :
    {
        printf ("\n\t\t\t Egg Curry\n");
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food +=qu;
        p[order_count].cost += (25*qu);
        break;
    }
    case 27 :
    {
        printf ("\n\t\t\t Enter the size of Chicken curry: 1. half  2.full\n");
        int i;
        scanf ("%d", &i);
        getchar();
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food +=qu;
        if (i==1)
            p[order_count].cost += (80 * qu);
        else
            p[order_count].cost += (135 * qu);
        break;
    }
    case 28 :
    {
        gotoxy(56,10);
        printf ("\n\t\t\t Enter the size of Chicken Roast: 1. half  2.full\n");
        int i;
        scanf ("%d", &i);
        getchar();
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food += qu;
        if (i==1)
            p[order_count].cost += (90 * qu);
        else
            p[order_count].cost += (150 * qu);
        break;
    }
    case 29 :
    {
        printf ("\n\t\t\t Chicken Bhuna\n");
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food +=qu;
        p[order_count].cost += (90*qu);
        break;
    }
    case 30 :
    {
        printf ("\n\t\t\t Mutton Curry\n");
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food +=qu;
        p[order_count].cost += (110*qu);
        break;
    }
    case 31 :
    {
        printf ("\n\t\t\t Enter the size of Mutton Buna: 1. half  2.full\n");
        int i;
        scanf ("%d", &i);
        getchar();
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food += qu;
        if (i==1)
            p[order_count].cost += (140 * qu);
        else
            p[order_count].cost += (220 * qu);
        break;
    }
    case 32 :
    {
        printf ("\n\t\t\t Enter the size of Chicken Biriyani: 1. quarter  2.full\n");
        int i;
        scanf ("%d", &i);
        getchar();
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food += qu;
        if (i==1)
            p[order_count].cost += (60 * qu);
        else
            p[order_count].cost += (120 * qu);
        break;
    }
    case 33 :
    {
        printf ("\n\t\t\t Enter the size of Mutton Biriyani: 1. quarter  2.full\n");
        int i;
        scanf ("%d", &i);
        getchar();
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food += qu;
        if (i==1)
            p[order_count].cost += (85 * qu);
        else
            p[order_count].cost += (150 * qu);
        break;
    }
    case 34 :
    {
        printf ("\n\t\t\t Enter the size of  Kachhi  Biriyani: 1. quarter  2.full\n");
        int i;
        scanf ("%d", &i);
        getchar();
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food += qu;
        if (i==1)
            p[order_count].cost += (90 * qu);
        else
            p[order_count].cost += (160 * qu);
        break;
    }
    case 35 :
    {
        printf ("\n\t\t\t Enter the size of  Naan: 1. half  2.full\n");
        int i;
        scanf ("%d", &i);
        getchar();
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food += qu;
        if (i==1)
            p[order_count].cost += (15 * qu);
        else
            p[order_count].cost += (25 * qu);
        break;
    }
    case 36 :
    {
        printf ("\n\t\t\t Enter the size of Special Naan: 1. half  2.full\n");
        int i;
        scanf ("%d", &i);
        getchar();
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food += qu;
        if (i==1)
            p[order_count].cost += (20 * qu);
        else
            p[order_count].cost += (40 * qu);
        break;
    }
    case 37 :
    {
        printf ("\n\t\t\t Enter the size of   Chicken Grill : 1. half  2.full\n");
        int i;
        scanf ("%d", &i);
        getchar();
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food += qu;
        if (i==1)
            p[order_count].cost += (180 * qu);
        else
            p[order_count].cost += (350 * qu);
        break;
    }
    case 38 :
    {
        printf ("\n\t\t\t Enter the size of   Chicken Chap : 1. half  2.full\n");
        int i;
        scanf ("%d", &i);
        getchar();
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food += qu;
        if (i==1)
            p[order_count].cost += (155 * qu);
        else
            p[order_count].cost += (210 * qu);
        break;
    }
    case 39 :
    {
        printf ("\n\t\t\t Enter the size of   Chicken BBQ : 1. half  2.full\n");
        int i;
        scanf ("%d", &i);
        getchar();
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food += qu;
        if (i==1)
            p[order_count].cost += (120 * qu);
        else
            p[order_count].cost += (240 * qu);
        break;
    }
    case 40 :
    {
        printf ("\n\t\t\t Enter the size of   Chicken Tikka : 1. half  2.full\n");
        int i;
        scanf ("%d", &i);
        getchar();
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food += qu;
        if (i==1)
            p[order_count].cost += (110 * qu);
        else
            p[order_count].cost += (220 * qu);
        break;
    }
    case 41 :
    {
        printf ("\n\t\t\t Enter the size of   Chicken Korai : 1. half  2.full\n");
        int i;
        scanf ("%d", &i);
        getchar();
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food += qu;
        if (i==1)
            p[order_count].cost += (55 * qu);
        else
            p[order_count].cost += (110 * qu);
        break;
    }
    case 42 :
    {
        printf ("\n\t\t\t Enter the size of Vegetable fried rice : 1. quarter  2.full\n");
        int i;
        scanf ("%d", &i);
        getchar();
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food += qu;
        if (i==1)
            p[order_count].cost += (60 * qu);
        else
            p[order_count].cost += (240 * qu);
        break;
    }
    case 43 :
    {
        printf ("\n\t\t\t Enter the size of  Chicken fried rice : 1. quarter  2.full\n");
        int i;
        scanf ("%d", &i);
        getchar();
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food += qu;
        if (i==1)
            p[order_count].cost += (120 * qu);
        else
            p[order_count].cost += (480 * qu);
        break;
    }
    case 44 :
    {
        printf ("\n\t\t\t Tea\n");
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food +=qu;
        p[order_count].cost += (15*qu);
        break;
    }
    case 45:
    {
        printf ("\n\t\t\t Enter the size of  Coffee: 1. Hot  2.Cold\n");
        int i;
        scanf ("%d", &i);
        getchar();
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food += qu;
        if (i==1)
            p[order_count].cost += (30 * qu);
        else
            p[order_count].cost += (45 * qu);
        break;
    }
    case 46:
    {
        printf ("\n\t\t\t Enter the size of  Coffee: 1. 250 mg  2. 500 mg\n");
        int i;
        scanf ("%d", &i);
        getchar();
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food += qu;
        if (i==1)
            p[order_count].cost += (10 * qu);
        else
            p[order_count].cost += (35 * qu);
        break;
    }
    case 47 :
    {
        printf ("\n\t\t\t Lassi\n");
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food +=qu;
        p[order_count].cost += (40*qu);
        break;
    }
    case 48 :
    {
        printf ("\n\t\t\t Special coffee\n");
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food +=qu;
        p[order_count].cost += (50*qu);
        break;
    }
    case 49 :
    {
        printf ("\n\t\t\t Special lassi\n");
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food +=qu;
        p[order_count].cost += (70*qu);
        break;
    }
    case 50 :
    {
        printf ("\n\t\t\t Special lassi\n");
        printf ("\n\t\t\t Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        p[order_count].number_of_food +=qu;
        p[order_count].cost += (90*qu);
        break;
    }
    default :
    {
        printf ("\n\t\t\t Invalid selection try again\n");
    }
    }
}


int loading()
{
    int i,j,a;
    printf("\n\t\t\t LOADING...\n\t\t\t");
    for(i=0; i<=11; i++)
    {
        for(j=0; j<100000000; j++)
            a=j;
        printf("%c",177);
    }
}


int payment()
{
    int card,cash,enter5,enter7,code,pt;
    system ("COLOR 2");
    //gotoxy(20,10);
    printf("\n\n\n\n");
    printf("\n\t\t\tEnter'1' : Pay with Card or Mobile account\n");
    printf("\n\t\t\tEnter'2' : Cash on delivery\n");
    printf("\n\t\t\tEnter'3' : For Back\n");

    //puts("Enter'1'Pay with Card or Mobile account\nEnter'2'Cash of delivery\nEnter'3'For Back\n");
    scanf("%d",&pt);
    switch (pt)
    {
    case 1 :
        system("CLS");
        //puts("1.visa\n2.Your Bank\n3.Natwest\n4.Bkash\n5.Rocket\n6.Nagad\n\n\nEnter'0'For Back\n");
        printf("\n\n\n\n");
        printf("\n\t\t\tEnter '1' : V I S A\n");
        printf("\n\t\t\tEnter '2' : B A N K\n");
        printf("\n\t\t\tEnter '3' : N A T W E S T\n");
        printf("\n\t\t\tEnter '4' : B-kash\n");
        printf("\n\t\t\tEnter '5' : R O C K E T\n");
        printf("\n\t\t\tEnter '6' : N A G A D\n");
        printf("\n\t\t\tEnter '0' : FOR BACK\n");

        scanf("%d",&enter5);
        if(enter5==1)
        {
            system("CLS");
            // puts("Enter your card number:");
            printf("\n\t\t\tEnter your card number: ");

            scanf("%d",&card);
            //puts("Enter your code:");
            printf("\n\t\t\tEnter your code : ");
            scanf("%d",&code);
            loading();
            system("CLS");
        }
        if(enter5==2)
        {
            system("CLS");
            printf("\n\t\t\tEnter your card number: ");
            //puts("Enter your card number:");
            scanf("%d",&card);
            printf("\n\t\t\tEnter your code : ");
            // puts("Enter your code:");
            scanf("%d",&code);
            loading();
            system("CLS");
        }
        if(enter5==3)
        {
            system("CLS");
            printf("\n\t\t\tEnter your card number: ");
            //puts("Enter your card number:");
            scanf("%d",&card);
            printf("\n\t\t\tEnter your code : ");
            //puts("Enter your code:");
            scanf("%d",&code);
            loading();
            system("CLS");
        }

        if(enter5==4)
        {
            system("CLS");
            printf("\n\t\t\tEnter Bkash number: ");
            scanf("%d",&card);
            printf("\n\t\t\tEnter B-kash Pin : ");
            scanf("%d",&code);
            loading();
            system("CLS");

        }

        if(enter5==5)
        {
            system("CLS");
            printf("\n\t\t\tEnter your Rocket number: ");
            //puts("Enter your Rocket number:");
            scanf("%d",&card);
            //puts("Enter your Rocket Pin:");
            printf("\n\t\t\tEnter Rocket Pin : ");
            scanf("%d",&code);
            loading();
            system("CLS");
        }

        if(enter5==6)
        {
            system("CLS");
            printf("\n\t\t\tEnter your Nagad number: ");
            //puts("Enter your Nagad number:");
            scanf("%d",&card);
            printf("\n\t\t\tEnter Nagad Pin : ");
            //puts("Enter your Nagad Pin:");
            scanf("%d",&code);
            loading();
            system("CLS");
        }

        if(enter5==0)
        {
            system("CLS");
            payment();
        }
        system("CLS");
        //puts("Your Food is on the way please wait 20 minutes.");
        printf("\n\n\n\t\t\tYour Food is on the way please wait 20 minutes.");

        printf("\n\n\n");
        printf("\n\t\t\tEnter '1' : Awaitng Food List\n\t\t\tEnter '2' : Current Status\n\t\t\tEnter '3' : Both\n");
        scanf("%d",&enter7);
        if(enter7==1)
        {
            system("CLS");
            awaitingFood();
        }
        else if(enter7==2)
        {
            system("CLS");
            currentStatus();
        }
        else if(enter7==3)
        {
            system("CLS");
            awaitingFood();
            currentStatus();
        }
        printf("\n\t\t\tIf you want to pass your waiting time\n");
        int enter9;
        printf("\n\t\t\tEnter'1'For Entertainment\n\t\t\t\tOR\n\t\t\tEnter'0'For Exit\n");
        scanf("%d",&enter9);
        if(enter9==1)
        {
            system("CLS");
            int enter10;
            printf("\n\t\t\tEnter'1' : For Information\n\t\t\tEnter'2' : For Food quiz\n\t\t\tEnter'0' :For Exit\n");
            scanf("%d",&enter10);

            if(enter10==1)
            {
                system("CLS");
                information();
                printf("\n\n\n\n");
                Exit();
            }
            else if(enter10==2)
            {
                system("CLS");
                quiz();
                Exit();
            }
            else if(enter10==0)
            {
                system("CLS");
                Exit();
            }
        }
        else if(enter9==0)
        {
            system("CLS");
            Exit();
        }


        break;
    case 2 :
        loading();
        system("CLS");
        //puts("Please keep the amount on delivery time");
        printf("\n\t\t\tPlease keep the amount on delivery time");
        printf("\n\t\t\tEnter'1' : Awaiting Food\n\t\t\tEnter'2' : Current Status\n\t\t\tEnter'3' : Both\n\t\t\tEnter'0' : For Back\n");
        scanf("%d",&enter7);
        if(enter7==1)
        {
            system("CLS");
            awaitingFood();
        }
        else if(enter7==2)
        {
            system("CLS");
            currentStatus();
        }
        else if(enter7==3)
        {
            system("CLS");
            awaitingFood();
            currentStatus();
        }
        else if(enter7==0)
        {
            system("CLS");
            payment();
        }
        int enter15,enter16;
        printf("\n\t\t\tIf you want You can check our Others Features in Entertainment\n");
        printf("\n\t\t\tEnter'1'For Entertainment\n\t\t\t\tOR\n\t\t\tEnter'0'For Exit\n");
        scanf("%d",&enter15);
        if(enter15==1)
        {
            system("CLS");
            int enter16;
            printf("\n\t\t\tEnter'1' : For Information\n\t\t\tEnter'2' : For Food quiz\n\t\t\tEnter'0' : For Exit\n");
            scanf("%d",&enter16);

            if(enter16==1)
            {
                system("CLS");
                information();
                printf("\n\n\n\n");
                Exit();
            }
            else if(enter16==2)
            {
                system("CLS");
                quiz();
                Exit();
            }
            else if(enter16==0)
            {
                system("CLS");
                Exit();
            }
        }
        else if(enter15==0)
        {
            system("CLS");
            Exit();
        }
        break;
    case 3:
        system("CLS");
        backMenu();
        break;

    }
}




int awaitingFood ()
{
    if(order_count == 0)
    {
        printf("\n\n\n\n");
        printf ("\n\t\t\tTotal order taken: %d\n", (order_count));
        printf ("\n\t\t\tNumber of Currently waiting to be served: %d\n", (order_count-served_count));
        printf ("\n\t\t\tCurrently preparing food for order no. %d\n\n", p[served_count].order_number);

        printf("\n\t For order Press : 1\n");
        int p;
        scanf("%d",&p);

        if(p==1)
            returnMenu();
    }

    else
    {
        printf("\n\n\n\n");
        printf ("\n\t\t\tTotal order taken: %d\n", (order_count));
        printf ("\n\t\t\tNumber of Currently waiting to be served: %d\n", (order_count-served_count));
        printf ("\n\t\t\tCurrently preparing food for order no. %d\n\n", p[served_count].order_number);
    }
}

int Exit ()
{
    int enter2,enter3,enter4,enter6,et;
    system ("COLOR 2");
    printf("\n\n\t\t\tThanks for chosen Hungry Panda\n");
    printf("\n\t\t\tIf you are not satisfied with our service then report our restaurant or else Rating our restaurant.\n");
    printf("\n\t\t\tEnter'1' : Rating\n\t\t\tEnter'2' : Report\n");
    scanf("%d",&et);
    switch(et)
    {
    case 1 :
        system("CLS");
        printf("\n\t\t\tEnter'1' : for 5 STAR\n\t\t\tEnter'2' : for 3 STAR\n\t\t\tEnter'3' : for 1 STAR\n");
        scanf("%d",&enter3);
        if(enter3==1)
        {
            system("CLS");
            system ("COLOR 5");
            printf("\n\t\t\tWow! THANK YOU FOR YOUR RATING\n");
            printf("\n\t\t\tEnter'1'for Main-Manu\n\t\t\tEnter'2'for exit\n");
            scanf("%d",&enter6);
            if(enter6==1)
            {
                returnMenu();
            }
            else if(enter6==2)
            {

                contributor();
                close();
            }
        }
        else if(enter3==2)
        {
            system("CLS");
            system ("COLOR 3");
            printf("\n\t\t\tTHNAK YOU FOR YOUR RATING\n");
            printf("\n\t\t\tEnter'1'for Main-Manu\n\t\t\tEnter'2'for exit\n");
            scanf("%d",&enter6);
            if(enter6==1)
            {
                returnMenu();
            }
            else if(enter6==2)
            {
                system("CLS");
                contributor();
                close();
            }
        }
        else if(enter3==3)
        {
            system("CLS");
            system ("COLOR 4");
            printf("\n\t\t\tTHANK YOU\n");
            printf("\n\t\t\tEnter'1'for Main-Manu\n\t\t\tEnter'2'for exit\n");
            scanf("%d",&enter6);
            if(enter6==1)
            {
                returnMenu();
            }
            else if(enter6==2)
            {
                system("CLS");
                contributor();
                close();
            }
        }
        break;
    case 2 :
        system("CLS");
        printf("\n\t\t\t1.I have no mood for rating thats why choice report option\n\t\t\t2.Food quality not good\n\t\t\t3.late delivery.\n");
        scanf("%d",&enter4);
        if(enter4==1)
        {
            system("CLS");
            system ("COLOR 4");
            printf("\n\t\t\tOK!when you are in mood rate our restaurant.THANK YOU");
            printf("\n\t\t\tEnter'1' : for Main-Manu\n\t\t\tEnter'2' : for exit\n");
            scanf("%d",&enter6);
            if(enter6==1)
            {
                main();
            }
            else if(enter6==2)
            {
                system("CLS");
                contributor();
                close();
            }
        }
        else if(enter4==2)
        {
            system("CLS");
            system ("COLOR 5");
            printf("\n\t\t\tOK!We will improve our food Quality.THANK YOU");
            printf("\n\t\t\tEnter'1'for Main-Manu\n\t\t\tEnter'2'for exit\n");
            scanf("%d",&enter6);
            if(enter6==1)
            {
                main();
            }
            else if(enter6==2)
            {
                system("CLS");
                contributor();
                close();
            }
        }
        else if(enter4==3)
        {
            system("CLS");
            system ("COLOR 3");
            printf("\n\t\t\tOK!We will deliver our food faster.THANK YOU");
            printf("\n\t\t\tEnter '1' for Main-Manu\n\t\t\tEnter '2' for exit\n");
            scanf("%d",&enter6);
            if(enter6==1)
            {
                main();
            }
            else if(enter6==2)
            {
                system("CLS");
                contributor();

            }
        }
        break;
    }
}
int  currentStatus()
{
    if (order_count==0)
    {
        printf ("\n\t\t\tPlease order first\n");
        printf ("\n\t\t\tOrder no. %d\n", p[served_count].order_number);
        int enter8;
        printf("\n\t\t\tEnter'1'for Order\n");
        scanf("%d",&enter8);
        if(enter8==1)
        {
            returnMenu();
        }

    }
    else
    {
        printf ("\n\t\t\tAll order served\n");
        printf ("\n\t\t\tOrder no. %d by is ready\n", p[served_count].order_number);

    }

    served_count++;
}
int close()
{
    exit(0);
}
int entertainment()
{
    int enter9;
    printf("\n\t\t\tEnter'1'For Entertainment\n");
    scanf("%d",&enter9);
    if(enter9==1)
    {
        system("CLS");
        int enter10;
        printf("\n\t\t\tEnter'1'For Information\n\t\t\t\n");
        scanf("%d",&enter10);

        if(enter10==1)
        {
            system("CLS");
            information();
            Exit();
        }

        else if(enter10==0)
        {
            system("CLS");
            entertainment();
            Exit();
        }
    }

}
int information()
{
    system("CLS");
    int n,enter12;

    printf("\n\t\t\t1. Trip Advisor\t\t2. News\t\t3. Best Books\t \t4.Quiz\t\n");
    printf("\n\t\t\tEnter any number please : ");

    scanf("%d",&n);

    switch(n)
    {
    /*About Green Sylhet*/

    case 1:
        system("cls");

        printf("\n\n\n");

        printf("\n\t\t\t\t\t************************************************\n");
        printf("\n\t\t\t\t\t|----Welcome to EVER GREEN SYLHET ...!!----|\n");
        printf("\n\t\t\t\t\t************************************************\n");

        printf("\n\tEnter any number (3 to infinite)\n");

        int m,n; //local variable

        scanf("%d",&m);
        printf("\n");

        char *naturePark[]= {"Ratargul Swamp Forest","Bisnakandi\t\t","Jaflong\t\t","Lalakhal\t\t","Khadimnagar National Park","Tilagor Eco Park\t","Sreemangol Tea Garden","Madavkundo\t\t","Malnichara Tea state","Lakkatura Tea Garden"};

        char *others[] = {"Shahi Edgah","Shajalal Mazar","Surma Bridge","Kadir Bazar Bridge","King Bridge and Ali Amzad clock","Pantumai Waterfall","Rema-kalenga Wildlife","Adventure World","Osmani Museum","Osmani Park","Dreamlend","Jakariya City"};

        while(m--)
        {
            printf("\n\n\n\t\t1.  N A T U R E and  P A R K  \t2. O T H E R S ");
            printf("\n\n\tchose one !!\n");
            scanf("%d",&n);
            switch(n)
            {
            case 1:
                system("cls");

                printf("\n\t\t\t\t\t************************************\n");
                printf("\n\t\t\t\\t|----- Most Visitor spot in Sylhet  -----|\n");
                printf("\n\t\t\t\t\t*************************************\n\n\n");

                for(int m = 0 ; m < 10; m++)
                {
                    printf("\n\t%d = %s\n",m+1,naturePark[m]);
                }
                break;

            case 2:
                system("cls");
                printf("\n\t\t\t\t\t************************************\n");
                printf("\n\t\t\t\t\t|----- Tourist Spot in Sylhet  -----|\n");
                printf("\n\t\t\t\t\t*************************************\n\n");

                for(int o = 0 ; o < 12; o++)
                {
                    printf("\n\t%d = %s\n",o+1,others[o]);
                }
                break;

            default:
                printf("\n\n\t\t\tWrong  input -----!!!!\n");
                printf("\n\t\t\tPlease input between 1 - 2\n");
            }
            printf("\n\n\t\t\tPress Any key for back to main function");
            getch();
            system("CLS");
            backMenu();
        };
        break;

    case 2:

        system("cls");
        system("COLOR FC");
        printf("\n\n\n");
        printf("\n\t\t\t\t\t************************************************\n");
        printf("\n\t\t\t\t\t|----Welcome to The News world...!!----|\n");
        printf("\n\t\t\t\t\t************************************************\n");

        printf("\n\n\n\tEnter any number (3 to infinite)\n");

        int v,b;

        scanf("%d",&v);

        char *namer[]= {"FOOTBALLAR","MOVIE","ONLINE GAME"};

        for(int i = 0 ; i < 3 ; i++)
        {
            printf("\t%d. = %s\t",i+1,namer[i]);
        }

        while(v--)
        {
            printf("\n\n\n\t\t1.Top 10 Football  \t2.Top 10 Movie  \t3.Top 10 On-line Game \n");
            printf("\n\n\t\tchose one !!\n");
            scanf("%d",&b);
            switch(b)
            {
            case 1:
                system("cls");

                printf("\n\t\t\t*****************************\n");
                printf("\n\t\t\t|----- Top 10 Footballer -----|\n");
                printf("\n\t\t\t*****************************\n");

                char *nam[] = {"Lionel Messi     ",
                               "Cristiano Ronaldo",
                               "Neymar jr        ",
                               "K. Mbappe        ",
                               "M. Salah         ",
                               "Paul Pogba       ",
                               "Griezman         ",
                               "Greate Bale      ",
                               "De Maria         ",
                               "David de Gea     "
                              };
                int salary[10]= {126,117,108,42,37,35,33,29,26,22};

                printf("\n\t\tNo \t\tName\t\tSalary(Million usd $)\n");

                for(m = 0 ; m <10 ; m++)
                {
                    printf("\n\t\t%d\t %s\t\t%d\n",m+1,nam[m],salary[m]);
                }
                printf("\n\n\t\t\tPress Any key for back to main function");
                getch();
                system("CLS");
                backMenu();
                break;

            case 2:
                system("cls");

                printf("\n\t\t\t\t\t************************************\n");
                printf("\n\t\t\t\t\t|----- All Time Best 10 Movies -----|\n");
                printf("\n\t\t\t\t\t*************************************\n\n\n");


                printf("\n\t\t\tNo\t\tMovie name\n");
                printf("\n\t\t\t1\t\tInception\n");
                printf("\n\t\t\t2\t\tTitanic\n");
                printf("\n\t\t\t3\t\tLone Survivor\n");
                printf("\n\t\t\t4\t\tThe Prestige\n");
                printf("\n\t\t\t5\t\tShutter Island\n");
                printf("\n\t\t\t6\t\tA Beautiful Mind\n");
                printf("\n\t\t\t7\t\tAqua Man\n");
                printf("\n\t\t\t8\t\tAvengers\n");
                printf("\n\t\t\t9\t\tJames Bond\n");
                printf("\n\t\t\t10\t\tJurassic Park\n");

                break;

            case 3:
                system("cls");

                printf("\n\t\t\t*****************************\n");
                printf("\n\t\t\t|----- Top 10 On-line Game -----|\n");
                printf("\n\t\t\t*****************************\n");

                char *onlineGame[] = {" Player Unknown Battle Ground             ",
                                      " Fortanite Battle Royal                   ",
                                      " Apex Legends                             ",
                                      " League Of Legends                        ",
                                      " Count Strike                             ",
                                      " Hearth Stone                             ",
                                      " Maine craft                              ",
                                      " Dota 2                                   ",
                                      " The Division                             ",
                                      " The Splatoon 2                           "
                                     };
                int year[10]= {2018,2017,2019,2009,2014,2012,2011,2015,2019,2015};

                printf("\n\t\tNo \t\t  Game Name\t\t\t\t   Lunched Year\n");

                for(m = 0 ; m <10 ; m++)
                {
                    printf("\n\t\t%d\t %s\t\t%d\n",m+1,onlineGame[m],year[m]);
                }
                printf("\n\n\t\t\tPress Any key for back to main function");
                getch();
                system("CLS");
                backMenu();
                break;

            default:
                printf("\n\t\terror !! you limit our cross , go home");
            }

        };
        break;


    case 3:
        system("cls");

        printf("\n\n\n");

        printf("\n\t\t\t\t\t************************************************\n");
        printf("\n\t\t\t\t\t|----- Welcome Book Lover to the zone...!!-----|\n");
        printf("\n\t\t\t\t\t************************************************\n");

        printf("\n\n\tEnter any number (3 to infinite)\n");

        int q,w;

        scanf("%d",&q);
        printf("\n");


        char *bookNam[] = {"Don Quixote                               ",
                           "Xinhuan Zidian                            ",
                           "A Tale Of Two Cities                      ",
                           "The Lord Of The Rings                     ",
                           "The Little Prince                         ",
                           "Harry Poter                               ",
                           "And Then There Were None                  ",
                           "Dream Of The Red Chember                  ",
                           "The Hobbit                                ",
                           "The Lion The Witch & The Wardorbe         "
                          };
        int copySold[10]= {500,400,200,150,142,120,100,100,100,85};


        char *BanglaBookNam[] = {"Shesher Kobitha and Gura                      ",
                                 "Prodush Pakritojon                            ",
                                 "Luhokopat                                     ",
                                 "Ontorlina                                     ",
                                 "Khuabnama                                     ",
                                 "Shun Bor Nari                                 ",
                                 "Kobi                                          ",
                                 "Tobu o akdin                                  ",
                                 "Lalshalu                                      ",
                                 "Hazar Bosor Dore                              "
                                };
        while(q--)
        {
            printf("\n\n\t1.All Time Top 10 Best Selling Book\t\t2.Bangla Literature\n");
            printf("\n\n\tchose one !!\n");
            scanf("%d",&n);
            switch(n)
            {
            case 1:
                system("cls");

                printf("\n\t\t\t\t\t*************************************\n");
                printf("\n\t\t\t\t\t|----- All time 10 Best Selling -----|\n");
                printf("\n\t\t\t\t\t**************************************\n");

                printf("\n\t\tNo \t\tBook Name\t\t\t\tCopy sold(Million)\n");

                for(m = 0 ; m <10 ; m++)
                {
                    printf("\n\t\t%d\t %s\t\t%d\n",m+1,bookNam[m],copySold[m]);
                }

                break;

            case 2:
                system("cls");

                printf("\n\t\t\t\t\t*************************************\n");
                printf("\n\t\t\t\t\t|-----   Top 10 Bangla Novel   -----|\n");
                printf("\n\t\t\t\t\t**************************************\n");
                for(int o = 0 ; o < 10; o++)
                {
                    printf("\n\t\t%d = %s\n",o+1,BanglaBookNam[o]);
                }
                break;
            default:
                printf("\nWrong  input\n");
            }
            printf("\n\n\t\t\tPress Any key for back to main function");
            getch();
            system("CLS");
            backMenu();

        };
        break;
    case 4:
        system("CLS");
        quiz();
        break;
    case 5:
        system("CLS");
        entertainment();
        break;

    }


}
void backMenu()
{
    int in,n;
level:
    printf("\n\n\t\t1:Order\n\t\t2:Awaiting Food \n\t\t3:Information and Quiz\n\t\t4:Exit \n");
    scanf ("%d", &in);
    getchar();
    switch(in)
    {
    case 1:
        system("CLS");
        returnMenu();
        break;
    case 2 :
        system("CLS");
        awaitingFood();
        break;
    case 3 :
        system("CLS");
        entertainment();
        break;
    case 4 :
        system("CLS");
        Exit();
    default :
    {
        printf ("\n\n\t\t\tInvalid selection try again\n");
    }
    }
}

int quiz()
{
    int q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11,q12,q13,
        q14,q15,q16,q17,q18,q19,q20, score=0;

    printf("\n\t\t\tlet's see , if your score upto 10 that's said that you're real foodie\n\t\t\t");

    printf("\n\t\t\t1.What is the famous Drinks of Sylhet?\n\t\t\t"
           "1. Tea 2. Lassi 3. Coffee\n\t\t\t");
    scanf("%d",&q1);
    if (q1==1)
    {
        printf("\n\t\t\tCorrect\n");
        ++score;
    }
    else if (q1==2)
    {
        printf("\n\t\t\tWrong.Correct answer is 1\n");
    }
    else if (q1==3)
    {
        printf("\n\t\t\tWrong.Correct answer is 1\n");
    }
    else
    {
        printf("\n\t\t\tWrong input\n");
    }
    printf("\n\t\t\t2.What is the Traditional food of Dhaka?\n\t\t\t"
           "1. Kacchi 2. Haji Biriyani 3. kabab\n\t\t\t");
    scanf("%d",&q2);
    if (q2==2)
    {
        printf("\n\t\t\tCorrect\n");
        ++score;
    }
    else if (q2==1)
    {
        printf("\n\t\t\tWrong.Correct answer is 2\n");
    }
    else if (q2==3)
    {
        printf("\n\t\t\tWrong.Correct answer is 2\n");
    }
    else
    {
        printf("\n\t\t\tWrong input\n");
    }
    printf("\n\t\t\t3.What is the Traditional food of Rangpur?\n\t\t\t"
           "1.Shidal 2.Bharta 3.Mezban\n\t\t\t");
    scanf("%d",&q3);
    if (q3==1)
    {
        printf("\n\t\t\tCorrect\n");
        ++score;
    }
    else if (q3==2)
    {
        printf("\n\t\t\tWrong.Correct answer is 1\n");
    }
    else if (q3==3)
    {
        printf("\n\t\t\tWrong.Correct answer is 1\n");
    }
    else
    {
        printf("\n\t\t\tWrong input\n");
    }
    printf("\n\t\t\t4.What is the famous Dessert of Bogra?\n\t\t\t"
           "1. Chana 2. Dooi 3. Kheer Sagar\n\t\t\t");
    scanf("%d",&q4);
    if (q4==2)
    {
        printf("\n\t\t\tCorrect\n");
        ++score;
    }
    else if (q4==1)
    {
        printf("\n\t\t\tWrong.Correct answer is 2\n");
    }
    else if (q4==3)
    {
        printf("\n\t\t\tWrong.Correct answer is 2\n");
    }
    else
    {
        printf("\n\t\t\tWrong input\n");
    }

    printf("\n\t\t\t5.What is the famous curry of Nilphamari?\n\t\t\t"
           "1. Fish curry 2. Dall 3. Pelka\n\t\t\t");
    scanf("%d",&q5);
    if (q5==3)
    {
        printf("\n\t\t\tCorrect\n");
        ++score;
    }
    else if (q5==1)
    {
        printf("\n\t\t\tWrong.Correct answer is 3\n");
    }
    else if (q5==2)
    {
        printf("\n\t\t\tWrong.Correct answer is 3\n");
    }
    else
    {
        printf("\n\t\t\tWrong input");
    }
    printf("\n\t\t\t6.What is the famous Sweet of Jossor?\n\t\t\t"
           "1. Kalojam 2. Jamtolar misthi 3. ChomChom\n\t\t\t");
    scanf("%d",&q6);
    if (q6==2)
    {
        printf("\n\t\t\tCorrect\n");
        ++score;
    }
    else if (q6==1)
    {
        printf("\n\t\t\tWrong.Correct answer is 2\n");
    }
    else if (q6==3)
    {
        printf("\n\t\t\tWrong.Correct answer is 2\n");
    }
    else
    {
        printf("\n\t\t\tWrong input\n");

    }
    printf("\n\t\t\t7.What is the famous Sweet of Faridpur?\n\t\t\t"
           "1. KhejurGur 2. Jamtolar misthi 3. ChomChom\n\t\t\t");
    scanf("%d",&q7);
    if (q7==1)
    {
        printf("\n\t\t\tCorrect\n");
        ++score;
    }
    else if (q7==2)
    {
        printf("\n\t\t\tWrong.Correct answer is 1\n");
    }
    else if (q7==3)
    {
        printf("\n\t\t\tWrong.Correct answer is 1\n");
    }
    else
    {
        printf("\n\t\t\tWrong input\n");

    }

    printf("\n\t\t\t8.What is the famous 	Beverage of Moulvibazar?\n\t\t\t"
           "1. Tea 2. Lemon juice 3. Seven color tea\n\t\t\t");
    scanf("%d",&q8);
    if (q8==3)
    {
        printf("\n\t\t\tCorrect\n");
        ++score;
    }
    else if (q8==1)
    {
        printf("\n\t\t\tWrong.Correct answer is 1\n");
    }
    else if (q8==2)
    {
        printf("\n\t\t\tWrong.Correct answer is 1\n");
    }
    else
    {
        printf("\n\t\t\tWrong input\n");

    }
    printf("\n\t\t\t9.Which Place famous for 'Shutki Chatni'?\n\t\t\t"
           "1. Netrokona 2. Chattak 3. Kulaura\n\t\t\t");
    scanf("%d",&q9);
    if (q9==3)
    {
        printf("\n\t\t\tCorrect\n");
        ++score;
    }
    else if (q9==1)
    {
        printf("\n\t\t\tWrong.Correct answer is 3\n");
    }
    else if (q9==2)
    {
        printf("\n\t\t\tWrong.Correct answer is 3\n");
    }
    else
    {
        printf("\n\t\t\tWrong input\n");

    }
    printf("\n\t\t\t10.Which Place famous for 'Mango'?\n\t\t\t"
           "1.Chittagong 2.Rajshahi 3.Khulna\n\t\t\t");
    scanf("%d",&q10);
    if (q10==2)
    {
        printf("\n\t\t\tCorrect\n");
        ++score;
    }
    else if (q10==1)
    {
        printf("\n\t\t\tWrong.Correct answer is 2\n");
    }
    else if (q10==3)
    {
        printf("\n\t\t\tWrong.Correct answer is 2\n");
    }
    else
    {
        printf("\n\t\t\tWrong input\n");

    }
    printf("\n\t\t\t11.Kustiya is famous for which dessert?\n\t\t\t"
           "1. Malai cha 2. Malai kulfi 3. Ice Cream\n\t\t\t");
    scanf("%d",&q11);
    if (q11==2)
    {
        printf("\n\t\t\tCorrect\n");
        ++score;
    }
    else if (q11==1)
    {
        printf("\n\t\t\tWrong.Correct answer is 2\n");
    }
    else if (q11==3)
    {
        printf("\n\t\t\tWrong.Correct answer is 2\n");
    }
    else
    {
        printf("\n\t\t\tWrong input\n");

    }
    printf("\n\t\t\t12.What is the famous food in Chittagong?\n\t\t\t"
           "1. Mazban 2. Kalbhuna 3. Kacchi\n\t\t\t");
    scanf("%d",&q12);
    if (q12==1)
    {
        printf("\n\t\t\tCorrect\n");
        ++score;
    }
    else if (q12==2)
    {
        printf("\n\t\t\tWrong.Correct answer is 1\n");
    }
    else if (q12==3)
    {
        printf("\n\t\t\tWrong.Correct answer is 1\n");
    }
    else
    {
        printf("\n\t\t\tWrong input\n");

    }
    printf("\n\t\t\t13.Which Place is famous for 'Bamboo Chicken'?\n\t\t\t"
           "1. Ragnamati 2. Cox-bazar 3. Dhaka\n\t\t\t");
    scanf("%d",&q13);
    if (q13==1)
    {
        printf("\n\t\t\tCorrect\n");
        ++score;
    }
    else if (q13==2)
    {
        printf("\n\t\t\tWrong.Correct answer is 1\n");
    }
    else if (q13==3)
    {
        printf("\n\t\t\tWrong.Correct answer is 1\n");
    }
    else
    {
        printf("\n\t\t\tWrong input\n");

    }
    printf("\n\t\t\t14. What is the famous sweet of Maymanshingh?\n\t\t\t"
           "1. Kalojam 2. Balish misthi 3. Kheer sagor\n\t\t\t");
    scanf("%d",&q14);
    if (q14==2)
    {
        printf("\n\t\t\tCorrect\n");
        ++score;
    }
    else if (q14==1)
    {
        printf("\n\t\t\tWrong.Correct answer is 2\n");
    }
    else if (q14==3)
    {
        printf("\n\t\t\tWrong.Correct answer is 2\n");
    }
    else
    {
        printf("\n\t\t\tWrong input\n");

    }
    printf("\n\t\t\t15. Chadpur is famous for which fish?\n\t\t\t"
           "1. Rui  2. Ilish 3. Katla\n\t\t\t");
    scanf("%d",&q15);
    if (q15==2)
    {
        printf("\n\t\t\tCorrect\n");
        ++score;
    }
    else if (q15==1)
    {
        printf("\n\t\t\tWrong.Correct answer is 2\n");
    }
    else if (q15==3)
    {
        printf("\n\t\t\tWrong.Correct answer is 2\n");
    }
    else
    {
        printf("\n\t\t\tWrong input\n");

    }
    printf("\n\t\t\t16 Khulna is famous for wich dish?\n\t\t\t"
           "1. Chuijhal beef 2.Kalabhuna 3.Kabab\n\t\t\t");
    scanf("%d",&q16);
    if (q16==1)
    {
        printf("\n\t\t\tCorrect\n");
        ++score;
    }
    else if (q16==2)
    {
        printf("\n\t\t\tWrong.Correct answer is 1\n");
    }
    else if (q16==3)
    {
        printf("\n\t\t\tWrong.Correct answer is 1\n");
    }
    else
    {
        printf("\n\t\t\tWrong input\n");

    }
    printf("\n\t\t\t17.Tangail is famous for?\n\t\t\t"
           "1. Chomchom 2. Balish misty 3. Gur pitha\n\t\t\t");
    scanf("%d",&q17);
    if (q17==1)
    {
        printf("\n\t\t\tCorrect\n");
        ++score;
    }
    else if (q17==2)
    {
        printf("\n\t\t\tWrong.Correct answer is 1\n");
    }
    else if (q17==3)
    {
        printf("\n\t\t\tWrong.Correct answer is 1\n");
    }
    else
    {
        printf("\n\t\t\tWrong input\n");

    }
    printf("\n\t\t\t18.Which Place is famus for 'KACHAGOLLA'?\n\t\t\t"
           "1. Bogra 2. Natore 3. Khulna\n\t\t\t");
    scanf("%d",&q18);
    if (q18==2)
    {
        printf("\n\t\t\tCorrect\n");
        ++score;
    }
    else if (q18==1)
    {
        printf("\n\t\t\tWrong.Correct answer is 2\n");
    }
    else if (q18==3)
    {
        printf("\n\t\t\tWrong.Correct answer is 2\n");
    }
    else
    {
        printf("\n\t\t\tWrong input\n");

    }
    printf("\n\t\t\t19.Comilla is famous for?\n\t\t\t"
           "1. mishty 2. Dooi 3. Rashmalai\n\t\t\t");
    scanf("%d",&q19);
    if (q19==3)
    {
        printf("\n\t\t\tCorrect\n");
        ++score;
    }
    else if (q19==1)
    {
        printf("\n\t\t\tWrong.Correct answer is 3\n");
    }
    else if (q19==2)
    {
        printf("\n\t\t\tWrong.Correct answer is 3\n");
    }
    else
    {
        printf("\n\t\t\tWrong input\n");

    }
    printf("\n\t\t\t20.What is the Traditional Food of Sylhet?\n\t\t\t"
           "1. Shatkora beef 2. Kalabhuna 3. Paya\n\t\t\t");
    scanf("%d",&q20);

    if (q20==1)
    {
        printf("\n\t\t\tCorrect\n");
        ++score;
    }
    else if (q20==2)
    {
        printf("\n\t\t\tWrong.Correct answer is 1\n");
    }
    else if (q20==3)
    {
        printf("\n\t\t\tWrong.Correct answer is 1\n");
    }
    else
    {
        printf("\n\t\t\tWrong input\n");

    }
    printf("\n\t\t\tYour score is %d of 20",score);

    printf("\n\n\t\t\tPress Any key for back to main function");
    getch();
    system("CLS");
    backMenu();


}

/*1st welcome part */

void welcome()
{

    printf("\n\n\n\n");
    printf("\t\t\t===================---------------------------------------------==================\n");
    printf("\t\t\t*                                                                                *\n");
    printf("\t\t\t**********************************************************************************\n");
    printf("\t\t\t*********                                                                *********\n");
    printf("\t\t\t********                                                                  ********\n");
    printf("\t\t\t*******                                                                    *******\n");
    printf("\t\t\t******                     W E L C O M E    TO                              ******\n");
    printf("\t\t\t*****                                                                        *****\n");
    printf("\t\t\t****                               T H E                                      ****\n");
    printf("\t\t\t***                                                                            ***\n");
    printf("\t\t\t**                                                                              **\n");
    printf("\t\t\t**                        H U N G R Y  - P A N D A                               *\n");
    printf("\t\t\t*                                                                                *\n");
    printf("\t\t\t*                                                                                *\n");
    printf("\t\t\t*                                                                                *\n");
    printf("\t\t\t* ...............................................................................*\n");
    printf("\t\t\t*                                                                                *\n");
    printf("\t\t\t*                                                                                *\n");
    printf("\t\t\t**********************************************************************************\n");
}


void  logIn()
{
    system("CLS");
    gotoxy(40,4);
    printf("Some Information :-");

    gotoxy(10,6);
    printf("=> For the very first time you must be REGISTRATION  and later on  SIGN IN option work");

    gotoxy(10,8);
    printf("=> Be careful !!  when you  Input your name  and your password ");

    gotoxy(10,10);
    printf("=> Your user name is Your User ID");

    gotoxy(10,12);
    printf("=> Note that 'You can only Registration one device for one Account'");


    gotoxy(10,16);
    printf("Press 1 : Registration \t Press 2 : Sign in\n");
}

//Team members name name

void contributor()
{

    printf("\n\n\n\n");
    printf("\t\t\t===================---------------------------------------------====================\n");
    printf("\t\t\t*.                                                                                .*\n");
    printf("\t\t\t*.                              Team RAGNAROK                                     .*\n");
    printf("\t\t\t*.                                                                                .*\n");
    printf("\t\t\t*.                                                                                .*\n");
    printf("\t\t\t....................................................................................\n");
    printf("\t\t\t.                                                                                  .\n");
    printf("\t\t\t.                          C O N T R I B U T O R                                   .\n");
    printf("\t\t\t.                                                                                  .\n");
    printf("\t\t\t*********.                                                                .*********\n");
    printf("\t\t\t*********.             1. MD. SAJJADUR RAHMAN  ------ 299                 .*********\n");
    printf("\t\t\t*********.                                                                .*********\n");
    printf("\t\t\t********.              2. ARNOB LASKAR        --------301                  .********\n");
    printf("\t\t\t*******.                                                                    .*******\n");
    printf("\t\t\t******.                3. MD. ASADULLAH-AL-GALIB -----303                    .******\n");
    printf("\t\t\t*****.                                                                        .*****\n");
    printf("\t\t\t****.                  4. CHINMOY DATTA PRIOM    -----311                      .****\n");
    printf("\t\t\t***.                                                                            .***\n");
    printf("\t\t\t**.                                                                              .**\n");
    printf("\t\t\t*.                                                                                .*\n");
    printf("\t\t\t*. ................................................................................*\n");
    printf("\t\t\t*.                                                                                .*\n");
    printf("\t\t\t*.                       Digital Food Business  Platform                          .*\n");
    printf("\t\t\t*.                                                                                .*\n");
    printf("\t\t\t************************************************************************************\n");
}




