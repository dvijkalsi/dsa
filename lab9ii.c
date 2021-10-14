//Write a menu driven program to implement queue operations such as Enqueue, Dequeue, Peek, Delete from any 
//postion,Display of 
//elements, IsEmpty, IsFull using static array.
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if(rear==MAX-1) //queue is full
    {
        printf("Overflow because queue is full");
    }
    else if(front==-1 && rear==-1) //queue is empty
    {
        front=rear=0;
        queue[rear]=x;
    }
    else
    {
        rear++;
        queue[rear]=x;
    }
}

void dequeue()
{
    if(front==-1 && rear==-1) //queue is empty
    {
        printf("Underflow");
    }
    else if(front==rear) //single element present
    {   
        printf("\n%d ",queue[front]);
        front=rear=-1;
    }
    else
    {
        printf("\n%d ",queue[front]);
        front++;
    }
}

void display()
{   
    int i;
    for(i=front;i<=rear;++i)
    {
        printf("%d <- ",queue[i]);
    }
}

void peek()
{
    printf("\n%d ",queue[front]);
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
                dequeue();
                break;
            case 4:
                display();
                break;
            default:
                printf("\nInvalid choice");
                break;

        }
    }
    return 0;
}