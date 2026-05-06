
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
    int id;
    char name[50];
    int quantity;
    int unit_price;
};

struct goods* search_by_id(struct goods stock[], int size, int id)
{
    for (int i = 0; i < size; i++)
    {
        if (stock[i].id_of_good_available == id)
        {
            return &stock[i];
        }
    }
    return NULL;
}


int register_goods(struct goods stock[])
{
    int item;

    printf("Number of goods received? ");
    scanf("%d", &item);

    if (item > MAX || item <= 0)
    {
        printf("ERROR: Maximum goods is %d\n", MAX);
        return 0; 
    }

    for (int i = 0; i < item; i++)
    {
        stock[i].id_of_good_available = i + 1;

        printf("\nGood %d", i + 1);
        printf("\nID = %d", stock[i].id_of_good_available);

        printf("\nName: ");
        scanf("%s", stock[i].name);
        
        printf("Quantity: ");
        scanf("%d", &stock[i].quantity_of_good);

        printf("Unit price: ");
        scanf("%d", &stock[i].unit_price);

        printf("\n------------------\n");
    }

    return item; 
}


int purchase_goods(struct goods stock[], int item, struct cart_module cart[])
{
    int number_of_goods;
    int search_id;
    int quantity_requested;

    printf("\nHow many goods do you want to purchase? ");
    scanf("%d", &number_of_goods);

    if (number_of_goods <= 0 || number_of_goods > item)
    {
        printf("ERROR: Invalid number of goods\n");
        return 0; 
    }

    for (int i = 0; i < number_of_goods; i++)
    {
        printf("\nEnter ID of good: ");
        scanf("%d", &search_id);

        struct goods *result = search_by_id(stock, item, search_id);

        if (result == NULL)
        {
            printf("Invalid ID\n");
            return i; 
        }

        printf("Available Quantity: %d\n", result->quantity_of_good);
        printf("Unit Price: %d\n", result->unit_price);

        printf("How many do you want to buy? ");
        scanf("%d", &quantity_requested);

        if (quantity_requested > result->quantity_of_good)
        {
            printf("Insufficient stock\n");
            return i; 
        }

  
        cart[i].id = result->id_of_good_available;
        strcpy(cart[i].name, result->name);
        cart[i].quantity = quantity_requested;
        cart[i].unit_price = result->unit_price;

      
        result->quantity_of_good -= quantity_requested;
    }

    return number_of_goods; 
}


void print_receipt(struct cart_module cart[], int count)
{
    printf("\nSN  ID  GOOD   UNITPRICE  QTY   TOTAL\n");

    for (int i = 0; i < count; i++)
    {
        printf("%d   %d   %s   %d        %d     %d\n",
               i + 1,
               cart[i].id,
               cart[i].name,
               cart[i].unit_price,
               cart[i].quantity,
               cart[i].unit_price * cart[i].quantity);
    }
}

int main()
{
    struct goods stock[MAX];
    struct cart_module cart[MAX];

    int item = register_goods(stock);

    if (item == 0)
        return 0; 

    int purchased = purchase_goods(stock, item, cart);

    if (purchased == 0)
        return 0; 

    print_receipt(cart, purchased);

    return 0;
}
