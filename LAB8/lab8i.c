//WAP to reverse a stack using extra stack.
#include <stdio.h>
#include <stdlib.h>
typedef struct node NODE;
typedef struct node NODE;
struct node
{
    char data;
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
    for(int i=1;i<=n;++i)
    {
        push(&start2,pop(&start1));
    }
    printf("\nReverse stack:");
    display(&start2);
    destroy(&start2);
    return 0;

}