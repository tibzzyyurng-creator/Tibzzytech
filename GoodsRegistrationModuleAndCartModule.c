#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

struct goods
{
  int id_of_good_available;
  char name[50];
  int quantity_of_good;
  int unit_price;
};

struct cart_module
{
  int quantity_of_good_requested;

};

struct search_by_id
{
  int item;
  int id_of_good_to_purchase;
};

struct goods* search_by_id(struct goods* available_goods, int size, int id)
{
  for (int i = 0; i < size; i++)
  {
    if((available_goods + i)->id_of_good_available == id)
    {
      return (available_goods + i);
    }
  }
    return NULL;
}

int main()
{
  struct goods stock[MAX];
  struct cart_module cart[MAX];
  int item;
  int id_of_good_to_purchase;
  int number_of_good_to_purchase;
  int max_of_goods_to_purchase = 20;
  int quantity_of_goods_requested;
  int search_id;

  printf("Number of goods received? ");
  scanf("%d", &item);

  if (item > max_of_goods_to_purchase)
  {
    printf("\nERORR .....MAXIMUM GOODS THAT CAN BE REGISTERED IS 20....");
  }

  else if (item <= max_of_goods_to_purchase)
  {

    for (int goods_to_be_registered= 0; goods_to_be_registered < item; goods_to_be_registered++)
    {
      stock[goods_to_be_registered].id_of_good_available = goods_to_be_registered + 1;

      printf("\nGood %d", goods_to_be_registered + 1);

      printf("\nID of good = %d", stock[goods_to_be_registered].id_of_good_available);

      printf("\nName of good - ");
      scanf("%s", stock[goods_to_be_registered].name);
      
      if (strlen(stock[goods_to_be_registered].name) > 50)
      {
       printf("\nERROR..... NAME OF GOODS CANNOT SURPASS 50 CHARACTERS...\n");
      }

      else if (strlen(stock[goods_to_be_registered].name) <= 50)
      {
        printf("\nQuantity of good - ");
        scanf("%d", &stock[goods_to_be_registered].quantity_of_good);
       

        printf("\nUnit price of goods - ");
        scanf("%d", &stock[goods_to_be_registered].unit_price);
        

        printf("\n******************\n");
      }
    }

    printf("\nHow many goods do you want to purchase? ");
    scanf("%d", &number_of_good_to_purchase);

    if (number_of_good_to_purchase > item)
    {
      printf("ERORR .........\n");
    }

    else if (number_of_good_to_purchase <= item)
    {
     for (int available_goods = 0; available_goods < number_of_good_to_purchase; available_goods++)
     {    
       printf("\nID of good you want to buy? ");
       scanf("%d", &search_id);

       struct goods *result = search_by_id(stock, item, search_id);
       
        if (result != NULL)
        {
          printf("item found\n"); 

          printf("Available Quantity: %d\n", result->quantity_of_good);

          printf("Unit Price: %d\n", result->unit_price);

          printf("How many do you want to buy?");
          scanf("%d", &quantity_of_goods_requested);

         if (quantity_of_goods_requested <= result->quantity_of_good)
         {
           printf("The number of goods requested is valid\n");
            printf("The number of goods remaining in stock is %d", result->quantity_of_good - quantity_of_goods_requested);
         }
         else
           {
             printf("\nInsufficient availability of goods\n");
           }
        } 

         else
         {
           printf("\nInvalid id... Input a valid id ...... Some informations below might be wrong!!!");
         } 
      }

     printf("\nSN  ID  GOOD  UNITPRICE  QUANTITY  TOTAL AMOUNT");
     for (int print_receipt = 0; print_receipt < number_of_good_to_purchase; print_receipt++)
     {
       printf("\n%d   %d   %s     %d         %d        %d   ", print_receipt + 1, stock[print_receipt].id_of_good_available, stock[print_receipt].name, stock[print_receipt].unit_price, quantity_of_goods_requested, stock[print_receipt].unit_price * quantity_of_goods_requested);
     } 
      
    }
  }
  return 0;
}
