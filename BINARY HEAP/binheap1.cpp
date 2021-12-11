#include<iostream>
using namespace std;
class maxheap
{
    int n;
    int *ar;  
    public:
    maxheap()   //O(nlogn) for creation of heap
    {
        cout<<"\nEnter size:";
        cin>>n;
        ar=new int[n+1];
        int i;
        cout<<"\nEnter array:";
        for(i=1;i<=n;++i)
        {
            cin>>ar[i];
        }
        for(i=2;i<=n;++i)
        {
            insert(i);
        }
    }
    ~maxheap()
    {
        delete[] ar;
    }
    void insert(int j)  //O(logn)
    {
        int temp,k=j;
        temp=ar[j];
        while(k>1 && temp>ar[k/2])
        {
            ar[k]=ar[k/2];
            k/=2;
        }
        ar[k]=temp; 
    }


    void Delete_root(int s)
    {
        int x,i,j;
        x=ar[1];
        ar[1]=ar[s];
        i=1;
        j=2*i;
        while(j < s-1)
        {
            if(ar[j+1]>ar[j])
            {
                j=j+1;
            }
            if(ar[i]<ar[j])
            {
                swap(ar[i],ar[j]);
                i=j;
                j=2*j;
            }
            else
            {
                break;
            }
        }
        ar[s]=x;
    }
    void heapsort()
    {
        int i=n;
        for(;i>0;i--)
        {
            Delete_root(i);
        }
    }
    void display()
    {
        cout<<"\nArray:";
        for(int i=1;i<=n;++i)
        {
            cout<<ar[i]<<" ";
        }
    }
};
int main(void)
{
    maxheap b;
    cout<<"\nbinary heap:";
    b.display();
    b.heapsort();
    cout<<"\nAfter sorting";
    b.display();
}