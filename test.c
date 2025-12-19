#include <stdio.h>

int main()
{
   char item1[50];
   char item2[50];
   int price1, price2;
   int qty1, qty2;
   int total1, total2, totalCost;

   // First item
   printf("What do you want to buy? ");
   scanf("%s", item1);

   printf("\nHow many do you want to buy? ");
   scanf("%d", &qty1);

   printf("\nWhat is the price of %s: ", item1);
   scanf("%d", &price1);

   // Second item
   printf("\nDo you want to buy something else? ");
   scanf("%49s", item2);

   printf("\nHow many do you want to buy? ");
   scanf("%d", &qty2);

   printf("\nWhat is the price of %s: ", item2);
   scanf("%d", &price2);
   
   printf("\nIs that all? ");
   scanf("%s", item2);

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

   return 0;
}