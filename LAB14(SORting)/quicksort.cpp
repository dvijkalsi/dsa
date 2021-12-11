#include<iostream>
using namespace std;

int partition(int ar[], int l,int h)
{
    int pivot =ar[l];
    int i=l,j=h;
    do
    {
        do
        {
            i++;
        } while (ar[i]<=pivot);
        do
        {
            j--;
        } while (ar[j]>pivot);
    }while(i<j);
    swap(ar[l],ar[j]);
    return j;
    
}
void quicksort(int ar[],int l, int h)
{
    int j;
    if(l<h)
    {
        j=partition(ar,l,h);
        quicksort(ar,l,j);
        quicksort(ar,j+1,h);
    }

}
void display(int ar[],int n)
{
    int i;cout<<"\narray:";
    for(i=0;i<n-1;++i)
    {
        cout<<ar[i]<<" ";
    }
}
int main()
{
    int ar[]={34,2,4,3,52,35,32,INT32_MAX};
    int n=sizeof(ar)/sizeof(ar[0]);
    display(ar,n);
    quicksort(ar,0,n-1);
    display(ar,n);
    return 0;
}