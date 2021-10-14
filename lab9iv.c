/*A stack data structure is given with push and pop operations. WAP to implement a queue using instances 
of stack data structure and operations on them.*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node NODE;
struct node
{
    int data;
    NODE *next;
};NODE *start1,*start2;
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
    printf("\nStack deleted");
}
void enqueue(int d)
{
    push(&start1,d);
}
int dequeue()
{
    if(start2==NULL&&start1==NULL)
    {
        printf("\nEmpty queue");
        return -999;
    }
    else if(start2==NULL&&start1!=NULL)
    {
        while(start1)
        {
            push(&start2,pop(&start1));
        }
        return pop(&start2);
    }
    else if(start2!=NULL)
    {
        return pop(&start2);
    }
}
int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    printf("%d ",dequeue());
    printf("%d ",dequeue());
    enqueue(5);
    enqueue(6);
    printf("%d ",dequeue());
    printf("%d ",dequeue());
    printf("%d ",dequeue());
    printf("%d ",dequeue());
    destroy(&start1);
    destroy(&start2);
    return 0;
}