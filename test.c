/////*Author: Yusuf Abdullahi
////Purpose: This program prints out my name to the screen
////Date: 12/1/2025*/

#include <stdio.h>

int main()
{
   char item1[50];
   char item2[50];
   int price1, price2;
   int qty1, qty2;
   int total1, total2, totalCost;
   int question;

   // First item
   printf("Maximum number of items you can purchase is 2\n");
   printf("\nWhat do you want to buy? ");
   scanf("%s", item1);

   printf("\nHow many do you want to buy? ");
   scanf("%d", &qty1);

   printf("\nWhat is the price of %s: ", item1);
   scanf("%d", &price1);

   // Second item
   printf("\nDo you want to buy something else? (If yes select <1> , If no select <2>) =>");
   scanf("%d", &question);
   
   if( question == 1 ){
   printf("\nWhat do you want to buy? ");
   scanf("%s", item2);

   printf("\nHow many do you want to buy? ");
   scanf("%d", &qty2);

   printf("\nWhat is the price of %s: ", item2);
   scanf("%d", &price2);

   // Calculations
   total1 = qty1 * price1;
   total2 = qty2 * price2;
   totalCost = total1 + total2;

   printf("\nThe total price = %d\n", totalCost);

   // Payment Section
   printf("\nSelect payment method (Verve or Visa): ");
   scanf("%s", item1);

   printf("\nEnter your card pin: ");
   scanf("%4s", item1);

   printf("\nPayment confirmed... Thanks for your patronage\n");

  }
  
  else if( question == 2){
 // Calculations
   total1 = qty1 * price1;

   printf("\nThe total price = %d\n", total1);

   // Payment Section
   printf("\nSelect payment method (Verve or Visa): ");
   scanf("%s", item1);

   printf("\nEnter your card pin: ");
   scanf("%4s", item1);

   printf("\nPayment confirmed... Thanks for your patronage\n");
  }
  
     return 0;
}
   
   

   
   
