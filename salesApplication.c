#include <stdio.h>

int main()
{
   char item[20];
   int index;
   int quantity2;
   int price;
   int goods;
   int i;
   
  printf("GOODS REGISTRATION MODULE\n");
  printf("--Registration of new goods--\n");
  
  printf("Number of goods you want to purchase? ");
  scanf("%d", &goods );
  
  for ( i = 0; i < goods; i++){
      
  printf("\nName of goods - ", i + 1);
  scanf("%s", item);
  
  printf("\nID of goods - ", i + 1);
  scanf("%d", &index);
  
  printf("\nQuantity of goods - ", i + 1);
  scanf("%d", &quantity2);
  
  printf("\nUnit price of goods - ", i + 1);
  scanf("%d", &price);
  }
  
  printf("\nGood(s) listed above have been registered successfully..\n");
	return 0;
}
