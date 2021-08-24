//WAP to create SLL and to display the values of each node(atleast 5) using user defined create and display
//function and insert node at beginning, in the middle and at the end.
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};
struct node *first =NULL;
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
    int n;
    printf("\nEnter number of nodes:");
    scanf("%d",&n);
    first=(struct node*)malloc(sizeof(struct node));
    first->next=NULL;
    printf("\nEnter data of node 1:");
    int d;
    scanf("%d",&d);
    first->data=d;
    struct node* last;
    last=first;
    for(int i=1;i<n;i++)
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

    printf("\nInsert a node at\n1.start; or\n2.End; or\n3.Middle\nEnter a choice:");
    int c;
    scanf("%d",&c);
        struct node *x;
        x=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter data:");
        scanf("%d",&x->data);
        x->next=NULL;
    switch (c)
    {
    case 1:
        

        x->next=first;
        first=x;
        break;
    case 2:

        last->next=x;
        last=last->next;
        break;
    case 3:
        temp=first;

        printf("Enter the postition after which new node to be inserted:");

        int pos;
        scanf("%d",&pos);
        if(pos>=n)
        {
            printf("Invalid position");
            break;
        }
        for(int i=1;i<pos-1;++i)
        {
            temp=temp->next;
        }
        x->next=temp->next;
        temp->next=x;
        break;
    
    default:
        printf("\nInvalid choice");
        break;
    }
        printf("\nNew list:");
    
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