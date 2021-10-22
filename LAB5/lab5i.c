//length, sum and product of nodes using iterative and recursive function
//min and max of nodes using iterative function
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
    printf("Enter number of nodes");
    int n;
    scanf("%d",&n);
    printf("\nEnter a data of node 1:");
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
    int sum=0,pro=1,length=0;
    int min=first->data;
    int max=first->data;
    while(temp)
    {
        printf("%d ",temp->data);
        sum+=temp->data;
        pro*=temp->data;
        length++;
        if(temp->data>max)
        {
            max=temp->data;
        }
        if(temp->data<min)
        {
            min=temp->data;
        }
        temp=temp->next;
    }
    printf("\nSum:%d\nProduct:%d\nlength:%d\nmax:%d\nmin:%d",sum,pro,length,max,min);
    
    destroy();
    temp=NULL;
    first=NULL;
    last=NULL;
    return 0;
    
}


