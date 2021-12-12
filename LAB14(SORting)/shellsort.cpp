#include<iostream>
using namespace std;

void shellsort(int a[],int n)
{
    int gap,i,j,temp;

    for(gap=n/2;gap>=1;gap/=2)
    {
        for(i=gap;i<n;i++)
        {
            temp=a[i];
            j=i-gap;
            while(j>=0 && a[j]>temp)
            {
                a[j+gap]=a[j];
                j-=gap;
            }
            a[j+gap]=temp;
        }
    }
}


int main()
{
    int a[]={111,1,1213,44343,3232123,2};
    int n=sizeof(a)/sizeof(a[0]);
    shellsort(a,n);
    for(int i=0;i<n;++i)
    {
        cout<<a[i]<<" ";
    }
}