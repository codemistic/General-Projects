#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<dos.h>
#include<stdio.h>
#include<process.h>
#include<string.h>

void pass()
{
     for(int s=2;s>=0;s--)
     {
     clrscr();
     char un[30]="abc";
     char pas[10]="abc";

     char u[30];
     char pa[10];

	for(int  i=10;i<=17;i++)
	{
	      gotoxy(20,i);
	      cout<<"Û";
	}
       for( i=10;i<=17;i++)
	{
	      gotoxy(50,i);
	      cout<<"Û";
	}
	for( i=20;i<=50;i++)
	{
	      gotoxy(i,10);
	      cout<<"Ü";
	}
	for( i=21;i<=49;i++)
	{
	      gotoxy(i,17);
	      cout<<"Ü";
	}
	gotoxy(24,12);
	cout<<"NAME     : ";
	cin>>u;
	gotoxy(24,15);
	cout<<"PASSWORD : ";
	for( i=0 ;i<10;i++)
	{
	  pa[i]=getch();
	  if(pa[i]==13)
	   break;
	   else
	   cout<<"*";

	}
	pa[i]='\0';

	  if(strcmp(un,u)==0 && strcmp(pas,pa)==0)
	  {
	      break;
	  }
	  else
	  {
	     gotoxy(20,20);
	     cout<<"Invalid name & Password : ";
	     gotoxy(20,22);
	     cout<<endl<<"Attempts Left : "<<s;
	     getch();
	  }


     if(s==0)
     {
       exit(0);

     }
     }

 }

void listmenu()
{

	 clrscr();
	  int j;
	//1
	for(int  i=2;i<=24;i++)
	{
	      gotoxy(5,i);
	      cout<<"Û";
	}
	for( i=2;i<=24;i++)
	{
	      gotoxy(76,i);
	      cout<<"Û";
	}
	for( i=6;i<=75;i++)
	{
	      gotoxy(i,2);
	      cout<<"Ü";
	}
	for( i=6;i<=75;i++)
	{
	      gotoxy(i,23);
	      cout<<"Ü";
	}
	for( i=3;i<=22;i++)
	{
	      gotoxy(22,i);
	      cout<<"Ý";
	 }
	 for( i=3;i<=22;i++)
	{
	      gotoxy(43,i);
	      cout<<"Ý";
	 }
	 for( i=3;i<=22;i++)
	{
	      gotoxy(60,i);
	      cout<<"Ý";
	 }
	 for( i=6;i<=75;i++)
	{
	      gotoxy(i,5);
	      cout<<"-";
	 }
	 textcolor(15);
	 gotoxy(9,4);
	cprintf("ACCOUNT NO.");
	 gotoxy(30,4);
	cprintf("NAME");
	gotoxy(46,4);
	cprintf("ACCOUNT TYPE");
	gotoxy(65,4);
	cprintf("BALANCE");

 }
void loading()
{

	int j;
	//1
	for(int  i=10;i<=15;i++)
	{
	      gotoxy(23,i);
	      cout<<"Û";
	}
	for( i=10;i<=15;i++)
	{
	      gotoxy(53,i);
	      cout<<"Û";
	}
	for( i=24;i<=52;i++)
	{
	      gotoxy(i,15);
	      cout<<"Ü";
	}
	for( i=23;i<=53;i++)
	{
	      gotoxy(i,9);
	      cout<<"Ü";
	}
	for( i=24;i<=52;i++)
	{
	      gotoxy(i,12);
	      cout<<"Ü";
	}      textcolor(10);
	gotoxy(25,11);
	cout<<"LOADING... ";
	for(i=25,j=-4;i<=51;i++,j+=4)
	{
	     gotoxy(i,14);
	     delay(25);
	     textcolor(15);
	     cout<<("¯");
	     gotoxy(47,11);
	     delay(50);
	     cout<<"["<<j<<"%]";
	}
}

void menugra()
{

	int j;
	//1
	for(int  i=2;i<=24;i++)
	{
	      gotoxy(5,i);
	      cout<<"Û";
	}
	for( i=2;i<=24;i++)
	{
	      gotoxy(76,i);
	      cout<<"Û";
	}
	for( i=6;i<=75;i++)
	{
	      gotoxy(i,2);
	      cout<<"Ü";
	}
	for( i=6;i<=75;i++)
	{
	      gotoxy(i,23);
	      cout<<"Ü";
	}


}

