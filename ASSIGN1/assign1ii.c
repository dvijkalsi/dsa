//2.WAP to remove duplicates from a single linked list of n nodes.
#include<stdlib.h>
#include<stdio.h>
typedef struct node NODE;
struct node
{
    int data;
    NODE *next;
};NODE *start;
void create(NODE **s,int d)
{
    if((*s)==NULL)
    {
        (*s)=(NODE*)malloc(sizeof (NODE));
        (*s)->next=NULL;
        (*s)->data=d;
    }
    else
    {
        NODE *new=(NODE*)malloc(sizeof (NODE));
        new->data=d;
        new->next=NULL;
        NODE *temp=(*s);
        while(temp->next)
        {
            temp=temp->next;
        }
        temp->next=new;
    }
}
void display(NODE **s)
{
    printf("\nLinked list:");
    NODE *temp=(*s);
    while(temp)
    {
        printf("%d ",temp->data);
        temp=temp->next;
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
void remove_duplicates(NODE **s)
{
    NODE *tempi=(*s);
    while(tempi)
    {
        NODE *tempj=tempi->next;
        NODE *tempj_prev=tempi;
        while(tempj)
        {
            if(tempi->data==tempj->data)
            {
                tempj_prev->next=tempj->next;
                NODE *victim=tempj;
                tempj=tempi->next;
                tempj_prev=tempi;
                free(victim);
            }
            else
            {
                tempj_prev=tempj;
                tempj=tempj->next;
            }
        }
        tempi=tempi->next;
    }
    
}

int main()
{
    int c=-999;
    while(c!=0)
    {
        printf("\n0.exit\n1.Enter an element\n2.display list\n3.Remove duplicates\nEnter your choice:");
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
                remove_duplicates(&start);
                
                printf("\nAfter removing duplicates:-");
                display(&start);
            default:
                printf("\nInvalid choice");
                break;
        }
    }
    destroy(&start);
    return 0;
}
