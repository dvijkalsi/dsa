//Find largest number in an array using DMA
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("Enter number of elements");
    scanf("%d",&n);
    int* ptr=(int*)malloc(n*sizeof(int));
    printf("\nEnter elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",(ptr+i));

    }
    int max=INT_MIN;
    for(int i=0;i<n;++i)
    {
        max=(*(ptr+i))>max?*(ptr+i):max;
    }
    printf("Largest element is:%d",max);
    free(ptr);
    ptr=NULL;
    return 0;
}
