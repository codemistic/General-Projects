/*
                                    Project Name: Scientific Calculator.
                                    Created by: Manasij Haldar
                                    B.E., 3rd Year, AIT_CSE, Chandigarh University.
                                    Language used: C++
*/


#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string>
#include<math.h>
using namespace std;
float a,b;
const float PI=3.14159265;
const float e=2.718281828;

class complex
{
   public :
      int real, img;
};

void division()
{
  cout<<"\nEnter 1st number : ";
  cin>>a;
  cout<<"Enter 2nd number : ";
  cin>>b;
  cout<<"\nDivision = "<<a/b<<endl;
}

void multiplication()
{
  cout<<"\nEnter 1st number : ";
  cin>>a;
  cout<<"Enter 2nd number : ";
  cin>>b;
  cout<<"\nMultiplication = "<<a*b<<endl;
}

void subtraction()
{
  cout<<"\nEnter 1st number : ";
  cin>>a;
  cout<<"Enter 2nd number : ";
  cin>>b;
  cout<<"\nSubtraction = "<<a-b<<endl;
}

void addition()
{
  cout<<"\nEnter 1st number : ";
  cin>>a;
  cout<<"Enter 2nd number : ";
  cin>>b;
  cout<<"\nAddition = "<<a+b<<endl;
}

void exponent()
{
  cout<<"\nEnter the number : ";
  cin>>a;
  cout<<"Enter the exponent : ";
  cin>>b;
  cout<<"\nExponent = "<<pow(a,b)<<endl;
}

void root()
{
  cout<<"\nEnter the number : ";
  cin>>a;
  cout<<"Enter the n-root : ";
  cin>>b;
  cout<<"\n"<<b<<"th Root of "<<a<<" = "<<pow(a,(1/b))<<endl;
}

void sinx()
{
  cout<<"\nEnter the number : ";
  string c;
  cin>>c;
  if (c=="Pi"||c=="pi"||c=="PI"||c=="180")
    a=0;
  else if(c=="inf") { cout<<"Sin inf = inf";return;}
  else
    a=stoi(c);
  if(a==360)a=0;
  cout<<"\nSin "<<c<<" = "<<sin(a*PI/180)<<endl;
}

void cosx()
{
  cout<<"\nEnter the number : ";
  string c;
  cin>>c;
  if (c=="Pi"||c=="pi"||c=="PI")
    a=180;
  else if(c=="inf") { cout<<"Sin inf = inf";return;}
  else
    a=stoi(c);
  if(a==90||a==270){cout<<"\nCos "<<c<<" = "<<0<<endl;return;}
  cout<<"\nCos "<<c<<" = "<<cos(a*PI/180)<<endl;
}

void tanx()
{
  cout<<"\nEnter the number : ";
  string c;
  cin>>c;
  if (c=="Pi"||c=="pi"||c=="PI")
    a=180;
  else if(c=="inf") {cout<<"Sin inf = inf";return;}
  else
    a=stoi(c);
  if(a==90||a==270) {cout<<"\nTan "<<c<<" = inf"<<endl;return;}
  else if(a==180) {cout<<"\nTan "<<c<<" = 0"<<endl;return;}
  cout<<"\nTan "<<c<<" = "<<tan(a*PI/180)<<endl;
}

void arcsinx()
{
  cout<<"\nEnter the number : ";
  cin>>a;
  cout<<"\nInverse of Sin "<<a<<" = "<<asin(a)*180.0/PI<<endl;
}

void arccosx()
{
  cout<<"\nEnter the number : ";
  string c;
  cin>>a;
  cout<<"\nInverse of Cos "<<a<<" = "<<acos(a)*180.0/PI<<endl;
}

void arctanx()
{
  cout<<"\nEnter the number : ";
  string c;
  cin>>a;
  cout<<"\nInverse of tan "<<a<<" = "<<atan(a)*180.0/PI<<endl;
}

void logx()
{
  cout<<"\nEnter the number : ";
  string c;
  cin>>c;
  if (c=="e")
    a=e;
  else
    a=stoi(c);
  cout<<"\nLog "<<c<<" = "<<log(a)<<endl;
}

void log_10()
{
  cout<<"\nEnter the number : ";
  string c;
  cin>>c;
  if (c=="e")
    a=e;
  else
    a=stoi(c);
  cout<<"\nLog "<<c<<" with base 10 = "<<log10(a)<<endl;
}

void Complexadd()
{
    complex a, b, c;

    cout << "\n\nEnter X = a+ib\n";
    cout << "\n\tX.real = ";
    cin >> a. real;
    cout << "\tX.img = ";
    cin >> a. img;
    cout << "\nEnter Y = c+id\n";
    cout << "\n\tY.real = ";
    cin >> b. real;
    cout << "\tY.img = ";
    cin >> b. img;

   c. real = a. real + b. real;
   c. img = a. img + b. img;

   if (c. img >= 0)
      cout << "\nSum of two complex numbers = " << c. real << " + " << c. img << "i";
   else
      cout << "\nSum of two complex numbers = " << c. real << " " << c. img << "i";
}

