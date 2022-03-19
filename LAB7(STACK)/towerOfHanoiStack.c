#include <stdio.h>
#include <stdlib.h>
typedef struct node NODE;
struct node
{
    int data;
    NODE *next;
};NODE *start1,*start2,*start3;
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
void display(NODE **s)
{
    if((*s)==NULL)
    {
        printf("Empty stack");
        return ;
    }
    
    NODE *temp=(*s);
    while (temp)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    
}
void toh(int n,NODE **a,NODE **b,NODE **c)
{
    if(n>0)
    {
        toh(n-1,a,c,b);
        push(c,pop(a));
        toh(n-1,b,a,c);
    }
}
int main()
{
     push(&start1,4);
     push(&start1,3);
     push(&start1,2);
     push(&start1,1);
     printf("\nBefore");
     printf("\ntower1:");
     display(&start1);
     printf("\ntower2:");
     display(&start2);
     printf("\ntower3:");
     display(&start3);
     toh(4,&start1,&start2,&start3);
     printf("\nAfter");
     printf("\ntower1:");
     display(&start1);
     printf("\ntower2:");
     display(&start2);
     printf("\ntower3:");
     display(&start3);
     destroy(&start3);
    return 0;
}