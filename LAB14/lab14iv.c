//WAP to verify that the algorithm is Adaptive and Stable or not for Bubble sort,Insertion sort and Selection 
//sort.
#include<stdio.h>
#include<stdlib.h>
typedef struct arr AR;
 struct arr
{
    int item;
    char code;
};
void disp(int* ar,int n)
{
    printf("\nArray:");
    for(int i=0;i<n;++i)
    {
        printf("%d ",ar[i]);
    }
}
void bubble_sort(int *ar,int n)
{
    int i,j, noSwap;
    for(i=0;i<n-1;++i)
    {
        noSwap=1;
        for(j=0;j<n-i-1;++j)
        {
            if(ar[j]>ar[j+1])
            {
                noSwap=0;
                int t=ar[j+1];
                ar[j+1]=ar[j];
                ar[j]=t;
            }
        }
        if(noSwap) break;
    }
}
void insertion_sort(int *ar,int n)
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
void selection_sort(int *ar,int n)
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
        int t=ar[i];
        ar[i]=ar[mini];
        ar[mini]=t;
    }
}
int* make(int n)
{
    AR *ar=(AR*)malloc(n*sizeof(AR));
    char ch='a';
    printf("\nEnter array:");
    for(int i=0;i<n;++i,ch++)
    {
        scanf("%d",&(ar[i].item));
        ar[i].code=ch;
    }
    return ar;
}

int main()
{

}