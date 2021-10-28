/*B.Write a menu driven program to implement Dequeue (both Input-restricted and Output-restricted) operations 
such as Enqueue, Dequeue, Peek, Display of elements, IsEmpty using linked list.*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node NODE;
struct node
{
    int data;
    NODE *next;
};NODE *start=NULL;
void enqueue_start(NODE **s,int d)
{
    if((*s)==NULL)
    {
        (*s)=(NODE*)malloc(sizeof(NODE));
        (*s)->next = NULL;
        (*s)->data=d;
    }
    else
    {
        NODE *new=(NODE*)malloc(sizeof(NODE));
        new->next=(*s);
        new->data=d;
        (*s)=new;
    }
}
void enqueue_end(NODE **s,int d)
{
    if((*s)==NULL)
    {
        (*s)=(NODE*)malloc(sizeof(NODE));
        (*s)->next = NULL;
        (*s)->data=d;
    }
    else
    {
        NODE *new=(NODE*)malloc(sizeof(NODE));
        new->next=NULL;
        new->data=d;
        NODE *temp=(*s);
        while (temp->next)
        {
            temp=temp->next;
        }
        temp->next=new;
        
    }
}
int dequeue_start(NODE **s)
{
    if((*s)==NULL)
    {
        printf("\nUnderflow");
        return -999;
    }
    NODE *temp=(*s);
    (*s)=(*s)->next;
    int x=temp->data;
    free(temp);
    return x;
}
int dequeue_end(NODE **s)
{
    if((*s)==NULL)
    {
        printf("\nUnderflow");
        return -998;
    }
    NODE *temp=(*s);
    while(temp->next->next)
    {
        temp=temp->next;
    }
    NODE *victim=temp->next;
    int x=victim->data;
    temp->next=NULL;
    free(victim);
    return x;
}
void display(NODE **s)
{
    NODE *temp=*s;
    if(temp==NULL)
    {
        printf("\nDeQueue empty");
        return;
    }
    printf("\nDequeue:");
    while(temp)
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
    while(temp)
    {
        NODE *victim=temp;
        temp=temp->next;
        free(victim);
    }
    printf("\nDequeue deleted");
}
void input_restrict()
{
    int c=-99;
    while(c)
    {
        printf("\n0.exit\n1.enter.queue\n2.display\n3.dequeue.start\n4.dequeue.end\nEnter choice:");
        scanf("%d",&c);
        switch(c)
        {
            case 0:
                break;
            case 1:
                printf("\nEnter a number:");
                int x;
                scanf("%d",&x);
                enqueue_start(&start,x);
                break;
            case 2:
                display(&start);
                break;
            case 3:
                printf("\nDequed@start:%d",dequeue_start(&start));
                display(&start);
                break;
            case 4:
                printf("\nDequed@end:%d",dequeue_end(&start));
                display(&start);
                break;
            default:
                printf("\nInvalid choice");
                break;
        }
    }
}
void output_restrict()
{
    int c=-99;
    while(c)
    {
        printf("\n0.exit\n1.enter.queue.start\n2.enter.queue.end\n3.display\n4.dequeue\nEnter choice:");
        scanf("%d",&c);
        switch(c)
        {
            case 0:
                break;
            case 1:
                printf("\nEnter a number:");
                int x;
                scanf("%d",&x);
                enqueue_start(&start,x);
                break;
            case 2:
                printf("\nEnter a number:");
                int y;
                scanf("%d",&y);
                enqueue_end(&start,y);
                break;
            case 3:
                display(&start);
                break;
            case 4:
                printf("\nDequed@end:%d",dequeue_end(&start));
                display(&start);
                break;
            default:
                printf("\nInvalid choice");
                break;
        }
    }
}
int main()
{
    int c=0;
    printf("\n1.input restricted dequeue\n2.output restricted dequeue\nEnter choice:");
    scanf("%d",&c);
    switch(c)
    {
        case 1:
            input_restrict();
            break;
        case 2:
            output_restrict();
            break;
        default:
            printf("\nInvelid choice");
    }
    /*enqueue_start(&start,1);
    enqueue_start(&start,2);
    enqueue_start(&start,3);
    enqueue_start(&start,4);
    enqueue_end(&start,99);
    enqueue_end(&start,98);
    enqueue_end(&start,97);
    enqueue_end(&start,96);
    display(&start);
    printf("\nDequed@start:%d",dequeue_start(&start));
    printf("\nDequed@start:%d",dequeue_start(&start));
    printf("\nDequed@end:%d",dequeue_end(&start));
    printf("\nDequed@end:%d",dequeue_end(&start));
    display(&start);*/
    destroy(&start);
}