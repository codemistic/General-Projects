/* ******************************************************************************************
 Billing Application for Gopalan Mall
*******************************************************************************************/

//header file

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

// created implementation file for calculator

#include "Calculator_Implementation.h"

//main file

int main()

{

  //variable declaration

  char option[50], customer_type[50], product_no[50], str[20], str2[20];
  int quantity;
  float product_cost;

  // loop to not close the program until break statement is used

  do {
    system("cls");
    fflush(stdin);
    printf("\n\n\t\t****************************************************************************\t\t\n");
    printf("\t\t\t\t..........GOPALAN MALL..........");
    printf("\n\n\t\t****************************************************************************\t\t\n");

    // Value to be entered by the user

    // customer type

    printf("\n\n\t\tEnter Customer type => ");
    printf("\n\n\t\tR = Regular, S = Special......: (Case Sensitive) =>=>");

    customer_type:

      fflush(stdin);
    scanf("%s", & customer_type);

    if (strcmp(customer_type, "R") == 0 || strcmp(customer_type, "S") == 0)

    {
      // product number

      printf("\n\n\t\tENTER PRODUCT NUMBER..........=> =>");
      fflush(stdin);
      scanf("%s", & product_no);

      // product cost

      printf("\n\n\t\tENTER PRODUCT COST PER UNIT...=> => ");

      product_cost:

        fflush(stdin);
      //scanf("%f", &product_cost);
      fflush(stdin);

      float f;
      int i = 0;

      fflush(stdin);

      scanf("%s", str);
      fflush(stdin);

      while (i < strlen(str)) {
        if (str[i] < 46 || str[i] > 57 || str[i] == 47) {
          printf("\n\n\t\t Entered value contains alphabets or symbols.");
          printf("\n\n\t\t Please Enter Product cost: ");
          goto product_cost;
        }
        i++;
      }
      product_cost = atof(str);

      if (product_cost > 10.00 && sizeof(product_cost) == 4) {
        // Quantity purchased

        printf("\n\n\t\tENTER QUANTITY PURCHASED......=> => ");
        quantity_purchased:
          fflush(stdin);
        i = 0;

        fflush(stdin);

        scanf("%s", str2);
        fflush(stdin);

        while (i < strlen(str2)) {
          if (str2[i] < 48 || str2[i] > 57) {
            printf("\n\n\t\t Entered value contains alphabets or symbols.");
            printf("\n\n\t\t Please Enter Quantity: ");
            goto quantity_purchased;
          }
          i++;
        }

        quantity = atoi(str2);
        fflush(stdin);

        if (quantity >= 1 && quantity <= 100 && sizeof(quantity) == 4) {

          // Calculating the final bill amount
          // Discount_Calculator function is called from the header file

          float final_amount = Discount_Calculator(customer_type, product_no, quantity, product_cost);

          printf("\n\n\t\t****************************************************************************\t\t\n");
          printf("\t\t\t\t..........Total Final Bill Amount: %.2f..........", final_amount);
          printf("\n\n\t\t****************************************************************************\t\t\n");

          // To exit the menu

          printf("\n\n\t\tPress 'N' / 'n' to exit or any other key to return to main menu => =>");

          scanf("%s", & option);

          if (strcmp(option, "N") == 0 || strcmp(option, "n") == 0) {
            exit(0);
          }
        }

        // If the quantity is not between 1 to 100
        else {
          printf("\n\n\t\t Please enter integer quantity between 1 and 100.");
          printf("\n\n\t\t Please re-enter quantity => => ");
          goto quantity_purchased;

        }
      }

      // If the product cost is not greater than 10
      else {
        printf("\n\n\t\t\t You have entered wrong input.\n\n\t\t\t\ Please enter integer Product cost greater than 10");
        printf("\n\n\t\t Please re-enter Product Cost => ");
        goto product_cost;

      }
    }

    // If user entered wrong customer type
    else {
      printf("\n\n\t\t Entered Customer Type is invalid.");
      printf("\n\n\t\t Please Re-enter Customer Type. => =>");
      goto customer_type;

    }
  } while (1);

  return 0;

}
