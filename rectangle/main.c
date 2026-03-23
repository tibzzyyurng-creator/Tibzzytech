//Author: Yusuf Abdullahi
//Purpose: This program is to calculate the area and perimeter of a rectangle
//
//#include <stdio.h>
//
//int main()
//{
//	int height =5, width =3 ;
//    
//    printf("Height :5\n");
//    printf("Width :3\n");
//    printf("Perimeter = %i\n", 2* (height + width));
//    printf("Area = %i\n", height*width);
//	return 0;
//}



//Author: Yusuf Abdullahi
//Purpose: to calculate the mean of 10 random numbers
# include <stdio.h>

int main ()
{
    int grades [10];          //Array storing 10 values 
    int count = 10;         //Numbers of values to be read 
    long sum = 0;             //Sum of the numbers 
    float average = 0.0f;     //Average of the numbers 

    printf("\nEnter the 10 grades:\n");    // Prompt for the input 

    // Resad the ten numbers to be averaged
    int i;
    for(i = 0 ; i < count ; ++i)
    {
       printf("%2u> ",i + 1);
       scanf("%d", &grades[i]);      //Read to a grade
       sum += grades[i];            //Add it to sum
    }

    average = (float)sum/count;     //average
    
    printf("\nAverage of the ten grades entered is: %.2f\n", average);
    
    return 0;
}


