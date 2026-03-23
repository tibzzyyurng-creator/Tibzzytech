#include <stdio.h>
#include <string.h>

int main(){
    
//    char myString[] = "My Name is Tobi";
//    
//    char temp[50];
//    
//    strncpy(temp, myString, sizeof(temp) - 1);
//    printf("The string is : %s", temp);
//    printf("The length is : %d", strlen(myString));
    
    char src[50], dest[50];
    
    strcpy(src,  "This is source");
    strcpy(dest, "This is destination");
    
    strncat(dest, src, 15);
    
    printf("Final destination string : |%s|", dest);
    
    return 0;
}
