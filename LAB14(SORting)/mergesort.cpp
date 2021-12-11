#include<iostream>
#include<stdio.h>
using namespace std;

// int* merge(int a[],int b[], int m, int n)
// {
//     int i,j,k;
//     i=j=k=0;
//     int *c=new int[m+n];
//     while(i<m && j<n)
//     {
//         if(a[i]<b[i])
//         {
//             c[k++]=a[i++];
//         }
//         else 
//         {
//             c[k++]=b[j++];
//         }
//     }
//     for(;i<m;i++)
//     c[k++]=a[i];
//     for(;j<m;j++)
//     c[k++]=b[j];
//     return c;
// }
void merge(int a[],int l,int mid, int h)
{
    int i,j,k;
    i=k=l;

    j=mid+1;


    int c[100];
    while(i<=mid && j<=h)
    {
        if(a[i]<a[j])
        {
            c[k++]=a[i++];
        }
        else 
        {
            c[k++]=a[j++];
        }
    }
    for(;i<=mid;i++)
    c[k++]=a[i];
    for(;j<=h;j++)
    c[k++]=a[j];
    
    for(i=l;i<=h;i++)
    a[i]=c[i];
}

// void mergesort(int a[], int n)
// {
//     int p,l,h,i;
//     for(p=2;p<=n;p*=2)
//     {
//         for(i=0;i+p-1<n;i+=p)
//         {
//             l=i;
//             h=i+p-1;
            
//             merge(a,l,h);
//         }
//     }
// //if(p/2 < n)
//     merge(a,0,n-1);
// }
void mergesort(int a[],int l,int h)
{
    int mid;
    if(l<h)
    {
        mid=(l+h)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,h);
        merge(a,l,mid,h);
    }
}
int main()
{
    int a[]={4,3,7,51,8,10,13,5,832,32,89};
    int n=sizeof(a)/sizeof(a[0]);
    mergesort(a,0,n-1);
    for(int i=0;i<n;++i)
    {
        cout<<a[i]<<" ";
    }
}