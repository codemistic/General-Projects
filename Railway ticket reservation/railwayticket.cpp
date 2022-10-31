To develop a C++project to manage a railway ticket reservation service using object orientedprogramming anddata file handling.

The C++programming language was developed at AT&T Bell laboratories in the early igSo’s by Biarne Stroustrup. He found out “C” lacking for simulating and decided to extend the language by adding features from his favourite language. SimtaSj was one of the earliest object-oriented languages. Biarne Stroustrup called it “C with classes” originally. The name C++ was coined by Rick Mascitti where”++”is the C increment operator. Ever since its birth, C++ evolved to cope with problems encountered by users, and through discussions at AT&T.
The major reasons for its success is the support for object oriented programming, which is most near to real world situations.
However, the maturation of the C++ language is attested by 2 recent events:-
•	The formation of an ANSI (American National Standard Institute) C++ committee, and
•	The publication of the Annotated C++ Reference Manual by Ellis and Stroustrup. One can easily judge the importance of C++ as given the following lines:-
“Object-oriented technology is regarded as the ultimate paradigm for the modeling of the information in the data of logic. The C++ is now shown to fulfill this goal”.
This is a project basedon train reservation. The program helps us to enter, display or alter the details of different trains.
Moreover & most importantly the program helps us to reserve or cancel a train ticket.
The program also helps us to know the present status of a reservedticket, i.e. whether the ticket is confirmedor not.
It includes various function programs to do the above mentionedtasks.

Data file handling has been effectively usedin the program.

