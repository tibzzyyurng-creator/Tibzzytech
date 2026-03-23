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
  int quantity_of_good_requested;
};

struct goods * search_by_id (struct goods * available_goods, int id_of_good_available)
{
 
 

}


int main()
{
  struct goods stock[MAX];
  int item;
  int id_of_good_to_purchase;
  int found;
  int number_of_good_to_purchase;

  printf("Number of goods received? ");
  scanf("%d", &item);

  if (item > 20)
  {
    printf("\nERORR .....MAXIMUM GOODS THAT CAN BE REGISTERED IS 20....\n");
  }

  else if (item <= 20)
  {

    for (int goods_to_be_registered= 0; goods_to_be_registered < item; goods_to_be_registered++)
    {
      stock[goods_to_be_registered].id_of_good_available = goods_to_be_registered + 1;

      printf("\nGood %d\n", goods_to_be_registered + 1);

      printf("\nID of good = %d\n", stock[goods_to_be_registered].id_of_good_available);

      printf("\nName of good - ");
      scanf("%s", stock[goods_to_be_registered].name);
      printf("~Name of good is: %s\n", stock[goods_to_be_registered].name);

      if (strlen(stock[goods_to_be_registered].name) > 50)
      {
        printf("\nERROR..... NAME OF GOODS CANNOT SURPASS 50 CHARACTERS...\n");
      }

      else if (strlen(stock[goods_to_be_registered].name) <= 50)
      {
        printf("\nQuantity of good - ");
        scanf("%d", &stock[goods_to_be_registered].quantity_of_good);
        printf("~Quantity of good is: %d\n", stock[goods_to_be_registered].quantity_of_good);

        printf("\nUnit price of goods - ");
        scanf("%d", &stock[goods_to_be_registered].unit_price);
        printf("~Unit Price of good is: %d\n", stock[goods_to_be_registered].unit_price);

        printf("\n******************\n\n");
      }
    }

    printf("How many goods do you want to purchase? ");
    scanf("%d", &number_of_good_to_purchase);

    if (number_of_good_to_purchase > 20)
    {
      printf("\nERORR .....MAXIMUM GOODS THAT CAN BE PURCHASED iS 20....\n");
    }

    else if (number_of_good_to_purchase <= 20)
    {
      for (int available_goods = 0; available_goods < number_of_good_to_purchase; available_goods++)
      {
        printf("\nID of good you want to buy? ");
        scanf("%d", &id_of_good_to_purchase);

        for (int search_by_id = 0; search_by_id < item; search_by_id++)
        {
          if (stock[search_by_id].id_of_good_available == id_of_good_to_purchase)
          {
            printf("\nHow many do you want to buy? ");
            scanf("%d", &stock[search_by_id].quantity_of_good_requested);

            if (stock[search_by_id].quantity_of_good_requested > stock[search_by_id].quantity_of_good)
            {
              printf("\nERROR...Insufficient availability of goods...SOME INFORMATIONS BELOW MIGHT BE WRONG");
            }

            else
            {
              printf("\nThe number of goods you requested is valid\n");

              printf("\nThe number of %s remaining in stock = %d \n", stock[search_by_id].name, stock[search_by_id].quantity_of_good - stock[search_by_id].quantity_of_good_requested);
            }
            found = 1;
            break;
          }
        }

        if (found == 0)
        {
          printf("\nInvalid id... Input a valid id ...... Some informations below might be wrong!!!");
        }
      }
    }
    printf("\nSN  ID  GOOD  UNITPRICE  QUANTITY  TOTAL AMOUNT");
    for (int print_receipt = 0; print_receipt < number_of_good_to_purchase; print_receipt++)
    {
      printf("\n%d   %d   %s     %d         %d         %d   ", print_receipt + 1, stock[print_receipt].id_of_good_available, stock[print_receipt].name, stock[print_receipt].unit_price, stock[print_receipt].quantity_of_good_requested, stock[print_receipt].unit_price * stock[print_receipt].quantity_of_good_requested);
    }
  }
  return 0;
}
