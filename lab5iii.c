//length, sum and product of nodes using iterative and recursive function
//min and max of nodes using recursive function
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
int sum(NODE *s)
{
    if(s)
    {
        return (s->data)+sum(s->next);
    }
}
int pro(NODE *s)
{
    if(s)
    {
        return (s->data)*pro(s->next);
    }
    else
    {
        return 1;
    }
}
int len(NODE *s)
{
    if(s)
    {
        return 1+len(s->next);
    }
}
int max(NODE *s, int m)
{
    if(s==NULL)
    {
        return m;
    }
    else
    {
        if(s->data>m)
        {
            m=s->data;

        }
        return max(s->next,m);
    }
}
int min(NODE *s, int m)
{
    if(s==NULL)
    {
        return m;
    }
    else
    {
        if(s->data<m)
        {
            m=s->data;

        }
        return min(s->next,m);
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
int main (void)
{
    int n;
    printf ("\nEnter the no of nodes: ");
    scanf ("%d",&n);
    create (n);
    NODE *s=start; 
    display(s);
    printf("\nSum:%d",sum(s));
    printf("\nProduct:%d",pro(s));
    printf("\nLength:%d",len(s));
    printf("\nMax:%d",max(s,s->data));
    printf("\nmin:%d",min(s,s->data));
    destroy();
    return 0;
}