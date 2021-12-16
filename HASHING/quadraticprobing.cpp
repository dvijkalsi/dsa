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
    while(h[(index+(i*i))%SIZE]!=0)
        i++;
    return (index+(i*i))%SIZE;
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
    while(h[(index+(i*i))%SIZE]!=key)
        i++;
    return (index+(i*i))%SIZE;
}
int main()
{
    int ht[10]={0};
    insert(ht,23);
    insert(ht,43);
    insert(ht,13);
    insert(ht,27);
    cout<<"\nKey found at:"<<search(ht,13);
    return 0;
}