void graphics()
{

	for(int i=1;i<=24;i++)
	{
	      gotoxy(8,i);
	      cout<<"Û";
	      gotoxy(40,i);
	      cout<<"Û";
	}

	for(i=8;i<=40;i++)
	{
	      gotoxy(i,1);
	      cout<<"Ü";
	      gotoxy(i,24);
	      cout<<"Ü";
	}

}


class Account
{
	public:
	double act;
	long acno,phno;
	double bal,bade,bawi,opbal;
	char actype[20];
	char name[30];
	char fname[30];
	char address[50];
	char city[15];

    void input()
    {
      cout<<endl<<"Enter customer's details : ";
      cout<<endl<<"Enter  ac.no : ";
      cin>>acno;
      cout<<endl<<"Enter  choice [1-2] : ";
      cout<<endl<<"1: Saving ac. ";
      cout<<endl<<"2: Current ac. ";
      cin>>act;
      if(act==1)
      {
	char s[20]="SavingAcc";
	strcpy(actype,s);

      }
      else
      {
	char s[20]="CurrentAcc";
	strcpy(actype,s);
      }
      cout<<endl<<actype;
      cout<<endl<<"Customer name : ";
      cin>>name;
      cout<<endl<<"Father's name : ";
      cin>>fname;
      cout<<endl<<"Permanent address : ";
      cin>>address;
      cout<<endl<<"City : ";
      cin>>city;
      cout<<endl<<"Phone No. : ";
      cin>>phno;
      cout<<endl<<"Opening balance : ";
      cin>>opbal;
      bal=opbal;

  }
  void output()
  {
    cout<<endl<<"-----------------";
    cout<<endl<<"Account no. : "<<acno;
    cout<<endl<<"Account type : "<<act;
    cout<<endl<<"Customer's name : "<<name;
    cout<<endl<<"Fathers name : "<<fname;
    cout<<endl<<"Address : "<<address;
    cout<<endl<<"City : "<<city;
    cout<<endl<<"Balance : "<<bal;
    cout<<endl<<"-----------------";

  }
  void get()
  {
    cout<<endl<<endl<<"         "<<acno<<"              "<<name<<"                "<<actype<<"        "<<bal;
  }

};

void newacc()
{
   clrscr();
   Account A;
   A.input();
   fstream file;
   file.open("Account.dat",ios::app|ios::binary);
   file.seekp(0,ios::end);
   file.write((char*)&A,sizeof(A));
   cout<<endl<<"Account stored ";
   file.close();
}
void list()
{
	clrscr();
	gotoxy(5,3);
	Account a;
	int b=0;
	fstream file;
	file.open("Account.dat",ios::in|ios::binary);
	file.seekg(0,ios::beg);
	listmenu();
	while(file.read((char*)&a,sizeof(a))!=0)
	{
	   a.get();
	   b++;
	}
	gotoxy(30,23);
	cout<<endl<<"      no of accounts are :"<<b;

	file.close();

	menugra();
}
void edit()
{
	clrscr();
	Account E2;
	fstream file;
	int ac;
	cout<<endl<<"Input ac no to edit";
	cin>>ac;
	file.open("Account.dat",ios::in|ios::out|ios::binary);
	file.seekg(0,ios::beg);
	int c2=0,r=0;
	while((file.read((char*)&E2,sizeof(E2)))!=0)
	{

		r++;
		if(E2.acno==ac)
		{
			E2.output();
			c2++;
			break;
		}
	 }
	 file.close();
	 if(c2==0)
	 cout<<endl<<"acno not found";
	 else
	 {
		file.open("Account.dat",ios::in|ios::out|ios::binary);
		int offset=(r-1)*sizeof(E2);
		file.seekg(offset,ios::beg);
		cout<<endl<<"input new data";
		E2.input();
		file.write((char*)&E2,sizeof(E2));
		cout<<endl<<"record updated";
		file.close();
	  }

}
void clear()
{
   clrscr();
   char n;

   fstream file1,file2,file3;
   cout<<endl<<"Sure to delete all accounts(y/n) ? : ";
   cin>>n;
   if(n=='y'||n=='Y')
   {
     file1.open("Account.dat",ios::out|ios::binary);
     file2.open("loan.dat",ios::out|ios::binary);
     file3.open("installment.dat",ios::out|ios::binary);

     cout<<endl<<"All Accounts deleted";
   }
   file1.close();
   file2.close();
   file3.close();
}
void delet()
{
	clrscr();
	Account E2;
	int ac;
	cout<<endl<<"Input account no delete";
	cin>>ac;
	fstream temp,file;
	file.open("Account.dat",ios::in|ios::out|ios::binary);
	temp.open("temp.dat",ios::in|ios::out|ios::binary);
	file.seekg(0,ios::beg);
       int c=0;
	while((file.read((char*)&E2,sizeof(E2)))!=0)
	{
		if(E2.acno==ac)
		{
			c++;
		 }
		 else
		 {
			temp.seekp(0,ios::end);
			temp.write((char*)&E2,sizeof(E2));
		 }
	}
	file.close();
	temp.close();
	if(c==0)
	{
		cout<<endl<<"Ac no not found";
	}
	else
	{
		remove("Account.dat");
		rename("temp.dat","Account.dat");
		cout<<endl<<"account deleted";
	}

     }


