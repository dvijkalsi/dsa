//You are given an array of 0s and 1s in random order. Segregate 0s on left side and 1s on right side 
//of the array. Traverse array only once.
#include<stdio.h>
#include<stdlib.h>
int main()
{
    printf("\nEnter size:");
    int n;
    scanf("%d",&n);
    
    int i;
    int *ar;
    ar=(int*)malloc(n*sizeof(int));
    printf("\nEnter array:");
    for(i=0;i<n;++i)
    { 
        scanf("%d",&ar[i]);
    }
    int c1=0,c2=n-1;
    int arr[n];
    for(i=0;i<n;++i)
    {
        if(!ar[i])
        {

            arr[c1++]=ar[i];

        }
        else
        {

            arr[c2--]=ar[i];
        }
    }
    ar=arr;
    printf("\nnew array:");
    for(i=0;i<n;++i)
    {
        printf("%d ",ar[i]);
    }
    free(ar);
    
    ar=NULL;
    
    return 0;
}