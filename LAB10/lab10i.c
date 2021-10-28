/*Wap to create circular queue using linked list with following operation.
1. insert at Begining.
2. insert at End.
3. insert at Position.
4. delete at Begining.
5. delete at End.
6. delete at Position.
7. traverse the List*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node NODE;
struct node
{
    int data;
    NODE* next;
};NODE *start=NULL;
void enqueue_end(NODE **s,int d)
{
    if((*s)==NULL)
    {
        (*s)=(NODE*)malloc(sizeof(NODE));
        (*s)->data=d;
        (*s)->next=(*s);
    }
    else
    {
        NODE *temp=*s;
        NODE *new=(NODE*)malloc(sizeof(NODE));
        new->next=(*s);
        new->data=d;
        while(temp->next!=(*s))
        {
            temp=temp->next;
        }
        temp->next=new;
        temp=new;
        
    }
}
void enqueue_start(NODE **s,int d)
{
    if((*s)==NULL)
    {
        (*s)=(NODE*)malloc(sizeof(NODE));
        (*s)->data=d;
        (*s)->next=(*s);
    }
    else
    {
        NODE *temp=*s;
        NODE *new=(NODE*)malloc(sizeof(NODE));
        new->next=(*s);
        new->data=d;
        while(temp->next!=(*s))
        {
            temp=temp->next;
        }
        temp->next=new;
        temp=new;
        (*s)=new;
    }
}
void enqueue_pos(NODE **s,int pos,int d)
{
    if((*s)==NULL)
    {
        (*s)=(NODE*)malloc(sizeof(NODE));
        (*s)->data=d;
        (*s)->next=(*s);
    }
    else
    {
        NODE *temp=(*s);
        for(int i=1;i<pos-1;++i)
        {
            temp=temp->next;
        }
        NODE *new =(NODE*)malloc(sizeof(NODE));
        new->data=d;
        new->next=temp->next;
        temp->next=new;
    }
}
int dequeue_start(NODE **s)
{
    if((*s)==NULL)
    {
        printf("\nCirqueue empty");
        return -997;
    }
    NODE *last=(*s);
    while(last->next!=(*s))
    {
        last=last->next;
    }
    NODE *temp=(*s);
    int x=temp->data;
    (*s)=(*s)->next;
    last->next=(*s);
    free(temp);
    return x;
}
int dequeue_end(NODE **s)
{
    if((*s)==NULL)
    {
        printf("\nCirqueue empty");
        return -998;
    }
    NODE *last=(*s);
    while(last->next->next!=(*s))
    {
        last=last->next;
    }
    NODE *temp=last->next;
    int x=temp->data;
    last->next=(*s);
    free(temp);
    return x;
}
int dequeue_pos(NODE **s,int pos)
{
    if((*s)==NULL)
    {
        printf("\nCirqueue empty");
        return -999;
    }
    NODE *temp=(*s);
    for(int i=1;i<pos-1;++i)
    {
        temp=temp->next;
    }
    int x=temp->next->data;
    NODE *victim=temp->next;
    temp->next=temp->next->next;
    free(victim);
    return x;
}
void display(NODE **s)
{
    if((*s)==NULL)
    {
        printf("\nCirqueue empty");
        return;
    }
    NODE *temp=(*s);
    printf("\nCirqueue:");
    if((*s)!=NULL)
    {
        do
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }while(temp!=start);
    }
    else
    {
        printf("\nCirque Empty");
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
     do
    {
        NODE *victim=temp;
        temp=temp->next;
        free(victim);
    }while(temp!=(*s));
    printf("\nCirqueue deleted");
}
int main()
{
    enqueue_start(&start,1);
    enqueue_start(&start,2);
    enqueue_start(&start,3);
    enqueue_start(&start,4);
    enqueue_end(&start,100);
    enqueue_pos(&start,2,33);
    display(&start);
    printf("\nDequeued@start:%d",dequeue_start(&start));
    display(&start);
    printf("\nDequeued@end:%d",dequeue_end(&start));
    display(&start);
    printf("\nDequeued@pos%d:%d",3,dequeue_pos(&start,3));
    display(&start);
    destroy(&start);
}