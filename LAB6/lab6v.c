/*WAP to create a double circular double linked list of n nodes and display the linked list by using suitable
 user defined functions for create and display operations.*/

#include<stdlib.h>
#include<stdio.h>
typedef struct node NODE;
struct node 
{
    NODE *prev;
    int data;
    NODE *next;
};NODE *start;

void new_node(int d)
{
    if(start==NULL)
    {
        start=(NODE*)malloc(sizeof(NODE));
        start->next=start;
        start->prev=start;
        start->data=d;
    }
    else
    {
        NODE *new=(NODE*)malloc(sizeof(NODE));
        new->prev=start->prev;
        new->next=start;
        new->data=d;
        start->prev->next=new;
        start->prev=new;
    }
}

void display()
{
    NODE *temp=start;
    if(start==NULL)
    {
        printf("Empty");
        return;
    }
    printf("\nList:");
    while(temp->next!=start)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d ",temp->data);
}

void destroy()
{
    NODE *temp=start;
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
int main()
{
    int n;
    printf("\nEnter number of node:");
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        int x;
        printf("\nEnter data:");
        scanf("%d",&x);
        new_node(x);
    }
    display();
    destroy();
    return 0;
}