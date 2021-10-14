//Write a menu driven program to implement queue operations such as Enqueue, Dequeue, Peek, Display of 
//elements, IsEmpty using linked list.
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;
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

void peek()
{
    printf("%d",front->data);
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
        printf("\n0.Exit\n1.Enqueue\n2.Peek\n3.Dequeue\n4.display");
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
            default:
                printf("\nInvalid choice");
                break;

        }
    }
    destroy();
    return 0;
}