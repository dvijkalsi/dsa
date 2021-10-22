/*3.Given a linked list, write a function to reverse every k nodes. (where k is an input to the function).
 If a linked list is given as 12->23->45->89->15->67->28->98->NULL and k=3 then output will be 
 45->23->12->67->15->89->98->28->NULL.*/
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
NODE* reverse_list(NODE *s)
{
    NODE *currptr=(s);
    NODE *prevptr=NULL,*nextptr=NULL;
    while(currptr)
    {
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
    }
    currptr=prevptr;
    return currptr;
}
NODE* reversek(NODE* head,int k)
{
    NODE *prevptr=NULL;
    NODE *currptr=head;
    NODE *nextptr;
    int count=0;
    while(currptr && count<k)
    {
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        count++;
    }
    if(nextptr!=NULL)
    {
        head->next=reversek(nextptr,k);
    }
    return prevptr;

}
int main()
{
    int c=-999;
    while(c!=0)
    {
        printf("\n0.exit\n1.Enter an element\n2.display list\n3.rev every k nodes\n4.reverse full list\nEnter your choice:");
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
                start=reversek(start,k);
                display(&start);
                break;
            case 4:
                start=reverse_list(start);
                display(&start);
                break;
            default:
                printf("\nInvalid choice");
                break;
        }
    }

    

    destroy(&start);
    return 0;
}