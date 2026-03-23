#include <stdio.h>

int sum(int a, int b) {
    int result = a + b;
    printf("\nThe sum of the two numbers is: %d\n", result);
    
    return 0;
}

int main() {
    int a, b;

    printf("Enter the first number: ");
    scanf("%d", &a);
    
    printf("\nEnter the second number: ");
    scanf("%d", &b);

    sum(a, b);  
    
    return 0;
}