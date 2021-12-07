//WAP sort the n names in an alphabetical order.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char** make(int n)
{
    char **ar=(char**)malloc(n*sizeof(char*));
    printf("\nEnter array:\n");
    for(int i=0;i<n;++i)
    {
        ar[i]=(char*)malloc(20*sizeof(char));
        gets(ar[i]);
    }
    return ar;
}
void disp(char** ar,int n)
{
    printf("\nArray:");
    for(int i=0;i<n;++i)
    {
        printf("\n%s",ar[i]);
    }
}
void insertionSort(char **ar,int n)
{
    int i,j;
    char* k;
    for (i=1;i<n;i++)
    {
        k=ar[i];
        j=i-1;
        while(j>=0 && (strcmp(ar[j],k) >0))
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
    n++;
    char **ar=make(n);
    insertionSort(ar,n);
    disp(ar,n);
    return 0;

}