//WAP using a function to reverse a queue by using stack.
#include<stdio.h>
#include<stdlib.h>
typedef struct node NODE;
struct node
{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL,*stacktop=NULL;
void enqueue(int x)
{
    struct node *temp;
    temp= (struct node *) malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("No memory");
    }
    else
    {
        temp->data=x;
        temp->next=NULL;
        if(front==NULL)
        {
            front=rear=temp;
        }
        else
        {
            rear->next=temp;
            rear=temp;
        }
    }
}

int dequeue()
{
    int x=-1;
    struct node *temp;
    if(front==NULL && rear==NULL)
    {
        printf("Underflow / Queue is empty");
    }
    else
    {
        temp=front;
        x=front->data;
        front=front->next;
        free(temp);
    }
    return x;
}

void display()
{
    struct node *temp=front;
    if(front==NULL && rear==NULL)
    {
        printf("Underflow / Queue is empty");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d <- ",temp->data);
            temp=temp->next;
        }
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
void peek()
{
    printf("%d",front->data);
}
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
void reverse()
{
    
    if(front==NULL && rear==NULL)
    {
        printf("\nUnderflow / Queue is empty");
    }
    else
    {
        while(front!=NULL)
        {
            push(&stacktop, dequeue());
        }
    }

    if(stacktop==NULL)
    {
        printf("\nUnderflow in stack");
    }
    else
    {
        while(stacktop!=NULL)
        {
            enqueue(pop(&stacktop));
        }
    }
    printf("\nReversed queue:-\n");
    display();
}
void destroy()
{
    struct node *temp=front;
    if(front==NULL)
    {
        printf("\nEmpty list");
        return;
    }
     while(temp!=NULL)
    {
        struct node *victim=temp;
        temp=temp->next;
        free(victim);
    }
    printf("\nQueue deleted");
}

int main()
{
    int c=-999;
    while(c!=0)
    {
        printf("\n0.Exit\n1.Enqueue\n2.Peek\n3.Dequeue\n4.display\n5.reverse");
        printf("\nEnter your choice:");
        scanf("%d",&c);
        switch(c)
        {
            case 0:
                break;
            case 1:
                printf("\nEnter a number:");
                int x;
                scanf("%d",&x);
                enqueue(x);
                break;
            case 2:
                peek();
                break;
            case 3:
                printf("\nDequeued:%d",dequeue());
                break;
            case 4:
                display();
                break;
            case 5:
                reverse();
                break;
            default:
                printf("\nInvalid choice");
                break;

        }
    }  
    destroy();
    return 0;
}