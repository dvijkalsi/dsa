/*3.WAP to implement a stack which will support three additional operations in addition to push and pop.Those are  
a) peekLowestElement - return the lowest element in the stack without removing it from the stack
b) peekHighestElement - return the highest element in the stack without removing it from the stack
c) peekMiddleElement - return the (size/2+1)th lowest element in the stack without removing it from the stack.*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node NODE;
typedef struct node NODE;
struct node
{
    int data;
    NODE *next;
};NODE *start1;
void push(NODE **s,int d)
{
    if((*s)==NULL)
    {
        (*s)=(NODE*)malloc(sizeof (NODE));
        (*s)->data=d;
        (*s)->next=NULL;
    }
    else
    {
        NODE *new=(NODE*)malloc(sizeof (NODE));
        new->next=(*s);
        new->data=d;
        (*s)=new;
    }
}
int pop(NODE **s)
{
    if((*s)==NULL)
    {
        printf("\nStack underflow");return -999 ;
    }
    int t=(*s)->data;
    NODE *temp=(*s);
    (*s)=(*s)->next;
    free(temp);
    return t;
}
void display(NODE **s)
{
    if((*s)==NULL)
    {
        printf("\nEmpty stack");
        return ;
    }
    NODE *temp=(*s);
    while (temp)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    
}
void destroy(NODE **s)
{
    NODE *temp=(*s);
    if((*s)==NULL)
    {
        printf("\nEmpty list");
        return;
    }
     while(temp!=NULL)
    {
        NODE *victim=temp;
        temp=temp->next;
        free(victim);
    }
    printf("\nList deleted");
}
int peek_lowest(NODE **s)
{
    NODE *temp=*s;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    return temp->data;
}
int peek_highest(NODE **s)
{
    NODE *temp=*s;
    return temp->data;
}
int peek_middle(NODE **s)
{
    NODE *temp=*s;
    int count=0;
    while(temp)
    {
        count++;
        temp=temp->next;
    }
    temp=*s;
    for(int i=1;i<=(count/2);i++)
    {
        temp=temp->next;
    }
    return temp->data;
}
int main()
{
    printf("\nEnter number of elements:");
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        printf("\nEnter a number:");
        int d;
        scanf("%d",&d);
        push(&start1,d);
    }
    printf("\nStack entered:");
    display(&start1);
    printf("\nPeek_lowest:%d",peek_lowest(&start1));
    printf("\nPeek_highest:%d",peek_highest(&start1));
    printf("\nPeek_middle:%d",peek_middle(&start1));
    destroy(&start1);
    return 0;
}