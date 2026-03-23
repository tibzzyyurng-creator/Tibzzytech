/*Author: Yusuf Abdullahi
Purpose: This program prints out my name to the screen
Date: 11/20/2025*/

#include <stdio.h>

int main()
{
//    enum gender {male, female} ;
//    
//    enum gender myGender;
//    
//    myGender = male;
//    
//    enum gender anotherGender = female;
//    
//    char myCharacter = '\n';
//    
//    printf("%c", myCharacter);

    unsigned int a = 60; // 0011 1100
    unsigned int b = 13; // 0000 1101
    int result = 0;
    
    result = a & b; 
    // 0011 1101
    printf("result is %d", result);
    
	return 0;
}
