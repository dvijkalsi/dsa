#include<iostream>
using namespace std;
class Linkedlist;
class node
{
    
    int data;
    node *next;
    public:
    node()
    {
        data=0;
        next=NULL;
    }
    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
    friend class Linkedlist;
};
class Linkedlist
{
    
    node *start;
    public:
    Linkedlist()
    {
        start=NULL;
    }
    void insertNode(int);
    int deleteNode();
    int isempty()
    {
        if(!start)
        return 1;
        else 
        return 0;
    }
};
void Linkedlist::insertNode(int x)
{
    node *newNode=new node(x);
    if(!start)
    {
        start=newNode;
        return;
    }
    else
    {
        node *temp=start;
        while(temp->next) 
        {
            temp=temp->next;
        }

        temp->next=newNode;
    }

}
int Linkedlist::deleteNode()
{
    node *t=start;
    int x=t->data;
    start=start->next;
    free(t);
    return x;
}
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
void radixsort(int a[],int n)
{
    int max,i,j,d;
    Linkedlist *list;
    max=find_max(a,n);
    list=new Linkedlist[10];
    d=1;
    while((max/d)!=0)
    {
        for(i=0;i<n;i++)
        {
            list[(a[i]/d)%10].insertNode(a[i]);
        }
        i=j=0;
        while(i<10)
        {
            while(!(list[i].isempty()))
            {
                a[j++]=list[i].deleteNode();
            }
            i++;
        }
        d*=10;
    }
}
int main()
{
    int a[]={111,1,1213,44343,3232123,2};
    int n=sizeof(a)/sizeof(a[0]);
    radixsort(a,n);
    for(int i=0;i<n;++i)
    {
        cout<<a[i]<<" ";
    }
}