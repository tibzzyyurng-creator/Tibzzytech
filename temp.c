# include <stdio.h>

int main ()
{
    int temp [7];           
    int count = 7;        
    long sum = 0;            
    float average = 0.0;     

    printf("\nEnter the  average temperature for each day:\n");   

    
    int i;
    for(i = 0 ; i < count ; ++i)
    {
       printf("%d> ",i + 1);
       scanf("%d", &temp[i]);     
       sum += temp[i];          
    }

    average = (float)sum/count;  
    
    printf("\nThe average temperature for the week is: %.2f\n", average);
    
    if(average >= 28){
        printf("The weather was hot");
        }
        
    else{
         printf("The weather was cold");
        }    
    
    return 0;
}

