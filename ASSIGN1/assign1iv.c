/*4.Given a double linked list, rotate the linked list counter-clockwise by k nodes. Where k is a given 
positive integer. For example, if the given linked list is 10->20->30->40->50->60 and k is 4, the list 
should be modified to 50->60->10->20->30->40. Assume that k is smaller than the count of nodes in linked list.*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node NODE;
struct node 
{
    NODE *prev;
    int data;
    NODE *next;
};NODE *start=NULL;
void create(NODE **s, int d)
{
    if((*s)==NULL)
    {
        (*s)=(NODE*)malloc(sizeof(NODE));
        (*s)->prev=NULL;
        (*s)->next=NULL;
        (*s)->data=d;
    }
    else 
    {
        NODE *new=(NODE*)malloc(sizeof(NODE));
        new->next=NULL;
        new->prev=NULL;
        NODE *temp=(*s);
        new->data=d;
        while (temp->next)
        {
            temp=temp->next;
        }
        temp->next=new;
        new->prev=temp;
    }
}
void display(NODE **s)
{
    if((*s))
    {
    printf("\nLinked list:");
    NODE *temp=(*s);
    while(temp)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    }
    else 
    {
        printf("\nunderflow");
    }
}
void destroy(NODE **s)
{
    if((*s)==NULL)
    {
        printf("\nList empty");
        return;
    }
    else 
    {
        NODE *temp=*s;
        while(temp)
        {
            NODE *victim=temp;
            temp=temp->next;
            free(victim);
        }
        printf("\nLinked list deleted");
    }
}
void rotate(NODE **s,int k)
{
    NODE *temp=(*s);
    NODE *last=(*s);
    while(last->next)
    {
        last=last->next;
    }
    for(int i=0;i<k-1;++i)
    {
        temp=temp->next;
    }
    (*s)->prev=last;
    last->next=(*s);
    (*s)=temp->next;
    temp->next->prev=NULL;
    temp->next=NULL;
}
int main()
{

    int c=-999;
    while(c!=0)
    {
        printf("\n0.exit\n1.Enter an element\n2.display list\n3.rotate by k\nEnter your choice:");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                printf("\nEnter a number:");
                int d;
                scanf("%d",&d);
                create(&start,d);
                break;
            case 2:
                display(&start);
                break;
            case 0:
                break;
            case 3:
                printf("\nEnter k:");
                int k;
                scanf("%d",&k);
                printf("\nAFTER:");
                rotate(&start,k);
                display(&start);
                break;
            default:
                printf("\nInvalid choice");
                break;
        }
    }

    return 0;
}