void Complexsub()
{
    complex a, b, c;

    cout << "\n\nEnter X = a+ib\n";
    cout << "\n\tX.real = ";
    cin >> a. real;
    cout << "\tX.img = ";
    cin >> a. img;
    cout << "\nEnter Y = c+id\n";
    cout << "\n\tY.real = ";
    cin >> b. real;
    cout << "\tY.img = ";
    cin >> b. img;

   c. real = a. real - b. real;
   c. img = a. img - b. img;

   if (c. img >= 0)
      cout << "\nSubtraction of two complex numbers = " << c. real << " + " << c. img << "i";
   else
      cout << "\nSubtraction of two complex numbers = " << c. real << " " << c. img << "i";
}

void Complexmult()
{
    complex a, b, c;

    cout << "\n\nEnter X = a+ib\n";
    cout << "\n\tX.real = ";
    cin >> a. real;
    cout << "\tX.img = ";
    cin >> a. img;
    cout << "\nEnter Y = c+id\n";
    cout << "\n\tY.real = ";
    cin >> b. real;
    cout << "\tY.img = ";
    cin >> b. img;

   c. real = (a. real * b. real)-(a. img * b. img);
   c. img = (a. img * b. real)+(a. real * b. img);

   if (c. img >= 0)
      cout << "\nMultiplication of two complex numbers = " << c. real << " + " << c. img << "i";
   else
      cout << "\nMultiplication of two complex numbers = " << c. real << " " << c. img << "i";
}
int main ()
{
  int x;
  while(x)
  {
    system("cls");
    cout<<endl;
    cout<<"\033[0;33m";
    cout<<"*******************************************************************************************************************\n"<<endl;
    cout<<"\t     *****     **     **        *****  **    ** **          **   **********   ***     ******        \n";
    cout<<"\t   **         *  *    **      **       **    ** **         *  *      **     **   **   **   **       \n";
    cout<<"\t  **         ******   **     **        **    ** **        ******     **    **     **  *****         \n";
    cout<<"\t   **       **    **  **      **       **    ** **       **    **    **     **   **   **  **        \n";
    cout<<"\t     ***** **      ** *******   *****  ******** ******* **      **   **       ***     **   **       \n\n";
    cout<<"*******************************************************************************************************************"<<endl;
    int c;
    cout<<"\033[0;31m";
    cout<<"-------------------------------------------------------------------------------------------------------------------\n"<<endl;
    cout<<"******************************************** Scientific Calculator ************************************************\n"<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------------------\n";
    cout<<"\033[1;34m";
    cout<<"-------------------------------------------------------------------------------------------------------------------\n";
    cout<<"Operations\t"<<"\tTrigonometric Functions"<<"\t\tLogarithmic Functions"<<"\t\tComplex Arithmetic\n";
    cout<<"-------------------------------------------------------------------------------------------------------------------\n";
    cout<<"\033[1;33m";
    cout<<"\n1: Division\t\t"<<"7: Sin\t\t"<<"\t\t13: Log"<<"\t\t\t\t15: Complex Addition"<<endl;
    cout<<"2: Multiplication\t"<<"8: Cos\t\t"<<"\t\t14: Log with base 10"<<"\t\t16: Complex Subtraction"<<endl;
    cout<<"3: Subtraction\t\t"<<"9: Tan"<<"\t\t\t\t\t\t\t\t17: Complex Multiplication"<<endl;
    cout<<"4: Addition\t\t"<<"10: Inverse of Sin"<<endl;
    cout<<"5: Exponent\t\t"<<"11: Inverse of Cos"<<endl;
    cout<<"6: N-th Root\t\t"<<"12: Inverse of Tan"<<"\t\t\t\t\t\t"<<"\033[0;31m"<<"0: EXIT\n"<<endl;
    cout<<"\033[1;32m";
    cout<<"\nEnter the function that you want to perform : ";
    cin>>c;
    cout<<"\033[1;35m";
    switch(c)
    {
          case 1:
              division();
          break;
          case 2:
              multiplication();
          break;
          case 3:
              subtraction();
          break;
          case 4:
              addition();
          break;
          case 5:
              exponent();
          break;
          case 6:
              root();
          break;
          case 7:
              sinx();
          break;
          case 8:
              cosx();
          break;
          case 9:
              tanx();
          break;
          case 10:
              arcsinx();
          break;
          case 11:
              arccosx();
          break;
          case 12:
              arctanx();
          break;
          case 13:
              logx();
          break;
          case 14:
              log_10();
          break;
          case 15:
              Complexadd();
          break;
          case 16:
              Complexsub();
          break;
          case 17:
              Complexmult();
          break;
          case 0:
              exit(0);
          break;
          default:
          cout<<"\n\nWrong Input"<<endl;
    }
    condition:
    printf("\033[1;39m");
    cout<<"\n\nContinue? (Y/N): ";
    char cond;
    cin>>cond;
    if(cond=='1'||cond=='y'||cond=='Y')
      x=1;
    else if(cond=='0'||cond=='n'||cond=='N')
      x=0;
    else
    {
      cout<<"\nInvalid choice..Try Again."<<endl;
      goto condition;
    }
  }
}
