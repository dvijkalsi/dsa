//WAP to arrange elements of a Dynamic array, such that even numbers are followed by odd numbers
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
    int c=0;
    for(int i=0;i<n;i++)
    {
        if((ptr[i]%2)==0)
        {
            int t=ptr[c];
            ptr[c]=ptr[i];
            ptr[i]=t;
            c++;
        }
    }
    printf("\nRearranged:-\n");
     for(int i=0;i<n;i++)
    {
        printf("%d ",*(ptr+i));
        
    }
    free(ptr);
    ptr=NULL;
    return 0;
}