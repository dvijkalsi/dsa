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
    void display();
    void search_list(int);
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
        node *p=NULL;
        node *q=start;
        while(q && x>q->data) 
        {
            p=q;
            q=q->next;
        }
        if(q==start)
        {
            newNode->next=start;
            start=newNode;
        }
        else 
        {
            newNode->next=q;
            p->next=newNode;
        }
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
void Linkedlist::display()
{
    cout<<"\nList:";
    node* t=start;
    while (t)
    {
        cout<<t->data<<" ";
        t=t->next;
    }
}
void Linkedlist::search_list(int key)
{
    node* temp=start;
    while (temp && key>=temp->data)
    {
        if(temp->data==key)
        {
            cout<<"\nKey "<<key<<" found";
            return;
        }
        temp=temp->next;
    }
    cout<<"\nKey "<<key<<" not found";
}
int hash_it(int x)
{
    return x%20;
}
Linkedlist* create_hash_table(int a[],int n)
{
    int i,j,d;
    Linkedlist *list;
    
    list=new Linkedlist[21];
    for(i=0;i<n;i++)
    {
        list[(hash_it(a[i]))].insertNode(a[i]);
    }
    for(i=0;i<21;i++)
    {
        list[i].display();
    }
    return list;
}
void search_hash(Linkedlist *list,int key)
{
    list[hash_it(key)].search_list(key);
}
int main()
{
    int a[]={11,1,13,44,3,2,67,43,99,0,19,18,17};
    int n=sizeof(a)/sizeof(a[0]);
    Linkedlist *l=create_hash_table(a,n);
    search_hash(l,9);
    // for(int i=0;i<n;++i)
    // {
    //     cout<<a[i]<<" ";
    // }
    // Linkedlist list;
    // list.insertNode(3);
    // list.insertNode(2);
    // list.insertNode(5);
    // list.display();
}