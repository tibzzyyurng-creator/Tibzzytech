#include <stdio.h>

int main()
{
     float examgrade =0;
    
    printf("What was your score? ");
    scanf("%f", &examgrade);

    if (examgrade >= 101){
    printf("\n*");
          }
      
    else if (examgrade >= 75){ 
    printf("\nYour score grade is A");
          }
          
    else if (examgrade >= 65){
    printf("\nYour score grade is B");
          }
          
    else if (examgrade >= 50){
    printf("\nYour score grade is C");
          }
          
    else if (examgrade >= 45){
    printf("\nYour score grade is D");
          }
          
    else if (examgrade >= 40){
    printf("\nYour score grade is E");
          }
          
    else if (examgrade >= 0){ 
    printf("\nYour score grade is F");
          }

    else if (examgrade < 0){
    printf("\n*");
          }
       
   	return 0;
}
