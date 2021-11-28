//WAP to sort an array of n floats in an ascending order using selection sort.
#include<stdio.h>
#include<stdlib.h>
float* make(int n)
{
    float *ar=(float*)malloc(n*sizeof(float));
    printf("\nEnter array:");
    for(int i=0;i<n;++i)
    {
        scanf("%f",&ar[i]);
    }
    return ar;
}
void selection_sort(float *ar,int n)
{
    int mini;
    for(int i=0;i<n-1;++i)
    {
        mini=i;
        for(int j=i+1;j<n;++j)
        {
            if(ar[j]<ar[mini])
            {
                mini=j;
            }
        }
        float t=ar[i];
        ar[i]=ar[mini];
        ar[mini]=t;
    }
}
void disp(float* ar,int n)
{
    printf("\nArray:");
    for(int i=0;i<n;++i)
    {
        printf("%.1f ",ar[i]);
    }
}
int main()
{
    int n;
    printf("\nEnter number of elements:");
    scanf("%d",&n);
    float *ar=make(n);
    selection_sort(ar,n);
    disp(ar,n);
    return 0;
}