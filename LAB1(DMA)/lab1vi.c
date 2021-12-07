//WAP to reverse the contents of a dynamic array of N elements
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
    int t;
    for(int i=0;i<n/2;i++)
    {
        int t=ptr[i];
        ptr[i]=ptr[n-i-1];
        ptr[n-i-1]=t;
    }
    printf("\nReverse array:-\n");
     for(int i=0;i<n;i++)
    {
        printf("%d ",*(ptr+i));
        
    }
    free(ptr);
    ptr=NULL;
    return 0;
}