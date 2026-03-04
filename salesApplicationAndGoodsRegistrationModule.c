#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

   struct goods{
   int id;
   char name[50];
   float quantity_of_good;
   int unit_price;

   };
   
  int main()
{ 
  struct goods g[MAX];
  int item, i;
  int iD;
  float quantity_of_good_requested;
  
  printf("Number of goods received? ");
  scanf("%d", &item );
  
  if(item > 20){
     printf("\nERROR_SOME_INFORMATIONS_BELOW_MIGHT_BE_WRONG....\n");
  }
  
  else if(item <= 20){
  
  for (i = 0; i < item; i++){
      
      
  int id = i + 1;
  
      
  printf("\nGood %d\n", i + 1);
      
  printf("\nID of good = %d\n", i + 1);
  //printf("%d", g[i].id);

  printf("\nName of good - ");
  scanf("%s", g[i].name);
  printf("~Name of good is: %s\n",g[i].name);
  
  if(strlen(g[i].name) > 50){
     printf("\nERROR_SOME_INFORMATIONS_BELOW_MIGHT_BE_WRONG....\n");
  }
  
  else if(strlen(g[i].name) <= 50){
  
  printf("\nQuantity of good - ");
  scanf("%f", &g[i].quantity_of_good);
  printf("~Quantity of good is: %f\n",g[i].quantity_of_good);
  
  printf("\nUnit price of goods - ");
  scanf("%d", &g[i].unit_price);
  printf("~Unit Price of good is: %d\n",g[i].unit_price);
  g[i].id = id;
  
   printf("\n******************\n\n");
  }
  
  }
  
  
   printf("\nID of good you want to buy? ");
   scanf("%d", &iD );

  //step 1 loop through array

  for(int x = 0; x <  item; x++){ 

  struct goods current_good = g[x]; 

  //struct goods g[x];
  if(iD == g[x].id){
    
       printf("\nHow many do you want to buy? ");
       scanf("%f", &quantity_of_good_requested);
       
       if(quantity_of_good_requested > g[x].quantity_of_good){
           printf("Insufficient availability of goods");
           }
      
        else{
            printf("\nThe number of goods you requested is valid");
            printf("\nThe number of %s remaining in stock = %f ",  g[x].name, g[x].quantity_of_good - quantity_of_good_requested );
            
            }   
          }
       
       else{
           printf("Invalid id... Input a valid id");
       } 
      }                    
      
      
    
  
         
//   for (int x = 0; x < item; x++){
//      printf("\nRecord of good %d\n", x + 1);
//      printf("\nName of good = %s\n", g[x].name);
//      printf("\nQuantity of %s = %d\n",g[x].name, g[x].quantity);
//      printf("\nUnit Price of %s = %d\n",g[x].name, g[x].unitprice);
//      }
//       printf("\n<Good(s) listed above have been registered successfully..>\n");
       
       
       
          //     printf("\nID of good you want to buy? ");
          //     scanf("%d", id );
     
     

//     printf("\nHow many do you want to buy? ");
//     scanf("%d", &qty1);
//
//     printf("\nWhat is the price of %s: ", item1);
//     scanf("%f", &price1);

  }
	return 0;
}

