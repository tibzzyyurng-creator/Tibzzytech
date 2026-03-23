#include <stdio.h>

void product(int a, int b){
    int result = a * b;
    printf("\nThe product of the two numbers is %d\n", result);
}
     
int main()
{
    int a, b;
    
    printf("Enter the first number: ");
    scanf("%d", &a);
    
    printf("\nEnter the second number: ");
    scanf("%d", &b);
    
    product(a, b);
    
	return 0;
}