This program uses the concept of object-oriented programming and data file handling.
The database is a collection of interrelated data to serve multiple applications. That is database programs create files of information. So we see that files are worked with most, inside the program.
DBMS
The software required for the management of data is called as DBMS. It has3 models
•	Relation model
•	Hierarchical model
•	Network model
RELATIONAL MODELIt’s based on the concept on relation. Relation is the table that consists of rows and columns. The rows of the table are called tuple and the columns of the table are called attribute. Numbers of rows in the table is called as cardinality. Number of columns in the table is called as degree.
HIERARCHICAL MODELIn this type of model, we have multiple records for each record. A particular recordhas one parent
record. No chid record can exist without parent record. In this, the records are organized in tree (ike structure
NETWORK MODEL:- In this, the data is representedby collection of records and relationship is represented by (ink or association.

CHARACTERISTICS OF DB MS: -
•	It reduces the redundancy
•	Reduction of data in inconsistency
•	Data sharing
•	Data standardization
DIFFERENT TYPES OF FILES: -BASED ON ACCESS:-
•	Sequentialfile
•	Serial file
•	Random (direct access) file BASED ON STORAGE:-
•	Text file
•	Binary File






Program::::
//PROGRAM - TRAIN RESERVATION #indude<iostream .h> #include<conio .h> #include<string .h> #include<dos .h> #include<stdio .h> #include<fstream .h> #include<process .h> #include<stdlib .h>
 
class train {
private :
int trainno,nofafseat,nofasseat,noffsseat,nofacseat,nofssseat; char trainname[60],startingpoint[60],destination[60]; public :
train() {
trainno=0;
nofafseat=0;
nofasseat=0;
noffsseat=0;
nofacseat=0;
nofssseat=0;
strcpy(trainname,"/0");
strcpy(startingpoint,"/0");
strcpy(destination,"/0");
}
void input();        //To input the details void display();      //To display the details int returntr(); int returnaf();
 
 
int returnas(); int returnfs(); int returnac(); int returnss();
}tr;	
int train::returntr() {
return trainno;
}	
int train::returnaf()
{
return nofafseat;
}	
int train::returnas() {
return nofasseat;
}	
int train::returnfs()
{
return noffsseat;
}	
int train::returnac()
{
return nofacseat;
}	
int train::returnss()
{
return nofssseat;
}	11
 
void train::input()
{
clrscr();
gotoxy(10,10);
cout< <"ENTER THE TRAIN NUMBER ";
gotoxy(57,10);
cin>>trainno;
gotoxy(10,12);
cout< <"ENTER THE NUMBER OF A/C FIRST CLASS SEATS";
gotoxy(57,12);
cin>>nofafseat; gotoxy(10,14);
cout< <"ENTER THE NUMBER OF A/C SECOND CLASS SEATS";
gotoxy(57,14);
cin>>nofasseat;
gotoxy(10,16);
cout< <"ENTER THE NUMBER OF FIRST CLASS SLEEPER SEATS";
gotoxy(57,16);
cin>>noffsseat; gotoxy(10,18);
cout< <"ENTER THE NUMBER OF A/C CHAIR CAR SEATS"; gotoxy(57,18);
cin>>nofacseat;
gotoxy(10,20);
cout< <"ENTER THE NUMBER OF SECOND CLASS SLEEPER SEATS";
gotoxy(57,20);
cin>>nofssseat;
gotoxy(10,22);
cout< <"ENTER THE TRAIN NAME";
gotoxy(57,22);
gets(trainname);
gotoxy(10,24);
cout<<"ENTER THE STARTING POINT ";
gotoxy(57,24);
 
 
gets(startingpoint); gotoxy(10,26);
cout<<"ENTER THE DESTINATION ";
gotoxy(57,26);
gets(destination);
 
 
 
void train::display () {
clrscr();
gotoxy(10,10); cout<<"TRAIN NUMBER "; gotoxy(47,10);
cout<<trainno;
gotoxy(10,12); cout<<"TRAIN NAME "; gotoxy(47,12);
puts(trainname);
gotoxy(10,14);
cout<<"NO OF A/C FIRST CLASS SEATS ";
gotoxy(47,14);
cout<<nofafseat;
gotoxy(10,16);
cout<<"NO OF A/C SECOND CLASS SEATS ";
gotoxy(47,16);
cout<<nofasseat;
gotoxy(10,18);
cout<<"NO OF FIRST CLASS SLEEPER SEATS ";
gotoxy(47,18);
cout<<noffsseat;
gotoxy(10,20);
cout<<"NO OF A/C CHAIR CLASS SEATS ";
gotoxy(47,20);
cout<<nofacseat;
gotoxy(10,22);
 
 
cout<<"NO OF SECOND CLASS SLEEPER SEATS ";
gotoxy(47,22);
cout<<nofssseat;
gotoxy(10,24);
cout<<"STARTING POINT ";
gotoxy(47,24);
puts(startingpoint);
gotoxy(10,26); cout<<"DESTINATION "; gotoxy(47,26);
puts(destination);
gotoxy(10,28);
cout<<"PRESS ANY KEY TO CONTINUE ";
getch();
}
 
class tickets
{
int resno,toaf,nofaf,toas,nofas,tofs,noffs,toac,nofac,toss,nofss,age;
char status[40],name[40];
public:
tickets();
void reservation();	//For ticket reservation
void cancellation();        //For ticket cancellation int ret();
void display();	//To display reservation details
}tick;
 
tickets::tickets() {
resno=0;
toaf=0;
nofaf=0;
toas=0;
nofas=0;
 
tofs=0;
noffs=0;
toac=0;
nofac=0;
toss=0;
nofss=0;
age=0;
strcpy(status,"/0"); strcpy(name,"/0");
}
 
int tickets::ret()
{
return resno;
}
 
void tickets::display()
{
int f=0; clrscr();
ifstream fn("Ticket1.dat",ios::out); fn.seekg(0);
if(!fn)
{
cout<<"ERROR IN THE FILE ";
}
X:
gotoxy(10,10);
cout<<"ENTER THE RESERVATION NO "; gotoxy(10,12);
int n; cin>>n;
while(!fn.eof())
{
fn.read((char*)&tick,sizeof(tick));
 
gotoxy(10,10);
if(n==resno)
{
clrscr();
f=1;
gotoxy(10,10);
cout< <"NAME "; gotoxy(30,10) ; cout<<name; gotoxy(10,12);
cout<<"AGE "; gotoxy(30,12);
cout<<age;
gotoxy(10,14);
cout<<"PRESENT STATUS ";
gotoxy(30,14);
cout<<status; gotoxy(10,16);
cout<<"RESERVATION NUMBER ";
gotoxy(30,16);
cout<<resno;
gotoxy(10,18);
cout<<"PRESS ANY KEY TO CONTINUE ";
getch();
}
}
if(f==0) {
clrscr();
gotoxy(10,10);
cout<<"UNRECOGINIZED RESERVATION NO !!! WANNA
RETRY ?(Y/N) "; char a;
gotoxy(10,12);
cin>>a;
if(a==y||a==Y) {
clrscr();
goto X;
}
else {
gotoxy(10,12);
cout< <"PRESS ANY KEY TO CONTINUE"; getch();
}
}
fn.close();
}
 
void tickets::reservation()
{
clrscr();
gotoxy(10,10); cout<<"RESERVATION "; gotoxy(10,12);
cout<<"ENTER THE TRAIN NO: ";
int tno,f=0; cin>>tno; ofstream file;
ifstream fin("Train1.dat",ios::out); fin.seekg(0);
if(!fin)
{
clrscr();
gotoxy(10,10); cout< <"ERROR IN THE FILE ";
clrscr();
while(!fin.eof())
{
fin.read((char*)&tr,sizeof(tr)); int z;
z=tr.returntr(); if(tno==z)
{
f=1;
nofaf=tr.returnaf();
nofas=tr.returnas();
noffs=tr.returnfs();
nofac=tr.returnac();
nofss=tr.returnss();
}
}
if(f==1)
{
file.open("Ticket1.dat",ios::app);
S:
clrscr();
gotoxy(10,10); cout<<"NAME:";
gets(name);
gotoxy(10,12); cout<<"AGE:";
cin>>age; clrscr();
gotoxy(10,10);
cout< <"SELECT THE CLASS WHICH YOU WISH TO
TRAVEL"; gotoxy(10,12);
cout<<"1.A/C FIRST CLASS " ; gotoxy(10,14);
cout<<"2.A/C SECOND CLASS " ;
gotoxy(10,16);
cout<<"3.FIRST CLASS SLEEPER " ;
gotoxy(10,18); cout<<"4.A/C CHAIR CAR " ;
gotoxy(10,20);
cout<<"5.SECOND CLASS SLEEPER ";
gotoxy(10,22);
cout<<"ENTER YOUR CHOICE "; gotoxy(30,22);
int c; cin>>c; switch(c) {
case 1:
toaf++;
resno=rand(); if((nofaf-toaf)>0)
{
strcpy(status,"confirmed");
gotoxy(10,24) ;
cout< <"STATUS";
gotoxy(30,24);
puts(status);
gotoxy(10,26); cout<<"RESERVATION NO";
gotoxy(30,26); cout<<resno;
getch();
file.write((char*)&tick,sizeof(tick)); break;
 
 
 
 
 
strcpy(status,"pending");
gotoxy(10,24);
 
cout<<"STATUS";
gotoxy(30,24); puts(status);
gotoxy(10,26); cout<<"RESERVATION NO";
gotoxy(30,26); cout<<resno;
getch();
file.write((char*)&tick,sizeof(tick)); break;
}
 
case 2:
toas++;
resno=rand();
if((nofas-toas)>0)
{
strcpy(status,"confirmed");
gotoxy(10,24) ;
cout< <"STATUS";
gotoxy(30,24);
puts(status);
gotoxy(10,26); cout<<"RESERVATION NO";
gotoxy(30,26); cout<<resno;
getch();
file.write((char*)&tick,sizeof(tick)); break;
 
 
 
 
 
strcpy(status,"pending");
gotoxy(10,24); cout<<"STATUS";
gotoxy(30,24);
puts(status);
gotoxy(10,26);
cout<<"RESERVATION NO";
gotoxy(30,26);
cout<<resno;
getch();
file.write((char*)&tick,sizeof(tick)); break;
}
 
case 3:
tofs++; resno=rand();
if((noffs-tofs)>0)
{
strcpy(status,"confirmed");
gotoxy(10,24) ;
cout< <"STATUS";
gotoxy(30,24);
puts(status);
gotoxy(10,26); cout<<"RESERVATION NO";
gotoxy(30,26); cout<<resno;
getch();
file.write((char*)&tick,sizeof(tick)); break;
}
else
{
strcpy(status,"pending");
gotoxy(10,24);
cout<<"STATUS";
gotoxy(30,24);
puts(status);
gotoxy(10,26);
cout<<"RESERVATION NO";
gotoxy(30,26);
cout<<resno;
getch();
file.write((char*)&tick,sizeof(tick)); break;
}
 
case 4:
toac++;
resno=rand();
if((nofac-toac)>0)
{
strcpy(status,"confirmed");
gotoxy(10,24) ;
cout< <"STATUS";
gotoxy(30,24);
puts(status);
gotoxy(10,26);
cout<<"RESERVATION NO";
gotoxy(30,26);
cout<<resno;
getch();
file.write((char*)&tick,sizeof(tick)); break;
}
else
{
strcpy(status,"pending");
gotoxy(10,24);
cout<<"STATUS";
gotoxy(30,24);
puts(status);
gotoxy(10,26); cout<<"RESERVATION NO"; gotoxy(30,26);
cout<<resno;
getch();
file.write((char*)&tick,sizeof(tick)); break;
}
 
case 5:
toss++; resno=rand(); if((nofss-toss)>0) {
strcpy(status,"confirmed");
gotoxy(10,24) ;
cout< <"STATUS";
gotoxy(30,24);
puts(status);
gotoxy(10,26); cout<<"RESERVATION NO";
gotoxy(30,26); cout<<resno;
getch();
file.write((char*)&tick,sizeof(tick)); break;
}
else
{
strcpy(status,"pending");
gotoxy(10,24);
cout<<"STATUS";
gotoxy(30,24);
puts(status);
gotoxy(10,26);
 
cout<<"RESERVATION NO";
gotoxy(30,26);
cout<<resno;
getch();
file.write((char*)&tick,sizeof(tick)); break;
}
}
gotoxy(10,28);
cout<<"DO YOU WISH TO CONTINUE BOOKING TICKETS (Y/N) ? "; gotoxy(57,30); char n;
cin>>n;
if(n=='y'||n=='Y') {
goto S;
}
}
}
if(f==0)
{
clrscr();
gotoxy(10,10);
cout< <"ERROR IN THE TRAIN NUMBER ENTERED !!!"; getch();
}
file.close();
}
 
void tickets::cancellation()
{
clrscr(); ifstream fin;
fin.open("Ticket1.dat",ios::out);
 
ofstream file;
file.open("Temp1.dat",ios::app);
fin.seekg(0);
gotoxy(10,10);
cout<<"ENTER THE RESERVATION NO ";
int r,f=0;
cin>>r;
if(!fin)
 
cout< <"ERROR IN THE FILE !!!";
}
while(!fin.eof())
{
fin.read((char*)&tick,sizeof(tick)); int z;
z=ret(); if(z!=r)
{
file.write((char*)&tick,sizeof(tick));
}
if(z==r) {
f=1;
}
}
file.close(); fin.close();
remove("Ticket1.dat"); rename("Temp1.dat","Ticket1.dat");
if(f==0) {
gotoxy(10,12);
cout<<"NO SUCH RESERVATION IS MADE !!! PLEASE
RETRY	";
getch();
 
}
else
{
gotoxy(10,12);
cout<<"RESERVATION CANCELLED"; getch();
}
}
 
void main() {
int ch,r=1000,j;
clrscr();
gotoxy(33,22);
cout<<"WELCOME";
Z:
clrscr(); gotoxy(25,8) ;
cout<<"RAILWAY TICKET RESERVATION"; gotoxy(25,9);
cout<<"==========================";
gotoxy(20,15) ; cout<<"1.TRAIN DETAILS";
gotoxy(20,17);
cout<<"2.UPDATE TRAIN DETAILS ";
gotoxy(20,19);
cout<<"3.RESERVING A TICKET ";
gotoxy(20,21);
cout<<"4.CANCELLING A TICKET";
gotoxy(20,23);
cout<<"5.DISPLAY THE PRESENT TICKET STATUS ";
gotoxy(20,25);
cout<<"6.EXIT";
gotoxy(20,27);
cout<<"ENTER YOUR CHOICE: ";
 
 
cin>>ch; char n;
switch(ch) {
case 1: {
ifstream fin("Train1.dat",ios::out);
fin.seekg(0);
clrscr();
if(!fin)
{
clrscr();
gotoxy(10,10);
cout< <"ERROR IN THE FILE !!!";
}
else {
clrscr();
while(!fin.eof()) {
fin.read((char*)&tr,sizeof(tr)); tr.display();
}
}
fin.close(); goto Z;
}
case 2:
clrscr();
gotoxy(20,10);
cout<<"ENTER THE PASSWORD " ;
cin>>j;
gotoxy(20,30);
cout< <"CHECKING PLEASE WAIT	";
getch();
}
{
Y:
ofstream fout("Train1.dat",ios::app); tr.input();
fout.write((char*)&tr,sizeof(tr));
fout.close();
gotoxy(10,30);
cout<<"DO YOU WISH TO CONTINUE UPDATING ?(Y/N)";
cin>>n;
if(n==y||n==Y)
goto Y; goto Z;
}
else
goto Z;
 
case 3:
tick.reservation(); goto Z;
 
case 4:
tick.cancellation(); goto Z;
 
case 5:
tick.display(); goto Z;
 
case 6:
exit(0);
}
getch();
 
</stdlib></process></fstream></stdio></dos></string></conio></iostream>

