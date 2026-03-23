#include <stdio.h>

int main (int argc, char *argv[])
{
   int numberOfArguments = argc;
   char *argument1 = argc[0];
   char *argument2 = argv[1];

   printf("Number of Arguments: %d", numberOfArguments);
   printf("Argument 1 is the program name: %s", argument1");
   printf("Argument 2 is the command line argument: %s", argument2)

   return 0;
}




#include <stdio.h>
#include <stdlib.h>

int main()
{
    int minutesEntered = 0;
    double years = 0.0;
    double days = 0.0;
    double minutesInYear = 0;

    printf("Please enter the number of minutes: ");

    // get input from user
    scanf("%d", &minutesEntered);

    minutesInYear = (60 * 24 * 365);

    years = (minutesEntered / minutesInYear);
    days = (minutesEntered / 60.0) / 24.0;

    printf("%d minutes is approximately %f years and %f days\n", minutesEntered, years, days);

    return 0;
}
