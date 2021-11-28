//WAP to sort an array of n integers in a descending order using insertion sort.
#include<stdio.h>
#include<stdlib.h>
int* make(int n)
{
    int *ar=(int*)malloc(n*sizeof(int));
    printf("\nEnter array:");
    for(int i=0;i<n;++i)
    {
        scanf("%d",&ar[i]);
    }
    return ar;
}
void disp(int* ar,int n)
{
    printf("\nArray:");
    for(int i=0;i<n;++i)
    {
        printf("%d ",ar[i]);
    }
}
void insertionSort(int *ar,int n)
{
    int i,k,j;
    for (i=1;i<n;i++)
    {
        k=ar[i];
        j=i-1;
        while(j>=0 && ar[j]>k) 
        {
            ar[j+1]=ar[j];
            j--;
        }
        ar[j+1]=k;
    }
}
int main()
{
    int n;
    printf("\nEnter number of elements:");
    scanf("%d",&n);
    int *ar=make(n);
    insertionSort(ar,n);
    disp(ar,n);
    return 0;

}