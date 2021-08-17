//WAP to find the standard deviation of 20 numbers 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    
    int* ptr=(int*)malloc(20*sizeof(int));
    int sum=0;
    printf("\nEnter elements\n");
    for(int i=0;i<20;i++)
    {
        scanf("%d",(ptr+i));
        sum+=*(ptr+i);
    }
    int mean=sum/20;
    sum=0;
     for(int i=0;i<20;i++)
    {
        
        *(ptr+i)-=mean;
        *(ptr+i)=(*(ptr+i))*(*(ptr+i));
        sum+=*(ptr+i);
    }
    float sd=sqrt(sum/20);
    printf("Standard deviation is:%.1f",sd);
    free(ptr);
    ptr=NULL;
    return 0;
}