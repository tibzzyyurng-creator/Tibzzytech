#include <stdio.h>
#include <stdlib.h>

void increment(int* array, int size)
{
    int i;
   for(i = 0; i < size; i++)
   {
       array[i] = array[i] + 1;
   } 
}   
    
int main()
{
    int array[] ={1,2,3,4,5,6,7,8};
    int size = 8;
    
    increment(array,size);
    
    for(int i = 0; i < size; i++)
    printf("%d", array[i]);
    
	return 0;
}
