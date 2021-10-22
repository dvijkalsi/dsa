//WAP to create an SLL and delete at a given postion using menu driven program

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

    printf("\nDelete a node at\n1.start; or\n2.End; or\n3.Middle\nEnter a choice:");
    int c;
    scanf("%d",&c);
    struct node* temp2;
    switch (c)
    {
    case 1:
            temp=first;
            first=first->next;
            printf("\nData of node deleted:%d",temp->data);
            free(temp);
            temp=NULL;


        break;
    case 2:
            temp=first;
            
            temp2=first;

            while(temp2->next)
            {
                temp=temp2;
                temp2=temp2->next;
            }
            temp->next=NULL;
            
            printf("\nData of deleted node:%d",temp2->data);
            free(temp2);
            temp2=NULL;
            
        
        break;
    case 3:
        temp=first;

        temp2=first;

        printf("Enter the position to be deleted:");

        int pos;
        scanf("%d",&pos);
        if(pos>=n)
        {
            printf("Invalid position");
            break;
        }
        for(int i=1;i<pos;++i)
        {
            temp=temp2;
            temp2=temp2->next;
            if(temp2 == NULL)
                break;
        }
        printf("\nData of deleted node:%d",temp2->data);


        temp->next=temp2->next;
        temp2->next=NULL;
        free(temp2);
        temp2=NULL;


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