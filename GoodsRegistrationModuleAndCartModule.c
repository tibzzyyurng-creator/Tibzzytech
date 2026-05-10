#include <stdio.h>
#include <string.h>

#define MAX 20

enum error_code_t
{
    OK,
    INVALID_ARGUMENT,
    OUT_OF_BOUND,
    INVALID_ID,
    INSUFFICIENT_STOCK
};

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

enum error_code_t register_goods(struct goods stock[], int *item)
{
    if (stock == NULL || item == NULL)
    {
        return INVALID_ARGUMENT;
    }

    printf("Number of goods received? ");
    scanf("%d", item);

    if (*item <= 0 || *item > MAX)
    {
        return OUT_OF_BOUND;
    }

    for (int i = 0; i < *item; i++)
    {
        stock[i].id_of_good_available = i + 1;

        printf("\nGood %d", i + 1);

        printf("\nID of good = %d",
               stock[i].id_of_good_available);

        printf("\nName of good - ");
        scanf("%49s", stock[i].name);

        if (strlen(stock[i].name) >= 50)
        {
            return OUT_OF_BOUND;
        }

        printf("\nQuantity of good - ");
        scanf("%d", &stock[i].quantity_of_good);

        if (stock[i].quantity_of_good < 0)
        {
            return INVALID_ARGUMENT;
        }

        printf("\nUnit price of goods - ");
        scanf("%d", &stock[i].unit_price);

        if (stock[i].unit_price < 0)
        {
            return INVALID_ARGUMENT;
        }

        printf("\n******************\n");
    }

    return OK;
}

enum error_code_t purchase_goods(
    struct goods stock[],
    int item,
    struct cart_module cart[],
    int *purchased_count)
{
    if (stock == NULL ||
        cart == NULL ||
        purchased_count == NULL)
    {
        return INVALID_ARGUMENT;
    }

    int number_of_goods;
    int search_id;
    int quantity_requested;

    printf("\nHow many goods do you want to purchase? ");
    scanf("%d", &number_of_goods);

    if (number_of_goods <= 0 ||
        number_of_goods > item)
    {
        return OUT_OF_BOUND;
    }

    for (int i = 0; i < number_of_goods; i++)
    {
        printf("\nID of good you want to buy? ");
        scanf("%d", &search_id);

        struct goods *result =
            search_by_id(stock, item, search_id);

        if (result == NULL)
        {
            return INVALID_ID;
        }

        printf("Available Quantity: %d\n",
               result->quantity_of_good);

        printf("Unit Price: %d\n",
               result->unit_price);

        printf("How many do you want to buy? ");
        scanf("%d", &quantity_requested);

        if (quantity_requested <= 0)
        {
            return INVALID_ARGUMENT;
        }

        if (quantity_requested >
            result->quantity_of_good)
        {
            return INSUFFICIENT_STOCK;
        }

        cart[i].id =
            result->id_of_good_available;

        strcpy(cart[i].name, result->name);

        cart[i].quantity =
            quantity_requested;

        cart[i].unit_price =
            result->unit_price;

        result->quantity_of_good -=
            quantity_requested;
    }

    *purchased_count = number_of_goods;

    return OK;
}

void print_receipt(
    struct cart_module cart[],
    int purchased_count)
{
    printf("\nSN  ID  GOOD  UNITPRICE  QUANTITY  TOTAL");

    for (int i = 0; i < purchased_count; i++)
    {
        printf("\n%d   %d   %s     %d         %d        %d",
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

    int item = 0;
    int purchased_count = 0;

    enum error_code_t result;

    result = register_goods(stock, &item);

    if (result != OK)
    {
        printf("\nRegistration failed with error code: %d\n",
               result);
        return 0;
    }

    result = purchase_goods(
        stock,
        item,
        cart,
        &purchased_count);

    if (result != OK)
    {
        printf("\nPurchase failed with error code: %d\n",
               result);
        return 0;
    }

    print_receipt(cart, purchased_count);

    return 0;
}