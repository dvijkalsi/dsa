//WAP to create SLL and to display the values of each node(atleast 5) using user defined create and display
//recursive function
#include <stdio.h>
#include <stdlib.h>   

typedef struct node NODE;

struct node {
    int data;
    struct node *next;
} *start=NULL,*ptr;

void display(NODE *s);
void create (int);
void destroy();

int main (void)
{
    int n;
    printf ("\nEnter the no of nodes: ");
    scanf ("%d",&n);
    create (n);
    NODE *s=start; 
    display(s);
    destroy();
    return 0;
}

void create (int x) 
{

    if (x == 0) return;

    NODE *node;
        node = (NODE*)malloc (sizeof(NODE));

    

    printf ("Enter the data: ");
    scanf ("%d",&node->data);

    node->next = NULL;
    if (start == NULL)
    {
        ptr = start = node;
    }
    else
    {
        ptr->next = node;
        ptr = ptr->next;
    }   

    create (x-1);
}

void display(NODE *s)
{
    if(s!=NULL)
    {
        printf("%d ",s->data);
        display(s->next);
    }
}

void destroy()
{
    if (!start) return;

    NODE *ds = start;
    while (ds != NULL)
    {
        NODE *victim = ds;
        ds = ds->next;
        free (victim);
    }
}