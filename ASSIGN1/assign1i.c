//WAP to find out the kth smallest and kth largest element stored in a dynamic array of n integers,
//where k<n.
#include <stdio.h>
#include<stdlib.h>
void set_array(int **ar, int n)
{
    *ar =(int*) malloc(n*sizeof(int));
    printf("\nEnter array:");

    for(int i=0;i<n;++i)
    {
        scanf("%d", &(*ar)[i]);
    }
}
void display(int **ar, int n)
{
    printf("\nArray:");
    for(int i=0;i<n;++i)
    {
        printf("%d ",(*ar)[i]);
    }
}
void sort_array(int **ar,int n)
{
    for(int i=0;i<n-1;++i)
    {
        for(int j=0;j<n-i-1;++j)
        {
            if((*ar)[j]>(*ar)[j+1])
            {
                int t=(*ar)[j];
                (*ar)[j]=(*ar)[j+1];
                (*ar)[j+1]=t;
            }
        }
    }
}
int main()
{
    printf("\nEnter number of elements:");
    int n;
    scanf("%d",&n);
    int *ar;
    set_array(&ar,n);
    sort_array(&ar,n);
    display(&ar,n);
    printf("\nEnter k:");
    int k;
    scanf("%d",&k);
    if(k<0||k>n)
    {
        printf("Invalid k");
        return 0;
    }
    printf("\nkth smallest:%d",ar[k-1]);
    printf("\nkth largest:%d",ar[n-1-k]);
    free(ar);
    ar=NULL;
    return 0;
}