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

struct SalesRep
{
    char id[32];
    char name[64];
};

struct goods* search_by_id(
    struct goods stock[],
    int size,
    int id)
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

enum error_code_t register_sales_rep(
    struct SalesRep *rep)
{
    if (rep == NULL)
    {
        return INVALID_ARGUMENT;
    }

    printf("Enter Sales Rep ID: ");
    scanf("%31s", rep->id);

    if (strlen(rep->id) == 0)
    {
        return INVALID_ARGUMENT;
    }

    printf("Enter Sales Rep Name: ");
    scanf("%63s", rep->name);

    if (strlen(rep->name) == 0)
    {
        return INVALID_ARGUMENT;
    }

    return OK;
}

enum error_code_t register_goods(
    struct goods stock[],
    int *item)
{
    if (stock == NULL || item == NULL)
    {
        return INVALID_ARGUMENT;
    }

    printf("Number of goods received? ");
    scanf("%d", item);

    if (*item > MAX || *item <= 0)
    {
        printf("\nERROR ..... MAXIMUM GOODS THAT CAN BE REGISTERED IS 20....\n");
        return OUT_OF_BOUND;
    }

    for (int goods_to_be_registered = 0;
         goods_to_be_registered < *item;
         goods_to_be_registered++)
    {
        stock[goods_to_be_registered].id_of_good_available =
            goods_to_be_registered + 1;

        printf("\nGood %d",
               goods_to_be_registered + 1);

        printf("\nID of good = %d",
               stock[goods_to_be_registered]
               .id_of_good_available);

        printf("\nName of good - ");

        scanf("%49s",
              stock[goods_to_be_registered]
              .name);

        if (strlen(stock[goods_to_be_registered]
            .name) > 50)
        {
            printf("\nERROR..... NAME OF GOODS CANNOT SURPASS 50 CHARACTERS...\n");
            return OUT_OF_BOUND;
        }

        printf("\nQuantity of good - ");

        scanf("%d",
              &stock[goods_to_be_registered]
              .quantity_of_good);

        if (stock[goods_to_be_registered]
            .quantity_of_good < 0)
        {
            return INVALID_ARGUMENT;
        }

        printf("\nUnit price of goods - ");

        scanf("%d",
              &stock[goods_to_be_registered]
              .unit_price);

        if (stock[goods_to_be_registered]
            .unit_price < 0)
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

    int number_of_good_to_purchase;
    int quantity_of_goods_requested;
    int search_id;

    printf("\nHow many goods do you want to purchase? ");

    scanf("%d",
          &number_of_good_to_purchase);

    if (number_of_good_to_purchase > item ||
        number_of_good_to_purchase <= 0)
    {
        printf("ERROR .........\n");
        return OUT_OF_BOUND;
    }

    for (int available_goods = 0;
         available_goods < number_of_good_to_purchase;
         available_goods++)
    {
        printf("\nID of good you want to buy? ");

        scanf("%d", &search_id);

        struct goods *result =
            search_by_id(
                stock,
                item,
                search_id);

        if (result == NULL)
        {
            printf("\nInvalid id... Input a valid id ...... Some informations below might be wrong!!!");

            return INVALID_ID;
        }

        printf("item found\n");

        printf("Available Quantity: %d\n",
               result->quantity_of_good);

        printf("Unit Price: %d\n",
               result->unit_price);

        printf("How many do you want to buy?");

        scanf("%d",
              &quantity_of_goods_requested);

        if (quantity_of_goods_requested <= 0)
        {
            return INVALID_ARGUMENT;
        }

        if (quantity_of_goods_requested >
            result->quantity_of_good)
        {
            printf("\nInsufficient availability of goods\n");

            return INSUFFICIENT_STOCK;
        }

        cart[available_goods].id =
            result->id_of_good_available;

        strcpy(cart[available_goods].name,
               result->name);

        cart[available_goods].quantity =
            quantity_of_goods_requested;

        cart[available_goods].unit_price =
            result->unit_price;

        result->quantity_of_good -=
            quantity_of_goods_requested;

        printf("The number of goods requested is valid\n");

        printf("The number of goods remaining in stock is %d\n",
               result->quantity_of_good);
    }

    *purchased_count =
        number_of_good_to_purchase;

    return OK;
}

void print_receipt(
    struct cart_module cart[],
    int purchased_count,
    struct SalesRep rep)
{
    int grand_total = 0;

    printf("\n====================================");

    printf("\n           SALES RECEIPT");

    printf("\n====================================");

    printf("\nSales Rep ID   : %s",
           rep.id);

    printf("\nSales Rep Name : %s",
           rep.name);

    printf("\n\nSN  ID  GOOD  UNITPRICE  QUANTITY  TOTAL AMOUNT");

    for (int print_receipt = 0;
         print_receipt < purchased_count;
         print_receipt++)
    {
        int total =
            cart[print_receipt].unit_price *
            cart[print_receipt].quantity;

        grand_total += total;

        printf("\n%d   %d   %s     %d         %d        %d",
               print_receipt + 1,
               cart[print_receipt].id,
               cart[print_receipt].name,
               cart[print_receipt].unit_price,
               cart[print_receipt].quantity,
               total);
    }

    printf("\n------------------------------------");

    printf("\nGrand Total: %d",
           grand_total);

    printf("\n====================================\n");
}

int main()
{
    struct goods stock[MAX];

    struct cart_module cart[MAX];

    struct SalesRep rep;

    int item = 0;

    int purchased_count = 0;

    enum error_code_t result;

    result =
        register_sales_rep(&rep);

    if (result != OK)
    {
        printf("\nSales rep registration failed\n");

        return 0;
    }

    result =
        register_goods(
            stock,
            &item);

    if (result != OK)
    {
        printf("\nGoods registration failed with error code: %d\n",
               result);

        return 0;
    }

    result =
        purchase_goods(
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

    print_receipt(
        cart,
        purchased_count,
        rep);

    return 0;
}