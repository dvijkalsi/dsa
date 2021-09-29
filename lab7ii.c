//Write a menu driven program to perform the above operations of a stack using linked list by using suitable 
//user defined functions for each case.a) Check if the stack is empty b) Display the contents of stack
// c) Push d) Pop

#include <stdio.h>
#include<stdlib.h>
typedef struct node NODE;
struct node
{
    int data;
    NODE *next;
};NODE *start;

void push(int d)
{
    if(start==NULL)
    {
        start=(NODE*)malloc(sizeof (NODE));
        start->data=d;
        start->next=NULL;
    }
    else
    {
        NODE *new=(NODE*)malloc(sizeof (NODE));
        new->next=start;
        new->data=d;
        start=new;
    }
}
void pop()
{
    if(start==NULL)
    {
        printf("\nStack underflow");return ;
    }
    printf("\npopped data:%d",start->data);
    NODE *temp=start;
    start=start->next;
    free(temp);
}
void is_empty()
{
    if(start==NULL)
    {
        printf("Stack empty");
        
    }
    else 
    {
        printf("\nNot empty");
        
    }
}
void display()
{
    if(start==NULL)
    {
        printf("\nEmpty stack");
        return ;
    }
    printf("\nStack:");
    NODE *temp=start;
    while (temp)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    
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
    printf("\n1.push\n2.pop\n3.display\n4.is_empty\n5.exit");
    printf("\nEnter your choice:");
    int n;
    scanf("%d",&n);
    while(n!=5)
    {
        switch(n)
        {
            case 1:
                
                printf("\nEnter value to be pushed:");int d;
                scanf("%d",&d);
                push(d);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                is_empty();
                break;
                case 5:
                    break;
                default:
                    printf("\nInvalid choice");
                    break;    
        }
    printf("\n1.push\n2.pop\n3.display\n4.is_empty\n5.exit");
    printf("\nEnter your choice:");
    
    scanf("%d",&n);
    }
    destroy();
    return 0;
}