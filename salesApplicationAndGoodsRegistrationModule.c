#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

   struct goods{
   int id_of_good_available;
   char name[50];
   int quantity_of_good;
   int unit_price;
   int quantity_of_good_requested;

   };
   
  int main()
{ 
  struct goods g[MAX];
  int item;
  int id_of_good_to_purchase;
  int quantity_of_good_requested;
  int found;
  int number_of_good_to_purchase;
  
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
  
     printf("How many goods do you want to purchase? ");
     scanf("%d", &number_of_good_to_purchase);

     if(number_of_good_to_purchase > 20){
     printf("\nERORR .....MAXIMUM GOODS THAT CAN BE PURCHASED IS 20....\n");
     }
  
     else if(number_of_good_to_purchase <= 20){

     for ( int G = 0; G < number_of_good_to_purchase; G++){
  
      printf("\nID of good you want to buy? ");
      scanf("%d", &id_of_good_to_purchase );

     for(int x = 0; x < item; x++){ 

     if(g[x].id_of_good_available == id_of_good_to_purchase){
    
       printf("\nHow many do you want to buy? ");
       scanf("%d", &g[x].quantity_of_good_requested);
       
       if(g[x].quantity_of_good_requested > g[x].quantity_of_good){
           printf("\nERROR...Insufficient availability of goods...SOME INFORMATIONS BELOW MIGHT BE WRONG");
           }
      
           else{
            printf("\nThe number of goods you requested is valid\n");

            printf("\nThe number of %s remaining in stock = %d \n",  g[x].name, g[x].quantity_of_good - g[x].quantity_of_good_requested );
            
            }   
            found = 1;
            
            break;
          }  
        
         }  

         if (found == 0){
           printf("\nInvalid id... Input a valid id ...... Some informations below might be wrong!!!");
       }  

      }

     }
        printf("\nSN  ID  GOOD  UNITPRICE  QUANTITY  TOTAL AMOUNT");
      for (int a = 0; a < number_of_good_to_purchase; a++)
      {
        printf("\n%d   %d   %s     %d         %d         %d   ", a + 1, g[a].id_of_good_available, g[a].name, g[a].unit_price, g[a].quantity_of_good_requested, g[a].unit_price*g[a].quantity_of_good_requested ); 
      }
   
  }
	return 0;
}
