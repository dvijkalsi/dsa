#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node *next;
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
};
class Linkedlist
{
    public:
    node *start;
    
    Linkedlist()
    {
        start=NULL;
    }
    void insertNode(int);
    int deleteNode();
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
void binsort(int a[],int n)
{
    int max,i,j;
    Linkedlist *list;
    max=find_max(a,n);
    list=new Linkedlist[max+1];
    for(i=0;i<n;i++)
    {
        list[a[i]].insertNode(a[i]);
    }
    i=j=0;
    while(i<(max+1))
    {
        while(list[i].start)
        {
            a[j++]=list[i].deleteNode();
        }
        i++;
    }
}
int main()
{
    int a[]={1,1,1,4,3,2};
    int n=sizeof(a)/sizeof(a[0]);
    binsort(a,n);
    // Linkedlist list;
    // list.insertNode(100);
   // cout<<list.start->data;
    for(int i=0;i<n;++i)
    {
        cout<<a[i]<<" ";
    }
}