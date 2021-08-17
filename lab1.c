//WAP to allocate memory dynamically using malloc or calloc to store N numbers
// entered by the user and display all the numbers and average of numbers
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("Enter number of elements");
    scanf("%d",&n);
    int* ptr=(int*)malloc(n*sizeof(int));
    int sum=0;
    printf("\nEnter elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",(ptr+i));
        sum+=*(ptr+i);
    }
    double avg=sum/n;
    printf("\nDisplaying elements:-\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",*(ptr+i));

    }
    printf("\nAvg:%.1lf",avg);
    free(ptr);
    ptr=NULL;
    return 0;

}