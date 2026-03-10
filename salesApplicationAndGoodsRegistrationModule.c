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
  int item, i;
  int id_of_good_to_purchase;
  int quantity_of_good_requested;
  int x;
  int current_goods;
  
  printf("Number of goods received? ");
  scanf("%d", &item );
  
  if(item > 20){
     printf("\nERROR_SOME_INFORMATIONS_BELOW_MIGHT_BE_WRONG....\n");
  }
  
  else if(item <= 20){
  
  for (i = 0; i < item; i++){
      
      
   g[i].id_of_good_available = i + 1;
  
      
  printf("\nGood %d\n", i + 1);
      
  printf("\nID of good = %d\n", g[i].id_of_good_available);

  printf("\nName of good - ");
  scanf("%s", g[i].name);
  printf("~Name of good is: %s\n",g[i].name);
  
  if(strlen(g[i].name) > 50){
     printf("\nERROR_SOME_INFORMATIONS_BELOW_MIGHT_BE_WRONG....\n");
  }
  
  else if(strlen(g[i].name) <= 50){
  
  printf("\nQuantity of good - ");
  scanf("%d", &g[i].quantity_of_good);
  printf("~Quantity of good is: %d\n",g[i].quantity_of_good);
  
  printf("\nUnit price of goods - ");
  scanf("%d", &g[i].unit_price);
  printf("~Unit Price of good is: %d\n",g[i].unit_price);
 // g[i].id = id;
  
   printf("\n******************\n\n");
  }
  
  }
  
  
   printf("\nID of good you want to buy? ");
   scanf("%d", &id_of_good_to_purchase );

  //step 1 loop through array

  for( x = 0; x < item; x++){ 

    current_goods == x + 1;

    g[x].id_of_good_available == current_goods;

  if(current_goods == id_of_good_to_purchase){
    
       printf("\nHow many do you want to buy? ");
       scanf("%d", &quantity_of_good_requested);
       
       if(quantity_of_good_requested > g[x].quantity_of_good){
           printf("\nInsufficient availability of goods");
           }
      
        else{
            printf("\nThe number of goods you requested is valid");

            printf("\nThe number of %s remaining in stock = %d ",  g[x].name, g[x].quantity_of_good - quantity_of_good_requested );
            
            }   
          }


            else{
           printf("\nInvalid id... Input a valid id ...... Some informations below might be wrong!!!");
       } 
        
      }  
      
      
      
    
  
         
//   for (int x = 0; x < item; x++){
//      printf("\nRecord of good %d\n", x + 1);
//      printf("\nName of good = %s\n", g[x].name);
//      printf("\nQuantity of %s = %d\n",g[x].name, g[x].quantity);
//      printf("\nUnit Price of %s = %d\n",g[x].name, g[x].unitprice);
//      }
//       printf("\n<Good(s) listed above have been registered successfully..>\n");
       
       
   
  }
	return 0;
}
