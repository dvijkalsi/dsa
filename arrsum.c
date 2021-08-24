//1. Wap to find the sum of array elements by using pointer
#include<stdio.h>
int main()
{
    printf("Enter size of array\n");
    int s;
    scanf("%d",&s);
    int ar[s],sum=0;
    printf("Enter array\n");
    for(int i=0;i<s;i++)
    {
        scanf("%d",&ar[i]);
    }
    int *p=ar;
    for(int i=0;i<s;i++)
    {
        sum+=*(p+i);
    }
    printf("%d ",sum);
    
    return 0;
}
