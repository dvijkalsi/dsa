#include<iostream>
using namespace std;
int find_max(int a[],int n)
{
    int max=a[0];
    for(int i=1;i<n;++i)
    {
        if(max<a[i])
        max=a[i];
    }
    return max;
}
void count_sort(int a[],int n)
{
    int max, i, j;
    int *c;
    max=find_max(a,n);
    c=new int[max+1];
    for(i=0;i<=max;i++)
    c[i]=0;
    for(i=0;i<n;i++)
    {
        c[a[i]]++;
    }
    i=0;
    j=0;
    while(i < max+1)
    {
        if(c[i]>0)
        {
            a[j++]=i;
            c[i]--;
        }
        else
        {
            i++;
        }
    }
}
int main()
{
    int a[]={4,3,7,1,8,10,13,5,2,32,8};
    int n=sizeof(a)/sizeof(a[0]);
    count_sort(a,n);
    for(int i=0;i<n;++i)
    {
        cout<<a[i]<<" ";
    }
}