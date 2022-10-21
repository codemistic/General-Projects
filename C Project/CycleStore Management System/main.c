#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
void FirstPage();
void LoginPage();
void MenuPage();
void Heading();
void Add_Page();
void List_Page();
void Update_Page();
void Search_Page();
void Delete_Page();
void Rent_Menu();
void cycle_record();
void rent_cycle();
void sales_revenue();
void rent_revenue();
void Exit_Page();
void Mansarover();
void Vaishali();
void Jhotwara();
char ch;
int flag=0;
void main()
{
    FirstPage();
    LoginPage();
}
void FirstPage()
{
    printf("\n\n\n\n\t\t*********************************");
    printf("\n\t\t *-------------------------------------WELCOME TO---------------------------------------------*");
    printf("\n\t\t   *----------------------------------------THE-------------------------------------------------*");
    printf("\n\t\t     *---------------------------------------SHOWROOM--------------------------------------------*");
    printf("\n\t\t       ********************************");
    printf("\n\n\t\t\t\tCenters In The City----------");
    printf("\n\t\t\t\t\t|------------------------------------------------|");
    printf("\n\t\t\t\t\t|                 Mansarover centre              |\n");
	printf("\t\t\t\t\t|              Vaishali Nagar centre             |\n");
    printf("\t\t\t\t\t|                 jhotwara centre                |\n");
	printf("\t\t\t\t\t|                                                |\n");
	printf("\t\t\t\t\t|                                                |\n");
	printf("\t\t\t\t\t|                                                |\n");
	printf("\t\t\t\t\t|          CONTACT US:Jaipur_cycle@gmail.com     |\n");
	printf("\t\t\t\t\t|------------------------------------------------|\n\n\n");
    printf("\n\n\n\n\n\t\t\tPress any key to continue--------");
    getch();
}
void LoginPage()
{
    system("cls");
    Heading();
    char username[20],pass[20],ori_username[20]="ComputerProject",ori_pass[20]="iiitvadodara";
    int count=0;
    do
    {
       printf("\n\n\n\t\t\tEnter your login credentials :-----------");
       printf("\n\n\t\t\t\tUsername : ");
       scanf("%s",&username);
       printf("\n\t\t\t\tPassword : ");
       scanf("%s",&pass);
       if(strcmp(username,ori_username)==0 && strcmp(pass,ori_pass)==0)
       {
           printf("\n\n\t\t\t\t\tLogin Successful-------");
           printf("\n\t\tEnter any key to continue------");
           getch();
           system("cls");
           Second_Page();
           break;
       }
       else
       {
           printf("\n\n\t\t\t\tInvalid Input------Try Again.");
           printf("\n\t\t\t\tPress any key to continue---");
           count++;
           getch();
           system("cls");
           Heading();
       }
    }while(count<=4);
    if(count>4)
    printf("\n\n\t\tTime Out----------Account Blocked.");
}
void MenuPage()
{
  system("cls");
  Sales_Heading();
  int choice;
  printf("\n\n\n\t\t\t1. Add Customer Details.");
  printf("\n\t\t\t2. Customer's List.");
  printf("\n\t\t\t3. Update Costomer's List.");
  printf("\n\t\t\t4. Search Customer's.");
  printf("\n\t\t\t5. Delete Customer's.");
  printf("\n\t\t\t6. Total Revenue.");
  printf("\n\t\t\t7. Return to Home Page.");
  L:
  printf("\n\n\t\tChoose the Option-------");
  scanf("%d",&choice);
  switch(choice)
  {
      case 1: Add_Page();
      break;
      case 2: List_Page();
      break;
      case 3: Update_Page();
      break;
      case 4: Search_Page();
      break;
      case 5: Delete_Page();
      break;
      case 6: sales_revenue();
      break;
      case 7: Second_Page();
      default : printf("\n\n\t\tInvalid Input.----Try Again.");
      goto L;
  }
}
void Heading()
{
    printf("\n\n______________________________________");
    printf("\n-------------------------------------Jaipur Cycle Sales And Rental Service----------------------------------------");
    printf("\n________________________________________\n");
}
void Exit_Page()
{
    system("cls");
    printf("\n\n\n\n\n");
    printf("\t\t   TTTTTTTT   HH   HH        AA        NN       NN    KK    KK  \n");
    printf("\t\t      TT      HH   HH       A  A       NN NN    NN    KK  KK    \n");
    printf("\t\t      TT      HHHHHHH      AAAAAA      NN   NN  NN    KKK      \n");
    printf("\t\t      TT      HH   HH     AA    AA     NN    NN NN    KK  KK    \n");
    printf("\t\t      TT      HH   HH    AA      AA    NN       NN    KK    KK  \n\n");

    printf("\t\t         YY      YY          OO        UU        UU  \t\n");
    printf("\t\t           YY  YY         OO    OO     UU        UU  \t\n");
    printf("\t\t             YY           OO    OO     UU        UU  \t\n");
    printf("\t\t             YY           OO    OO      UUU    UUU   \t\n");
    printf("\t\t             YY              OO            UUUU      \t\n");
    printf("\t\t\t\t............DONE BY :* AYUSHI SHUKLA...* AYUSH SONI...* AYUSH SINGH....and......* GAGAN CHANDRA.");
    getch();
    printf("\n\n\n\n\n\n");
    exit(0);
}
void Add_Page()
{
    char first_name[30],last_name[30],address[30],number[15],email[30],model[15],date[12];
    float cost,paid;
    int warranty, i;
    system("cls");
    Sales_Heading();
    printf("\n\n\t\t\t======Add Customer's Details======");
    P:
    printf("\n\n\t\t\t  First Name : ");
    scanf("%s",first_name);
    if(strlen(first_name)>25)
    {
        printf("\n\t\t\t  Invalid First Name----Maximum Character is 25----Try Again.");
        goto P;
    }
    else
    {
        int flag=1;
        for(i=0;i<strlen(first_name);i++)
        {
            if(isalpha(first_name[i]))
            {
              first_name[i]=toupper(first_name[i]);
            }
            else
            {
                flag=0;
                break;
            }
        }
        if(flag==0)
        {
            printf("\n\t\t\t  Invalid Input---Only Alphabets Allowed---Enter Again-");
            goto P;
        }
    }
    Q:
    printf("\n\t\t\t  Last Name : ");
    scanf("%s",last_name);
    if(strlen(last_name)>25)
    {
        printf("\n\t\t\t  Invalid First Name----Maximum Character is 25----Try Again.");
        goto Q;
    }
    else
    {
        int flag=1;
        for(i=0;i<strlen(last_name);i++)
        {
            if(isalpha(last_name[i]))
            {
               last_name[i]=toupper(last_name[i]);
            }
            else
            {
                flag=0;
                break;
            }
        }
        if(flag==0)
        {
            printf("\n\t\t\t  Invalid Input---Only Alphabets Allowed---Enter Again-");
            goto Q;
        }
    }
    R:
    printf("\n\t\t\t  Address : ");
    scanf("%s",address);
    if(strlen(address)>25)
    {
        printf("\n\t\t\tInvalid Input---Limit Exceeds---Try Again-");
        goto R;
    }
    else
    {
        for(int i=0;i<strlen(address);i++)
        {
            address[i]=toupper(address[i]);
        }
    }
    S:
    printf("\n\t\t\t  Phone Number : ");
    scanf("%s",number);
    if(strlen(number) != 10)
    {
        printf("\n\t\t\tInvalid Input---Ten Digits Required---Try Again-");
        goto S;
    }
    else
    {
        int flag=1;
        for(int i=0;i<strlen(number);i++)
        {
            if(isalpha(number[i]))
            {
                flag=0;
                break;
            }
        }
        if(flag==0)
        {
            printf("\n\t\t\tInvalid Input---Only Digits Accepted---Try Again-");
            goto S;
        }
    }
    T:
    printf("\n\t\t\t  Email : ");
    scanf("%s",email);
    if(strlen(email)>30 || strlen(email)<10)
    {
        printf("Invalid Input---Minimum Characters-10---Maximum Character-30---Try Again-");
        goto T;
    }
    U:
    printf("\n\t\t\t  Model Number : ");
    scanf("%s",model);
    if(strlen(model)>15)
    {
        printf("Invalid Input---Limit Exceeds---Maximum Character-15---Try Again-");
        goto T;
    }
    V:
    printf("\n\t\t\t  Warranty(No. of years) : ");
    scanf("%d",&warranty);
    if(warranty<0)
    {
        printf("\n\t\t\t  Invalid Input---Positive Integer Expected---Try Again-");
        goto V;
    }
    W:
    printf("\n\t\t\t Date of purchase(dd/mm/yyyy) : ");
    scanf("%s",date);
    if(strlen(date)!=10)
    {
        printf("\n\t\t\tInvalid Input---Ten Characters Required---Try Again-");
        goto W;
    }
    printf("\n\t\t\t  Cost(in Rs) To Be Paid : ");
    scanf("%f",&cost);
    printf("\n\t\t\t Money Paid(in Rs) : ");
    scanf("%f",&paid);

    FILE *ptr;
    ptr=fopen("List.txt","a");
    fprintf(ptr,"\n%s  %s  %s  %s  %s  %s  %d  %s  %f  %f ",first_name,last_name,address,number,email,model,warranty,date,cost,paid);
    printf("\n\n\t\t------------------------------------------------------------------");
    printf("\n\t\t\tDetails Has Been Added Successfully!!!!!!!");
    fclose(ptr);
    Y:
    fflush(stdin);
    printf("\n\n\t\tDo You Want TO Add More----(Y/N) : ");
    scanf("%s",&ch);
    if(toupper(ch)=='Y')
    {
        Add_Page();
    }
    else if(toupper(ch)=='N')
    {
        printf("\n\n\t\tOk....Done----");
        getch();
        MenuPage();
    }
    else
    {
       printf("\n\n\t\tInvalid Input----Enter Again--");
       goto Y;
    }
}
void List_Page()
{
    system("cls");
    Sales_Heading();
    printf("\n\n\n\t\t\t---------------Customer's List---------------\n");
    FILE *ptr;
    ptr=fopen("List.txt","r");
    //printf("\n  Name\t\tAddress\t Phone Number\tEmail Address\t\t\tModel Number\tWarranty\tDate of Purchase\t\tCost\tAmount Paid");
    printf("%-20s%-20s%-20s%-25s%-20s%-20s%-20s%-20s%-20s\n","Full Name","Address","Phone Number","Email Address","Model Number","Warranty","Date of Purchase","Cost","Amount Paid");
    printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    char first_name[30],last_name[30],address[30],number[15],email[30],model[15],date[12];
    float cost,paid;
    int warranty;
    rewind(ptr);
    while(fscanf(ptr,"%s  %s  %s  %s  %s  %s  %d  %s  %f  %f ",first_name,last_name,address,number,email,model,&warranty,date,&cost,&paid)!=EOF)
    {
        char space[5]=" ";
        strncat(first_name,space,sizeof(first_name)-sizeof(space)-1);
        strncat(first_name,last_name,sizeof(first_name)-sizeof(last_name)-1);
        printf("%-20s%-20s%-20s%-25s%-20s%-20d%-20s%-20.2f%-20.2f\n",first_name,address,number,email,model,warranty,date,cost,paid);
    }
    fclose(ptr);
    printf("\n\n\nPress any key to continue---");
    getch();
    MenuPage();
}
void Update_Page ()
{
    system("cls");
    Sales_Heading();
    FILE *ptr1,*ptr2;
    ptr1=fopen("List.txt","r");
    ptr2=fopen("temp_List.txt","w+");
    char first_name[30],last_name[30],address[30],number[15],email[30],model[15],date[12];
    float cost,paid;
    int warranty;
    if(ptr1==NULL)
    {
        printf("\n\nError : Unable to open file---");
        getch();
        MenuPage();
    }
    printf("\n\n\t\t------------Update Customer's Details-----------");
    char phone[25];
    printf("\n\nEnter the Customer's Phone No or First Name : ");
    scanf("%s",phone);
    for(int i=0;i<strlen(phone);i++)
    {
        phone[i]=toupper(phone[i]);
    }
    int flag=0,i;
    while(fscanf(ptr1,"%s  %s  %s  %s  %s  %s  %d  %s  %f  %f ",first_name,last_name,address,number,email,model,&warranty,date,&cost,&paid)!=EOF)
    {
        if(strcmp(phone,number)==0 || strcmp(phone,first_name)==0)
        {
            printf("\n\n\t\t=============Existing Details============\n");
            char space[5]=" ";
            strncat(first_name,space,sizeof(first_name)-sizeof(space)-1);
            strncat(first_name,last_name,sizeof(first_name)-sizeof(last_name)-1);
            printf("%-20s%-20s%-20s%-25s%-20s%-20s%-20s%-20s%-20s\n","Full Name","Address","Phone Number","Email Address","Model Number","Warranty","Date of Purchase","Cost","Amount Paid");
            printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("%-20s%-20s%-20s%-25s%-20s%-20d%-20s%-20.2f%-20.2f\n",first_name,address,number,email,model,warranty,date,cost,paid);
            printf("\n\n\n\t\t\tEnter New Details-------");
            P:
            printf("\n\n\t\t\t  First Name : ");
            scanf("%s",first_name);
            if(strlen(first_name)>25)
            {
                printf("\n\t\t\t  Invalid First Name----Maximum Character is 25----Try Again.");
                goto P;
            }
            else
            {
                int flag=1;
                for(i=0;i<strlen(first_name);i++)
                {
                    if(isalpha(first_name[i]))
                    {
                        first_name[i]=toupper(first_name[i]);
                    }
                    else
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag==0)
                {
                       printf("\n\t\t\t  Invalid Input---Only Alphabets Allowed---Enter Again-");
                       goto P;
                }
            }
            Q:
            printf("\n\t\t\t  Last Name : ");
            scanf("%s",last_name);
            if(strlen(last_name)>25)
            {
                printf("\n\t\t\t  Invalid First Name----Maximum Character is 25----Try Again.");
                goto Q;
            }
            else
            {
                int flag=1;
                for(i=0;i<strlen(last_name);i++)
                {
                   if(isalpha(last_name[i]))
                   {
                       last_name[i]=toupper(last_name[i]);
                   }
                   else
                   {
                       flag=0;
                       break;
                   }
                }
                if(flag==0)
                {
                    printf("\n\t\t\t  Invalid Input---Only Alphabets Allowed---Enter Again-");
                    goto Q;
                }
            }
            R:
            printf("\n\t\t\t  Address : ");
            scanf("%s",address);
            if(strlen(address)>25)
            {
               printf("\n\t\t\tInvalid Input---Limit Exceeds---Try Again-");
               goto R;
            }
           else
           {
               for(int i=0;i<strlen(address);i++)
               {
                   address[i]=toupper(address[i]);
               }
           }
           S:
           printf("\n\t\t\t  Phone Number : ");
           scanf("%s",number);
           if(strlen(number) != 10)
           {
               printf("\n\t\t\tInvalid Input---Ten Digits Required---Try Again-");
               goto S;
           }
           else
           {
                int flag=1;
                for(int i=0;i<strlen(number);i++)
                {
                  if(isalpha(number[i]))
                  {
                     flag=0;
                     break;
                  }
                }
                if(flag==0)
                {
                    printf("\n\t\t\tInvalid Input---Only Digits Accepted---Try Again-");
                    goto S;
                }
            }
            T:
            printf("\n\t\t\t  Email : ");
            scanf("%s",email);
            if(strlen(email)>30 || strlen(email)<10)
            {
                printf("Invalid Input---Minimum Characters-10---Maximum Character-30---Try Again-");
                goto T;
            }
            U:
            printf("\n\t\t\t  Model Number : ");
            scanf("%s",model);
            if(strlen(model)>15)
            {
                printf("Invalid Input---Limit Exceeds---Maximum Character-15---Try Again-");
                goto T;
            }
            V:
            printf("\n\t\t\t  Warranty(No. of years) : ");
            scanf("%d",&warranty);
            if(warranty<0)
            {
                printf("\n\t\t\t  Invalid Input---Positive Integer Expected---Try Again-");
                goto V;
            }
            W:
            printf("\n\t\t\t Date of purchase(dd/mm/yyyy) : ");
            scanf("%s",date);
            if(strlen(date)!=10)
            {
                printf("\n\t\t\tInvalid Input---Ten Characters Required---Try Again-");
                goto W;
            }
            printf("\n\t\t\t  Cost(in Rs) To Be Paid : ");
            scanf("%f",&cost);
            printf("\n\t\t\t Money Paid(in Rs) : ");
            scanf("%f",&paid);
            Z:
            fflush(stdin);
            printf("\n\n\t\tDO You Want To Save The Changes Made----[Y/N] :");
            scanf("%c",&ch);
            if(toupper(ch)=='Y')
            {
            fprintf(ptr2,"%s  %s  %s  %s  %s  %s  %d  %s  %f  %f ",first_name,last_name,address,number,email,model,warranty,date,cost,paid);
            printf("\n\n----------------Changes Has Been Made Successfully---");
            }
            else if(toupper(ch)=='N')
            {
               printf("\n\t\t\tOk---Done----");
               getch();
               MenuPage();
            }
            else
            {
                printf("\n\n\t\tInvalid Input------Enter Again");
                goto Z;
            }
            flag=1;
        }
        else
        {
            fprintf(ptr2,"%s  %s  %s  %s  %s  %s  %d  %s  %f  %f ",first_name,last_name,address,number,email,model,warranty,date,cost,paid);
        }
    }
    if(flag==0)
    {
        printf("\n\n\t\t----No Data Found ????????");
    }
    fclose(ptr1);
    fclose(ptr2);
    remove("List.txt");
    rename("temp_List.txt","List.txt");
    printf("\n\n\t\tPress any key to continue----- : ");
    getch();
    MenuPage();
}
void Search_Page()
{
    system("cls");
    Sales_Heading();
    printf("\n\n\t\t\t-----------------Search Customer's Details------------------");
    char phone[25];
    char first_name[30],last_name[30],address[30],number[15],email[30],model[15],date[12];
    float cost,paid;
    int warranty;
    FILE *ptr;
    ptr=fopen("List.txt","r");
    printf("\n\n\t\t\t\tEnter Customer's Phone No or First Name : ");
    scanf("%s",phone);
    for(int i=0;i<strlen(phone);i++)
    {
        phone[i]=toupper(phone[i]);
    }
    int option=0;
    printf("%-20s%-20s%-20s%-25s%-20s%-20s%-20s%-20s%-20s\n","Full Name","Address","Phone Number","Email Address","Model Number","Warranty","Date of Purchase","Cost","Amount Paid");
    printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    while(fscanf(ptr,"%s  %s  %s  %s  %s  %s  %d  %s  %f  %f ",first_name,last_name,address,number,email,model,&warranty,date,&cost,&paid)!=EOF)
    {
        if(strcmp(phone,number)==0 || strcmp(phone,first_name)==0)
        {
            char space[5]=" ";
            strncat(first_name,space,sizeof(first_name)-sizeof(space)-1);
            strncat(first_name,last_name,sizeof(first_name)-sizeof(last_name)-1);
            printf("%-20s%-20s%-20s%-25s%-20s%-20d%-20s%-20.2f%-20.2f\n",first_name,address,number,email,model,warranty,date,cost,paid);
            option=1;
        }
    }
    if(option==0)
    {
        printf("\n\n\t\t\t\tNo Data Found");
    }
    fclose(ptr);
    printf("\n\n\t\tPress any key to return to Menu Page--- ");
    getch();
    MenuPage();
}
void Delete_Page()
{
    system("cls");
    Sales_Heading();
    printf("\n\n\t\t\t--------------Delete Customer's Details-------------");
    char name[25];
    char first_name[30],last_name[30],address[30],number[15],email[30],model[15],date[12];
    float cost,paid;
    int warranty;
    FILE *ptr,*ptr1;
    ptr=fopen("List.txt","r");
    ptr1=fopen("temp_List.txt","w+");
    printf("\n\n\t\t\t\tEnter Customer's First Name : ");
    fflush(stdin);
    scanf("%s",name);
    for(int i=0;i<strlen(name);i++)
    {
        name[i]=toupper(name[i]);
    }
    fflush(stdin);
    flag=0;
    while(fscanf(ptr,"%s  %s  %s  %s  %s  %s  %d  %s  %f  %f ",first_name,last_name,address,number,email,model,&warranty,date,&cost,&paid)!=EOF)
    {
        if(strcmp(first_name,name)==0)
        {
          printf("\n\n%s %-20s%-20s%-20s%-25s%-20s%-20d%-20s%-20.2f%-20.2f\n",first_name,last_name,address,number,email,model,warranty,date,cost,paid);
          flag=1;
        }
        else
        {
          fprintf(ptr1,"%s  %s  %s  %s  %s  %s  %d  %s  %f  %f ",first_name,last_name,address,number,email,model,warranty,date,cost,paid);
        }
    }
    if(flag==0)
    {
        printf("\n\n\t\t\tData Not Found-----");
        getch();
        MenuPage();
    }
    else
    {
        fclose(ptr);
        fclose(ptr1);
        remove("List.txt");
        rename("temp_List.txt","List.txt");
        printf("\n\n\t\t\tData Has Been Deleted Successfully-------");
        getch();
        MenuPage();
    }

}
void cycle_record()
{
    FILE *f;
    f = fopen("add.txt","r");

    if(f == NULL) {
        printf("Unable to open the file");
        exit(1);
    }
    char modelnumber[25],firstname[25],lastname[25],address[25],phonenumber[25],nationality[25],email[25];
    unsigned int period;
    system("cls");
    Rent_Heading();
	printf("\n\n\n%-15s%-25s%-20s%-20s%-20s%-33s%-20s\n","Model No","Full Name", "Address", "Phone No", "Nationality", "Email", "Period(hours)");
    for(int i=0;i<140;i++)
	{
		printf("-");
	}
    printf("\n");
    while(fscanf(f,"%s %s %s %s %s %s %s %u\n", modelnumber, firstname, lastname, address, phonenumber, nationality, email, &period)!=EOF)
    {
        char space[5]=" ";
        strncat(firstname,space,sizeof(firstname)-sizeof(space)-1);
        strncat(firstname,lastname,sizeof(firstname)-sizeof(lastname)-1);
        printf("%-15s%-25s%-20s%-20s%-20s%-33s%-20u\n", modelnumber, firstname, address, phonenumber, nationality, email, period);
    }
    printf("\n");
    for(int i=0;i<140;i++)
	{
		printf("-");
	}
    printf("\n");
    fclose(f);
    getch();
    Rent_Menu();
}
void rent_cycle()
{
    system("cls");
    Rent_Heading();
    printf("\n\n\n");
	FILE *f;
    f = fopen("add.txt","a");
    if(f == NULL)
    {
        printf("Unable to open the file");
        Rent_Menu();
    }
	rewind(f);
	char modelnumber[25],firstname[25],lastname[25],address[25],phonenumber[25],nationality[25],email[25];
	unsigned int period;
	printf("\n\n\t\t\t======Add Customer's Details======");
	printf("\n\n\t\t\tModel No : ");
	scanf("%s",modelnumber);
    A:
    printf("\n\t\t\t  First Name : ");
    scanf("%s",firstname);
    if(strlen(firstname)>25)
    {
        printf("\n\t\t\t  Invalid First Name----Maximum Character is 25----Try Again.");
        goto A;
    }
    else
    {
        int flag=1;
        for(int i=0;i<strlen(firstname);i++)
        {
            if(isalpha(firstname[i]))
            {
              firstname[i]=toupper(firstname[i]);
            }
            else
            {
                flag=0;
                break;
            }
        }
        if(flag==0)
        {
            printf("\n\t\t\t  Invalid Input---Only Alphabets Allowed---Enter Again-");
            goto A;
        }
    }
    M:
    printf("\n\t\t\tLast Name : ");
    scanf("%s",lastname);
    if(strlen(lastname)>25)
    {
        printf("\n\t\t\t  Invalid First Name----Maximum Character is 25----Try Again.");
        goto M;
    }
    else
    {
        int flag=1;
        for(int i=0;i<strlen(lastname);i++)
        {
            if(isalpha(lastname[i]))
            {
              lastname[i]=toupper(lastname[i]);
            }
            else
            {
                flag=0;
                break;
            }
        }
        if(flag==0)
        {
            printf("\n\t\t\t  Invalid Input---Only Alphabets Allowed---Enter Again-");
            goto M;
        }
    }
    B:
    printf("\n\t\t\t  Address : ");
    scanf("%s",address);
    if(strlen(address)>25)
    {
        printf("\n\t\t\tInvalid Input---Limit Exceeds---Try Again-");
        goto B;
    }
    else
    {
        for(int i=0;i<strlen(address);i++)
        {
            address[i]=toupper(address[i]);
        }
    }
    C:
    printf("\n\t\t\t  Phone Number : ");
    scanf("%s",phonenumber);
    if(strlen(phonenumber) != 10)
    {
        printf("\n\t\t\tInvalid Input---Ten Digits Required---Try Again-");
        goto C;
    }
    else
    {
        int flag=1;
        for(int i=0;i<strlen(phonenumber);i++)
        {
            if(isalpha(phonenumber[i]))
            {
                flag=0;
                break;
            }
        }
        if(flag==0)
        {
            printf("\n\t\t\tInvalid Input---Only Digits Accepted---Try Again-");
            goto C;
        }
    }
    printf("\n\t\t\tNationality : ");
    scanf("%s",nationality);
    D:
    printf("\n\t\t\t  Email : ");
    scanf("%s",email);
    if(strlen(email)>30 || strlen(email)<10)
    {
        printf("Invalid Input---Minimum Characters-10---Maximum Character-30---Try Again-");
        goto D;
    }
    int opt;
    F:
    printf("\n\t\t\tPeriod (No of Hours) : ");
    scanf("%u",&period);
	fprintf(f,"%s %s %s %s %s %s %s %u\n", modelnumber, firstname, lastname, address, phonenumber, nationality, email, period);
	printf("\n\n\t\t------------------------------------------------------------------");
    printf("\n\t\t\tDetails Has Been Added Successfully!!!!!!!");
    fclose(f);
    G:
    fflush(stdin);
    printf("\n\n\t\tDo You Want TO Add More----(Y/N) : ");
    scanf("%s",&ch);
    if(toupper(ch)=='Y')
    {
        system("cls");
        rent_cycle();
    }
    else if(toupper(ch)=='N')
    {
        printf("\n\n\t\tOk....Done----");
        getch();
        Rent_Menu();
    }
    else
    {
       printf("\n\n\t\tInvalid Input----Enter Again--");
       goto G;
    }
}
void Rent_Menu()
{
    system("cls");
    Rent_Heading();
    printf("\n\tSelect and Enter Your Choice From Menu:\n");
    printf("\n\t================================");
    printf(" \n\t Enter 1 ->> Rent a cycle");
    printf("\n\t=================================");
    printf(" \n\t Enter 2 ->> View Rental Record");
    printf("\n\t=================================");
    printf(" \n\t Enter 3 ->> Total Revenue");
    printf("\n\t=================================\n");
    printf(" \n\t Enter 4 ->> Return to Home Page");
    printf("\n\t=================================\n");
    int choice;
    H:
    printf(" \nEnter your choice: ");
    scanf("%d", &choice);
    switch(choice)           // SWITCH STATEMENT
    {
        case 1: system("cls");
        rent_cycle();
        break;
        case 2: cycle_record();
        break;
        case 3: rent_revenue();
        break;
        case 4: Second_Page();
        break;
        default: printf("\n\n\t\tInvalid Input----Enter Again : ");
        goto H;
    }
}
void Second_Page()
{
    system("cls");
    Heading();
    int n;
    printf("\n\n\n\t\t\t1. Centre Details---");
    printf("\n\t\t\t2. Sales Details---");
    printf("\n\t\t\t3. Rental Details---");
    printf("\n\t\t\t4. Exit---");
    printf("\n\n\t\tEnter your choice : ");
    O:
    fflush(stdin);
    scanf("%d",&n);
    switch(n)
    {
        case 1: Centre_Menu();
        break;
        case 2: MenuPage();
        break;
        case 3: Rent_Menu();
        break;
        case 4: Exit_Page();
        break;
        default : printf("Invalid Input---Try Again : ");
        goto O;
    }
}
void Rent_Heading()
{
    printf("\n\n______________________________________");
    printf("\n-------------------------------------Jaipur Cycle Sales And Rental Service----------------------------------------");
    printf("\n-------------------------------------------Rental Details---------------------------------------------------------");
    printf("\n--------------------------------------Rent Cost (per Hour) = Rs20-------------------------------------------------");
    printf("\n________________________________________\n");
}
void Sales_Heading()
{
    printf("\n\n______________________________________");
    printf("\n-------------------------------------Jaipur Cycle Sales And Rental Service----------------------------------------");
    printf("\n-------------------------------------------Sales Details----------------------------------------------------------");
    printf("\n________________________________________\n");
}
void Centre_Heading()
{
    printf("\n\n______________________________________");
    printf("\n-------------------------------------Jaipur Cycle Sales And Rental Service----------------------------------------");
    printf("\n-------------------------------------------Centre Details---------------------------------------------------------");
    printf("\n________________________________________\n");
}
void rent_revenue()
{
    system("cls");
    Sales_Heading();
    printf("\n\n\t\t\t-----------------Rental Revenue Details------------------");
    int total=0;
    char modelnumber[25],firstname[25],lastname[25],address[25],phonenumber[25],nationality[25],email[25];
    int period;
    int count=0;
    FILE *ptr;
    ptr=fopen("add.txt","r");
    while(fscanf(ptr,"%s %s %s %s %s %s %s %d", modelnumber, firstname, lastname, address, phonenumber, nationality, email, &period)!=EOF)
    {
        total=total+period*20;
        count++;
    }
    printf("\n\n\t\t\t\tNo Of Cycle On Rent : %d",count);
    printf("\n\t\t\t\tTotal Rental Revenue : Rs%d",total);
    fclose(ptr);
    printf("\n\n\t\tPress any key to return to Menu Page--- ");
    getch();
    Rent_Menu();
}
void sales_revenue()
{
    system("cls");
    Sales_Heading();
    printf("\n\n\t\t\t-----------------Sales Revenue Details------------------");
    float total=0;
    char first_name[30],last_name[30],address[30],number[15],email[30],model[15],date[12];
    float cost,paid;
    int warranty,count=0;
    FILE *ptr;
    ptr=fopen("List.txt","r");
    while(fscanf(ptr,"%s  %s  %s  %s  %s  %s  %d  %s  %f  %f ",first_name,last_name,address,number,email,model,&warranty,date,&cost,&paid)!=EOF)
    {
        total=total+paid;
        count++;
    }
    printf("\n\n\t\t\t\tNo Of Cycle Sold : %d",count);
    printf("\n\t\t\t\tTotal Sales Revenue : Rs%0.2f",total);
    fclose(ptr);
    printf("\n\n\t\tPress any key to return to Menu Page--- ");
    getch();
    MenuPage();
}
void Centre_Menu()
{
    system("cls");
    Centre_Heading();
    printf("\n\tSelect and Enter Your Choice From Menu:\n");
    printf("\n\t================================");
    printf(" \n\t Enter 1 ->> Mansarover centre");
    printf("\n\t=================================");
    printf(" \n\t Enter 2 ->> Vaishali Nagar centre");
    printf("\n\t=================================");
    printf(" \n\t Enter 3 ->> jhotwara centre");
    printf("\n\t=================================\n");
    printf(" \n\t Enter 4 ->> Return to Home Page");
    printf("\n\t=================================\n");
    int choice;
    I:
    printf(" \nEnter your choice: ");
    scanf("%d", &choice);
    switch(choice)           // SWITCH STATEMENT
    {
        case 1: system("cls");
        Mansarover();
        break;
        case 2: Vaishali();
        break;
        case 3: Jhotwara();
        break;
        case 4: Second_Page();
        break;
        default: printf("\n\n\t\tInvalid Input----Enter Again : ");
        goto I;
    }
}
void Mansarover()
{
    char model[25];
    int quantity;
    D:
    system("cls");
    Centre_Heading();
    printf("\n\t\t\t---------------Mansarover Centre Details-------------");
    printf("\n\n\t\t\t\t1. Add new stock.");
    printf("\n\t\t\t\t2. Available Cycles.");
    printf("\n\t\t\t\t3. Update the Stock.");
    printf("\n\t\t\t\t4.Return to previous page.");
    printf("\n\n\t\tEnter Your Choice-- :");
    int n;
    scanf("%d",&n);
    switch(n)
    {
        case 1: E:
            system("cls");
        Centre_Heading();
        FILE *p1;
        p1=fopen("Mans.txt","a");
        printf("\n\t\t\t----------------------Mansarover Centre Details----------------------");
        printf("\n\n\t\t\t+++++++++++++++Add New Stock+++++++++++++++++");
        printf("\n\n\t\t\tEnter Model No : ");
        scanf("%s",model);
        for(int i=0;i<strlen(model);i++)
        {
            model[i]=toupper(model[i]);
        }
        printf("\n\t\t\tEnter Quantity : ");
        scanf("%d",&quantity);
        fprintf(p1,"%s %d \n",model,quantity);
        fclose(p1);
        printf("\n\n\t\tDetails Has Been Successfully Added---");
        printf("\n\n\t\tDo You Want To Add More---[Y/N] : ");
        F:
        fflush(stdin);
        scanf("%c",&ch);
        if(ch=='y' || ch=='Y')
        {
            goto E;
        }
        else if(ch=='n' || ch=='N')
        {
            goto D;
        }
        else
        {
            printf("\n\n\t\tInvalid Input-----Enter Again :");
            goto F;
        }
        break;
        case 2: system("cls");
        Centre_Heading();
        int num=0;
        FILE *p2;
        p2=fopen("Mans.txt","r");
        printf("\n\t\t\t----------------------Mansarover Centre Details----------------------");
        printf("\n\n\t\t=======================Available Cycles======================");
        printf("\n\n\t\t\t%-20s%-10s","Model Number","Quantity");
        while(fscanf(p2,"%s %d",model,&quantity)!=EOF)
        {
            printf("\n\t\t\t %-20s%-10d",model,quantity);
            num=num+quantity;
        }
        printf("\n\t\t---------------------------------");
        printf("\n\t\tTotal Number of Cycles : %d",num);
        printf("\n\n\tPress any key to continue--- ");
        getch();
        fclose(p2);
        goto D;
        break;

        case 3: system("cls");
        printf("\n\t\t\t----------------------Mansarover Centre Details----------------------");
        Centre_Heading();
        char mod[25];
        FILE *p3,*p4;
        p3=fopen("Mans.txt","r");
        p4=fopen("temp_Mans.txt","w+");
        printf("\n\n\t\t=======================Update The Stock======================");
        printf("\n\n\t\t\tEnter The Model No. To Update : ");
        scanf("%s",mod);
        for(int i=0;i<strlen(mod);i++)
        {
            mod[i]=toupper(mod[i]);
        }
        while(fscanf(p3,"%s %d",model,&quantity)!=EOF)
        {
            if(strcmp(mod,model)==0)
            {
                printf("\n\n\t\t-----Existing Stock-----");
                printf("\n\n\t\t\t%-20s%-10s","Model Number","Quantity");
                printf("\n\t\t\t %-20s%-10d",model,quantity);
                printf("\n\n\t\t\tEnter New Stock :-");
                printf("\n\n\t\t\t\tModel No : ");
                scanf("%s",model);
                for(int i=0;i<strlen(model);i++)
                {
                    model[i]=toupper(model[i]);
                }
                printf("\n\t\t\t\tQuantity : ");
                scanf("%d",&quantity);
                fprintf(p4," %s %d ",model,quantity);
                printf("\n\n\t\tData Updated Successfully");
                n=10;
            }
            else
            {
                fprintf(p4," %s %d ",model,quantity);
            }
        }
        if(n!=10)
        {
            printf("Data Not Found---");
        }
        fclose(p3);
        fclose(p4);
        remove("Mans.txt");
        rename("temp_Mans.txt","Mans.txt");
        getch();
        goto D;
        break;

        case 4: Centre_Menu();
        break;

        default: printf("\n\n\tInvalid Input----- ");
        printf("\n\n\tPress any key to enter again : ");
        getch();
        goto D;
    }
}
void Vaishali()
{
    char model[25];
    int quantity;
    D:
    system("cls");
    Centre_Heading();
    printf("\n\t\t\t---------------Vaishali Centre Details-------------");
    printf("\n\n\t\t\t\t1. Add new stock.");
    printf("\n\t\t\t\t2. Available Cycles.");
    printf("\n\t\t\t\t3. Update the Stock.");
    printf("\n\t\t\t\t4.Return to previous page.");
    printf("\n\n\t\tEnter Your Choice-- :");
    int n;
    scanf("%d",&n);
    switch(n)
    {
        case 1: E:
            system("cls");
        Centre_Heading();
        FILE *p1;
        p1=fopen("Vais.txt","a");
        printf("\n\t\t\t----------------------Vaishali Centre Details----------------------");
        printf("\n\n\t\t\t+++++++++++++++Add New Stock+++++++++++++++++");
        printf("\n\n\t\t\tEnter Model No : ");
        scanf("%s",model);
        for(int i=0;i<strlen(model);i++)
        {
            model[i]=toupper(model[i]);
        }
        printf("\n\t\t\tEnter Quantity : ");
        scanf("%d",&quantity);
        fprintf(p1,"%s %d \n",model,quantity);
        fclose(p1);
        printf("\n\n\t\tDetails Has Been Successfully Added---");
        printf("\n\n\t\tDo You Want To Add More---[Y/N] : ");
        F:
        fflush(stdin);
        scanf("%c",&ch);
        if(ch=='y' || ch=='Y')
        {
            goto E;
        }
        else if(ch=='n' || ch=='N')
        {
            goto D;
        }
        else
        {
            printf("\n\n\t\tInvalid Input-----Enter Again :");
            goto F;
        }
        break;

        case 2: system("cls");
        Centre_Heading();
        int num=0;
        FILE *p2;
        p2=fopen("Vais.txt","r");
        printf("\n\t\t\t----------------------Vaishali Centre Details----------------------");
        printf("\n\n\t\t=======================Available Cycles======================");
        printf("\n\n\t\t\t%-20s%-10s","Model Number","Quantity");
        while(fscanf(p2,"%s %d",model,&quantity)!=EOF)
        {
            printf("\n\t\t\t %-20s%-10d",model,quantity);
            num=num+quantity;
        }
        printf("\n\t\t---------------------------------");
        printf("\n\t\tTotal Number of Cycles : %d",num);
        printf("\n\n\tPress any key to continue--- ");
        getch();
        fclose(p2);
        goto D;
        break;

        case 3: system("cls");
        Centre_Heading();
        char mod[25];
        FILE *p3,*p4;
        p3=fopen("Vais.txt","r");
        p4=fopen("temp_Vais.txt","w+");
        printf("\n\t\t\t----------------------Vaishali Centre Details----------------------");
        printf("\n\n\t\t=======================Update The Stock======================");
        printf("\n\n\t\t\tEnter The Model No. To Update : ");
        scanf("%s",mod);
        for(int i=0;i<strlen(mod);i++)
        {
            mod[i]=toupper(mod[i]);
        }
        while(fscanf(p3,"%s %d",model,&quantity)!=EOF)
        {
            if(strcmp(mod,model)==0)
            {
                printf("\n\n\t\t-----Existing Stock-----");
                printf("\n\n\t\t\t%-20s%-10s","Model Number","Quantity");
                printf("\n\t\t\t %-20s%-10d",model,quantity);
                printf("\n\n\t\t\tEnter New Stock :-");
                printf("\n\n\t\t\t\tModel No : ");
                scanf("%s",model);
                for(int i=0;i<strlen(model);i++)
                {
                    model[i]=toupper(model[i]);
                }
                printf("\n\t\t\t\tQuantity : ");
                scanf("%d",&quantity);
                fprintf(p4," %s %d ",model,quantity);
                printf("\n\n\t\tData Updated Successfully");
                n=10;
            }
            else
            {
                fprintf(p4," %s %d ",model,quantity);
            }
        }
        if(n!=10)
        {
            printf("Data Not Found---");
        }
        fclose(p3);
        fclose(p4);
        remove("Vais.txt");
        rename("temp_Vais.txt","Vais.txt");
        getch();
        goto D;
        break;

        case 4: Centre_Menu();
        break;

        default: printf("\n\n\tInvalid Input----- ");
        printf("\n\n\tPress any key to enter again : ");
        getch();
        goto D;
    }
}
void Jhotwara()
{
    char model[25];
    int quantity;
    D:
    system("cls");
    Centre_Heading();
    printf("\n\t\t\t---------------Jhotwara Centre Details-------------");
    printf("\n\n\t\t\t\t1. Add new stock.");
    printf("\n\t\t\t\t2. Available Cycles.");
    printf("\n\t\t\t\t3. Update the Stock.");
    printf("\n\t\t\t\t4.Return to previous page.");
    printf("\n\n\t\tEnter Your Choice-- :");
    int n;
    scanf("%d",&n);
    switch(n)
    {
        case 1: E:
            system("cls");
        Centre_Heading();
        FILE *p1;
        p1=fopen("Jhut.txt","a");
        printf("\n\t\t\t----------------------Jhotwara Centre Details----------------------");
        printf("\n\n\t\t\t+++++++++++++++Add New Stock+++++++++++++++++");
        printf("\n\n\t\t\tEnter Model No : ");
        scanf("%s",model);
        for(int i=0;i<strlen(model);i++)
        {
            model[i]=toupper(model[i]);
        }
        printf("\n\t\t\tEnter Quantity : ");
        scanf("%d",&quantity);
        fprintf(p1,"%s %d \n",model,quantity);
        fclose(p1);
        printf("\n\n\t\tDetails Has Been Successfully Added---");
        printf("\n\n\t\tDo You Want To Add More---[Y/N] : ");
        F:
        fflush(stdin);
        scanf("%c",&ch);
        if(ch=='y' || ch=='Y')
        {
            goto E;
        }
        else if(ch=='n' || ch=='N')
        {
            goto D;
        }
        else
        {
            printf("\n\n\t\tInvalid Input-----Enter Again :");
            goto F;
        }
        break;

        case 2: system("cls");
        Centre_Heading();
        int num=0;
        FILE *p2;
        p2=fopen("Jhut.txt","r");
        printf("\n\t\t\t----------------------Jhutwara Centre Details----------------------");
        printf("\n\n\t\t=======================Available Cycles======================");
        printf("\n\n\t\t\t%-20s%-10s","Model Number","Quantity");
        while(fscanf(p2,"%s %d",model,&quantity)!=EOF)
        {
            printf("\n\t\t\t %-20s%-10d",model,quantity);
            num=num+quantity;
        }
        printf("\n\t\t---------------------------------");
        printf("\n\t\tTotal Number of Cycles : %d",num);
        printf("\n\n\tPress any key to continue--- ");
        getch();
        fclose(p2);
        goto D;
        break;

        case 3: system("cls");
        Centre_Heading();
        char mod[25];
        FILE *p3,*p4;
        p3=fopen("Jhut.txt","r");
        p4=fopen("temp_Jhut.txt","w+");
        printf("\n\t\t\t----------------------Jhutwara Centre Details----------------------");
        printf("\n\n\t\t=======================Update The Stock======================");
        printf("\n\n\t\t\tEnter The Model No. To Update : ");
        scanf("%s",mod);
        for(int i=0;i<strlen(mod);i++)
        {
            mod[i]=toupper(mod[i]);
        }
        while(fscanf(p3,"%s %d",model,&quantity)!=EOF)
        {
            if(strcmp(mod,model)==0)
            {
                printf("\n\n\t\t-----Existing Stock-----");
                printf("\n\n\t\t\t%-20s%-10s","Model Number","Quantity");
                printf("\n\t\t\t %-20s%-10d",model,quantity);
                printf("\n\n\t\t\tEnter New Stock :-");
                printf("\n\n\t\t\t\tModel No : ");
                scanf("%s",model);
                for(int i=0;i<strlen(model);i++)
                {
                    model[i]=toupper(model[i]);
                }
                printf("\n\t\t\t\tQuantity : ");
                scanf("%d",&quantity);
                fprintf(p4," %s %d ",model,quantity);
                printf("\n\n\t\tData Updated Successfully");
                n=10;
            }
            else
            {
                fprintf(p4," %s %d ",model,quantity);
            }
        }
        if(n!=10)
        {
            printf("Data Not Found---");
        }
        fclose(p3);
        fclose(p4);
        remove("Jhut.txt");
        rename("temp_Jhut.txt","Jhut.txt");
        getch();
        goto D;
        break;

        case 4: Centre_Menu();
        break;

        default: printf("\n\n\tInvalid Input----- ");
        printf("\n\n\tPress any key to enter again : ");
        getch();
        goto D;
    }
}