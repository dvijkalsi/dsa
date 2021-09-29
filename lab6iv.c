/*Write a menu driven program to perform the following operations in a single circular linked list by using
 suitable user defined functions for each case.
a) Traverse the list 
b) Check if the list is empty 
c) Insert a node at the certain position
d) Delete a node at the certain position 
e) Delete a node for the given key
f) Count the total number of nodes 
g) Search for an element in the linked list*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node NODE;
struct node
{
    int data;
    NODE *next;
};NODE *start;

void new_node(int d)
{
    if(start==NULL)
    {
        NODE *new=(NODE*)malloc(sizeof(NODE));
        new->data=d;
        new->next=new;
        start=new;
    }
    else
    {

        NODE *new=(NODE*)malloc(sizeof(NODE));
        new->data=d;
        new->next=start;
        NODE *temp=start;
        while (temp->next!=start)
        {
            temp=temp->next;
        }
        temp->next=new;

    }
}
void display()
{
    NODE* temp=start;
    int count=1;
    printf("\nList:");
    while(temp->next!=start)
    {
        printf("%d ",temp->data);
        temp=temp->next;++count;
    }
    printf("%d ",temp->data);
    printf("\nNo. of node:%d",count);
}
void destroy()
{
    NODE *temp=start->next;
        if(start==NULL)
    {
        printf("\nEmpty list");
        return;
    }
    while(temp->next!=start)
    {
        NODE *victim=temp;
        temp=temp->next;
        free(victim);
    }
    free(temp->next);
    printf("\nList deleted");
}
void is_empty()
{
    if(!start)
    printf("\nEmpty List");
}
void add_at_pos(int pos,int d)
{
    
    NODE *temp1=start;
    NODE *temp2=start;
    NODE *new=(NODE*)malloc(sizeof(NODE));
        new->data=d;
        new->next=NULL;
        NODE *last;
        last=start;int c=1;
        while (last->next!=start)
        {
            last=last->next;++c;
        }
    if(pos==1)
    {
        last->next=new;
        new->next=start;
        start=new;
    }
    else if(pos==c)
    {
        new->next=start;
        last->next=new;
    }
    else 
    {
        for(int i=1;i<pos;++i)
        {
            temp1=temp2;
            temp2=temp2->next;
        }
        new->next=temp2;
        temp1->next=new;
    }
}
void delete_at_pos(int pos)
{   
    NODE *temp1=start;
    NODE *temp2=start;
        NODE *last;
        last=start;int c=1;
        while (last->next!=start)
        {
            last=last->next;++c;
        }
    if(pos==1)
    {
        start=start->next;
        free(last->next);
        last->next=start;
    }
    else if(pos==c)
    {
        NODE *prev=start;
        while(prev->next!=last)
        {
            prev=prev->next;
        }
        prev->next=start;
        free(last);
    }
    else 
    {
        for(int i=1;i<pos;++i)
        {
            temp1=temp2;
            temp2=temp2->next;
        }
        temp1->next=temp2->next;
        free(temp2);
    }
}
void delete_for_key(int key)
{
    NODE *last,*temp=start;
        last=start;int c=1;int keypos=-1;
        while (last->next!=start)
        {
            if(last->data==key)
            {
                keypos=c;
            }
            last=last->next;++c;
        }
        if(keypos!=-1)
        {
            delete_at_pos(keypos);
        }
        else
        {
            printf("\nkey not found");
        }
}
void search(int n)
{
    NODE *temp=start;
    while(temp->next!=start)
    {
        if(temp->data==n)
        {
            printf("\nElement found");return;
        }
       temp=temp->next;
    }
    if(temp->data==n)
    {
        printf("\nElement found");return;
    }
    printf("\nNot found");return;
}
int main()
{

    is_empty();
    new_node(1);
    new_node(2);
    new_node(3);
    new_node(4);
    display();
    printf("\nAfter adding at any postion");
    add_at_pos(4,100);
    display();
    printf("\nAfter deletion at any position");
    delete_at_pos(5);
    display();
    printf("\nDeletion using key");
    delete_for_key(1);
    display();
    search(100);
    search(3);
    destroy();
    return 0;
}