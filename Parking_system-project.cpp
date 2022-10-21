/*
**** Vehicles parking System software using C++ ****
*/

#include <iostream>
using namespace std;
// Define functions for vehicles
int menu();
void bus();
void cycle();
void riksha();
void showdata();
void clear();

int nob = 0, noc = 0, nor = 0, amount = 0, count = 0;

int main() {
  int b;
  do {
    switch (menu()) {
      case 1:
        bus();
        break;
      case 2:
        cycle();
        break;
      case 3:
        riksha();
        break;
      case 4:
        showdata();
        break;
      case 5:
        clear();
        break;

      default:
        cout << "DEAR SIR YOU ENTER WRONG CHOICE PLEASE ENTER AGAIN" << endl;
    }

    cout << "TO ADD MORE VECHILE REPORT PRESS 0 ELSE ANY NUMBER FOR EXIT"
         << endl;
    cout << "ENTER YOUR CHOICE" << endl;
    cin >> b;

  }

  while (b == 0);
  cout << "THANK YOU PLEASE VISIT AGAIN" << endl;

  return 0;
}

int menu() {
  int choice;
  cout << "***********WELCOME TO PARKING PROJECT***********" << endl;
  cout << "PRESS 1 FOR BUS CHARGES IS 100 INR" << endl;
  cout << "PRESS 2 FOR CYCLE CHARGES IS 60 INR" << endl;
  cout << "PRESS 3 FOR RIKSHA CHARGES IS 50 INR" << endl;
  cout << "PRESS 4 FOR SEE THE ENTER RECORD " << endl;
  cout << "PRESS 5 FOR DELETE THE RECORD " << endl;
  cout << "PRESS 6 FOR EXIT" << endl;
  cout << "****************************************************" << endl;
  cin >> choice;
  return choice;
}

void bus() {
  nob++;
  amount = amount + 100;
  count++;
}

void cycle() {
  noc++;
  amount = amount + 60;
  count++;
}

void riksha() {
  nor++;
  amount = amount + 50;
  count++;
}

void showdata() {
  cout << "********YOUR RECORD***********" << endl;
  cout << "The total no of BUS standing in parking" << nob << endl;
  cout << "The total no of Cycle standing in parking" << noc << endl;
  cout << "The total no of Riksha standing in Parking" << nor << endl;
  cout << "Total collection of Parking Amount " << amount << endl;
  cout << "*********************************************" << endl;
}

void clear() {
  nob = 0;
  noc = 0;
  nor = 0;
  amount = 0;
  count = 0;
}
