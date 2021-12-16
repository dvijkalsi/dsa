#include<iostream>
using namespace std;
#define SIZE 10
int Hash1(int x)
{
    return x%SIZE;
}
int Hash2(int x)
{
    return (7-(x%7));
}
int probe(int h[],int key)
{
    int index=Hash1(key);
    int i=0;
    while(h[(index+i*Hash2(key))%SIZE]!=0)
        i++;
    return (index+i*Hash2(key))%SIZE;
}
void insert(int h[], int key)
{
    int index=Hash1(key);
    if(h[index]!=0)
    {
        index=probe(h,key);
    }
    h[index]=key;
}
int search(int h[],int key)
{
    int index=Hash1(key);
    int i=0;
    while(h[(index+i*Hash2(key))%SIZE]!=key)
        i++;
    return (index+i*Hash2(key))%SIZE;
}
int main()
{
    int ht[10]={0};
    insert(ht,5);
    insert(ht,25);
    insert(ht,15);
    insert(ht,35);
    insert(ht,95);
    cout<<"\nKey found at:"<<search(ht,95);
    return 0;
}