void search()
{
	clrscr();
	Account a;
	int ac;
	fstream file;
	file.open("Account.dat",ios::in|ios::binary);
	cout<<endl<<"Enter account no. : ";
	cin>>ac;
	int rec=0,x=0;
	file.seekg(0,ios::beg);
	while(file.read((char*)&a,sizeof(a))!=0)
	{
		rec++;
		if(ac==a.acno)
		{
		      x=1;
		      break;
		}
	}
	if(x==0)
	{
	  cout<<endl<<"Account not found ";
	}
	else
	{
	   int offset=(rec-1)*sizeof(a);
	   file.seekg(offset,ios::beg);
	   file.read((char*)&a,sizeof(a));
	   a.output();
	}
	file.close();

}

//----------------------------------

class Loan
{
   public:
     long acno;
     char type[20];
     double amount;
     int months;
     double interest;
     double total;
     double installment;

     void getLoan()
     {
	 cout<<endl<<"input account no : ";
	 cin>>acno;
	 cout<<endl<<"Choose Loan type : ";
	 cout<<endl<<"1 - Personal Loan";
	 cout<<endl<<"2 - Housing Loan";
	 cout<<endl<<"3 - Car Loan";

	 char tp[3][20]={"Personal Loan","Housing Loan","Car Loan"};
	 int c;
	 cout<<endl<<"input type : ";
	 cin>>c;
	 strcpy(type,tp[c-1]);

	 cout<<endl<<"input loan amount : ";
	 cin>>amount;
	 cout<<endl<<"input for months : ";
	 cin>>months;

	 if(c==1)
	 {
	    interest=amount*5/100;
	 }
	 else if(c==2)
	 {
	    interest=amount*3/100;
	 }
	 else
	 {
	    interest=amount*6/100;
	 }
	 total=amount+interest;
	 installment=total/months;

     }

     void showLoan()
     {
	 cout<<endl<<"Account No           : "<<acno;
	 cout<<endl<<"Loan Type            : "<<type;
	 cout<<endl<<"Loan Amount          : "<<amount;
	 cout<<endl<<"For Months           : "<<months;
	 cout<<endl<<"Interest Amount      : "<<interest;
	 cout<<endl<<"Total Payable Amount : "<<total;
	 cout<<endl<<"Installment Amount   : "<<installment;
     }
};

void newLoan()
{
	clrscr();
	fstream file;
	Loan L;

	file.open("loan.dat",ios::app|ios::binary);
	file.seekp(0,ios::end);
	L.getLoan();
	file.write((char*)&L, sizeof(L));
	cout<<endl<<"Loan data stored.";
	file.close();
}
void searchLoan()
{
	clrscr();
	fstream file;
	Loan L;

	file.open("loan.dat",ios::in|ios::binary);
	file.seekg(0,ios::beg);

	long ac;
	cout<<endl<<"Input account no. : ";
	cin>>ac;

	int x=0;
	while(file.read((char*)&L, sizeof(L))!=0)
	{
	    if(ac==L.acno)
	    {
	       L.showLoan();
	       x++;
	    }
	}
	if(x==0)
	{
	   cout<<endl<<"Account no. not found ";
	}

	file.close();
}
//----------------------------------

