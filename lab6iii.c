//WAP to represent a sparse matrix using linked list.WAP to find out the transpose of a sparse matrix.
//WAP to multiply two sparse matrices.
#include<stdlib.h>
#include<stdio.h>
typedef struct node NODE;
struct node
{
    int row;
    int col;
    int val;
    NODE *next;
};NODE *start;

void new_node()
{
    if(start==NULL)
    {
        start=(NODE*)malloc(sizeof(NODE));
        printf("\nEnter number of rows, columns and non-zero elements:");
        scanf("%d %d %d",&(start->row), &(start->col), &(start->val));
        start->next=NULL;
    }
    else
    {
        NODE *new=(NODE*)malloc(sizeof(NODE));
        printf("\nEnter row, column and non-zero element:");
        scanf("%d %d %d",&(new->row), &(new->col), &(new->val));
        NODE *last=start;
        while(last->next!=NULL)
        {
            last=last->next;
        }
        new->next=NULL;
        last->next=new;
        last=new;
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
    while(temp!=NULL)
    {
        NODE *victim=temp;
        temp=temp->next;
        free(victim);
    }
    
    printf("\nList deleted");
}

void display()
{
    NODE *temp=start;
     if(start==NULL)
    {
        printf("\nEmpty list");
        return;
    }
    printf("\nNumber of row:%d\nNumber of columns:%d\nNumber of non-zero elements:%d",temp->row,temp->col,temp->val);
    temp=temp->next;
    while(temp!=NULL)
    {
        printf("\nr:%d\tc:%d\telement:%d",temp->row,temp->col,temp->val);
        temp=temp->next;
    }
}
void transpose()
{
    NODE *temp=start->next;
    while (temp)
    {
        int t=temp->row;
        temp->row=temp->col;
        temp->col=t;
        temp=temp->next;
    }
    
    
}
int main()
{
    printf("\nEnter number of non zero elements:");
    int n;
    scanf("%d",&n);
    for(int i=0;i<=n;++i)
    {
        new_node();
    }
    display();
    transpose();
    printf("\nAfter transpose");
    display();
    destroy();
} 