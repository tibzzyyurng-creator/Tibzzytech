#include <stdio.h>

int main() {
    int num, isPrime = 1;
    int count = 0;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
       // Prime numbers are greater than 1
     if (num <= 1) {
       isPrime = 0;
     }
     else {
        for (count = 2; count <= num / 2; ++count) 
            {
            if (num % count == 0) {
                isPrime = 0;
                break;
            }
        }
    }

    if (isPrime)
        printf("%d is a prime number.\n", num);
    else 
        printf("%d is not a prime number.\n", num);

    return 0;
}



//#include <stdio.h>
//int main() {
//    int n;
//    int cnt = 0;
//    // Ask user for input
//    printf("Enter a number: ");
//    scanf("%d", &n);
//    // If number is less than or equal to 1, it is not prime
//    if (n <= 1)
//        printf("%d is NOT prime\n", n);
//    else {
//        // Count divisors
//        for (int i = 1; i <= n; i++) {
//            if (n % i == 0)
//                cnt++;
//        }
//        // Check prime
//        if (cnt > 2)
//            printf("%d is NOT prime\n", n);
//        else
//            printf("%d is prime\n", n);
//    }
//    return 0;
//}