class Installment
{
    public:
      long acno;
      char date[20];
      double amt;

      void getInst(long ac)
      {
	 //cout<<endl<<"input account no.        : ";
	 //cin>>acno;
	 acno=ac;
	 cout<<endl<<"input date(dd/mm/yy)     : ";
	 cin>>date;
	 cout<<endl<<"input installment amount : ";
	 cin>>amt;
      }
      void showInst()
      {
	 cout<<endl<<"\t"<<date<<" \t\t "<<amt;
      }
};

void newInstallment()
{
	clrscr();
	fstream file;
	Loan L;

	file.open("loan.dat",ios::in|ios::binary);
	file.seekg(0,ios::beg);

	long ac;
	cout<<endl<<"Input account no. : ";
	cin>>ac;

	int x=0;
	while(file.read((char*)&L, sizeof(L))!=0)
	{
	    if(ac==L.acno)
	    {
	       L.showLoan();
	       cout<<endl<<"_____________________________________________________________";
	       x++;
	    }
	}
	if(x==0)
	{
	   cout<<endl<<"Account no. not found ";
	}
	else
	{
	   Installment In;
	   In.getInst(ac);
	   fstream file;
	   file.open("installment.dat",ios::app|ios::binary);
	   file.seekp(0,ios::end);
	   file.write((char*)&In,sizeof(In));
	   cout<<endl<<"installment amount paid.";
	   file.close();
	}

	file.close();
}

void showInstallment()
{
	clrscr();
	fstream file;
	Loan L;

	file.open("loan.dat",ios::in|ios::binary);
	file.seekg(0,ios::beg);

	long ac;
	cout<<endl<<"Input account no. : ";
	cin>>ac;


	int x=0;
	while(file.read((char*)&L, sizeof(L))!=0)
	{
	    if(ac==L.acno)
	    {
	       L.showLoan();
	       cout<<endl<<"_____________________________________";
	       x++;
	    }
	}
	if(x==0)
	{
	   cout<<endl<<"Account no. not found ";
	}
	else
	{
	   Installment In;
	   fstream file;
	   file.open("installment.dat",ios::in|ios::binary);
	   file.seekg(0,ios::beg);

	   cout<<endl<<"\tDate \t\t Amount";
	   cout<<endl<<"_____________________________________";

	   double total=0;
	   while(file.read((char*)&In,sizeof(In))!=0)
	   {
		In.showInst();
		total=total+In.amt;
		cout<<endl<<"-------------------------------------";

	   }
	   cout<<endl<<"\t"<<"Total Paid:\t "<<total;
	   file.close();
	}

	file.close();
}


void menu()
{

	 gotoxy(10,2);
	cout<<" 1.New Account  ";
	 gotoxy(10,4);
	cout<<" 2.List of All Accounts  ";
	 gotoxy(10,6);
	cout<<" 3.Search  ";
	 gotoxy(10,8);
	cout<<" 4.Edit  ";
	 gotoxy(10,10);
	cout<<" 5.Delete all account ";
	 gotoxy(10,12);
	cout<<" 6.Delete single account";
	 gotoxy(10,14);
	cout<<" 7.New Loan  ";
	 gotoxy(10,16);
	cout<<" 8.Search Loan Data ";
	 gotoxy(10,18);
	cout<<" 9.Pay installment  ";
	 gotoxy(10,20);
	cout<<" 10.Show paid installments";
	 gotoxy(10,22);
	cout<<" 11.Exit  ";
    }


void main()
{
      clrscr();
      pass();
      clrscr();

      loading();
      clrscr();

      while(1)
      {
	clrscr();
	int ch;
	clrscr();
	menu();
	graphics();
	gotoxy(10,23);
	cout<<"Enter choice [1-11] :";
	cin>>ch;
	clrscr();

	graphics();
	switch(ch)
	{
	    case 1:
		newacc();
		break;
	    case 2:
		list();
		break;
	    case 3:
		search();
		break;
	    case 4:
		edit();
		break;
	    case 5:
		clear();
		break;
	    case 6:
		delet();
		break;
	    case 7:
		newLoan();
		break;
	    case 8:
		searchLoan();
		break;
	    case 9:
		newInstallment();
		 break;
	    case 10:
		showInstallment();
		 break;
	    case 11:
		 exit(0);
		 break;
	 }
getch();
}
}