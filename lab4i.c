//WAP to create SLL and to display the values of each node(atleast 5) using user defined create and display
//function
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node *first;
void destroy()
{
    if (!first) return;

    struct node *ds = first;
    while (ds != NULL)
    {
        struct node *victim = ds;
        ds = ds->next;
        free (victim);
    }
}
int main()
{
    first=(struct node*)malloc(sizeof(struct node));
    first->next=NULL;
    printf("\nEnter a data of node 1:");
    int d;
    scanf("%d",&d);
    first->data=d;
    struct node* last;
    last=first;
    for(int i=1;i<5;i++)
    {
        printf("\nEnter data of node%d:",i+1);
        int da;
        scanf("%d",&da);
        struct node* new;
        new=(struct node*)malloc(sizeof(struct node));
        new->data=da;
        new->next=NULL;
        last->next=new;
        last=last->next;

    }
    printf("\nEntered list:");
    struct node *temp;
    temp=first;
    while(temp)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    
    destroy();
    temp=NULL;
    first=NULL;
    last=NULL;
    return 0;
    
}