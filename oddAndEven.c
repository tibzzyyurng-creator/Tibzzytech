#include <stdio.h>

int main()
{
    int number;

	printf("Enter your number: ");
    scanf("%d", &number);
    
    
    if(number % 2 == 0){
        printf("The number is an even number");
    }
        
    else {
        printf("The number is an odd number");
    }
        
	return 0;
}
