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
    int quantity_of_good_requested;
};

/* FUNCTION TO SEARCH ITEM BY ID */
int search_by_id(struct goods stock[], int item, int id)
{
    for (int i = 0; i < item; i++)
    {
        if (stock[i].id_of_good_available == id)
        {
            return i; // return index
        }
    }
    return -1; // not found
}

int main()
{
    struct goods stock[MAX];
    struct cart_module cart[MAX];

    int item;
    int number_of_good_to_purchase;

    printf("Number of goods received? ");
    scanf("%d", &item);

    if (item > MAX)
    {
        printf("\nERROR: Maximum goods allowed is 20\n");
        return 0;
    }

    /* INPUT GOODS */
    for (int i = 0; i < item; i++)
    {
        stock[i].id_of_good_available = i + 1;

        printf("\nGood %d\n", i + 1);

        printf("ID: %d\n", stock[i].id_of_good_available);

        printf("Name: ");
        scanf("%s", stock[i].name);

        printf("Quantity: ");
        scanf("%d", &stock[i].quantity_of_good);

        printf("Unit Price: ");
        scanf("%d", &stock[i].unit_price);

        printf("----------------------\n");
    }

    printf("\nHow many goods do you want to purchase? ");
    scanf("%d", &number_of_good_to_purchase);

    if (number_of_good_to_purchase > item)
    {
        printf("ERROR: Cannot purchase more than available goods\n");
        return 0;
    }

    /* PURCHASE PROCESS */
    for (int i = 0; i < number_of_good_to_purchase; i++)
    {
        int id;
        printf("\nEnter ID of good to buy: ");
        scanf("%d", &id);

        int index = search_by_id(stock, item, id);

        if (index == -1)
        {
            printf("Invalid ID!\n");
            i--; // retry
            continue;
        }

        cart[i].id = id;

        printf("How many do you want to buy? ");
        scanf("%d", &cart[i].quantity_of_good_requested);

        if (cart[i].quantity_of_good_requested > stock[index].quantity_of_good)
        {
            printf("ERROR: Not enough stock available\n");
            i--; // retry
        }
        else
        {
            stock[index].quantity_of_good -= cart[i].quantity_of_good_requested;
            printf("Item added to cart successfully\n");
        }
    }

    /* PRINT RECEIPT */
    printf("\n\nSN  ID  NAME   UNITPRICE  QTY  TOTAL\n");

    for (int i = 0; i < number_of_good_to_purchase; i++)
    {
        int index = search_by_id(stock, item, cart[i].id);

        int total = stock[index].unit_price * cart[i].quantity_of_good_requested;

        printf("%d   %d   %s   %d   %d   %d\n",
               i + 1,
               cart[i].id,
               stock[index].name,
               stock[index].unit_price,
               cart[i].quantity_of_good_requested,
               total);
    }

    return 0;
}