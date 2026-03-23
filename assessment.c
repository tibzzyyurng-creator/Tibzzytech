//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//   enum Company { GOOGLE, FACEBOOK, XEROX, YAHOO = 10, EBAY, MICROSOFT } ;
//
//   enum Company xerox = XEROX;
//   enum Company google = GOOGLE;
//   enum Company ebay = EBAY;
//
//   printf("The value of xerox is: %d\n", xerox);
//   printf("The value of google is: %d\n", google);
//   printf("The value of ebay is: %d\n", ebay);
//
//    return 0;
//}
//






//Author: Yusuf Abdullahi
//Purpose: Explaining array in C 

#include <stdio.h>

#define MONTHS 12

int main()
{
    int days[MONTHS] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int index;
    
    for (index = 0; index < MONTHS; index++)
        printf("Months %d has %2d days.\n", index +1, days[index]);
        
    return 0;    
}