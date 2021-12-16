#include<iostream>
using namespace std;
#define SIZE 10
int Hash(int x)
{
    return x%SIZE;
}
int probe(int h[],int key)
{
    int index=Hash(key);
    int i=0;
    while(h[(index+i)%SIZE]!=0)
        i++;
    return (index+i)%SIZE;
}
void insert(int h[], int key)
{
    int index=Hash(key);
    if(h[index]!=0)
    {
        index=probe(h,key);
    }
    h[index]=key;
}
int search(int h[],int key)
{
    int index=Hash(key);
    int i=0;
    while(h[(index+i)%SIZE]!=key)
        i++;
    return (index+i)%SIZE;
}
int main()
{
    int ht[10]={0};
    insert(ht,12);
    insert(ht,25);
    insert(ht,35);
    insert(ht,26);
    cout<<"\nKey found at:"<<search(ht,26);
    return 0;
}