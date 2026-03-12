#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

   struct goods{
   int id_of_good_available;
   char name[50];
   int quantity_of_good;
   int unit_price;

   };
   
  int main()
{ 
  struct goods g[MAX];
  int item;
  int id_of_good_to_purchase;
  int quantity_of_good_requested;
  int found;
  
  printf("Number of goods received? ");
  scanf("%d", &item );
  
  if(item > 20){
     printf("\nERORR .....MAXIMUM GOODS THAT CAN BE REGISTERED IS 20....\n");
  }
  
  else if(item <= 20){
  
  for ( int i = 0; i < item; i++){
      
      
   g[i].id_of_good_available = i + 1;
  
      
  printf("\nGood %d\n", i + 1);
      
  printf("\nID of good = %d\n", g[i].id_of_good_available);

  printf("\nName of good - ");
  scanf("%s", g[i].name);
  printf("~Name of good is: %s\n",g[i].name);
  
  if(strlen(g[i].name) > 50){
     printf("\nERROR..... NAME OF GOODS CANNOT SURPASS 50 CHARACTERS...\n");
  }
  
  else if(strlen(g[i].name) <= 50){
  
  printf("\nQuantity of good - ");
  scanf("%d", &g[i].quantity_of_good);
  printf("~Quantity of good is: %d\n",g[i].quantity_of_good);
  
  printf("\nUnit price of goods - ");
  scanf("%d", &g[i].unit_price);
  printf("~Unit Price of good is: %d\n",g[i].unit_price);
  
   printf("\n******************\n\n");
  }
  
  }

  for (int x = 0; x < item; x++){
     printf("\nRecord of good %d\n", x + 1);
     printf("\nName of good = %s\n", g[x].name);
     printf("\nQuantity of %s = %d\n",g[x].name, g[x].quantity_of_good);
     printf("\nUnit Price of %s = %d\n",g[x].name, g[x].unit_price);
     }
      printf("\n<Good(s) listed above have been registered successfully..>\n");
  

  return 0;
}