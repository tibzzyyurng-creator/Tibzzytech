#include <stdio.h>

int main()
{
     float score =0;
    
    printf("What was your score? ");
    scanf("%f", &score);

    if (score >= 101){
    printf("\n*");
          }
      
    else if (score >= 75 && score <= 100){ 
    printf("\nYour score grade is A");
          }
          
    else if (score >= 65 && score <= 74 ){
    printf("\nYour score grade is B");
          }
          
    else if (score >= 50 && score <= 64){
    printf("\nYour score grade is C");
          }
          
    else if (score >= 45 && score <= 49){
    printf("\nYour score grade is D");
          }
          
    else if (score >= 40 && score <= 44){
    printf("\nYour score grade is E");
          }
          
    else if (score >= 0 && score <=39){ 
    printf("\nYour score grade is F");
          }

    else if (score < 0){
    printf("\n*");
          }
       
   	return 0;
}

