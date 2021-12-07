//WAP demonstrating bubble sort using linked list.
#include<stdio.h>
#include<stdlib.h>
typedef struct node NODE;
struct node
{
    int data;
    NODE *next;
};NODE *start=NULL;

void insert(NODE **p,int key)
{
    NODE *new=(NODE*)malloc(sizeof(NODE));
    new->data=key;
    new->next=NULL;
    if(!(*p))
    {
        *p=new;
    }
    else
    {
        NODE *t=*p;
        while(t->next) t=t->next;
        t->next=new;
    }
}
void destroy(NODE *p)
{
    if (!p)
    {
        printf("\nList empty"); 
        return;
    }
    struct node *ds = p;
    while (ds != NULL)
    {
        struct node *victim = ds;
        ds = ds->next;
        free (victim);
    }
    printf("\nlist deleted");
}
void display(NODE *p)
{
    if(!p)
    {
        printf("\nUnderflow");
        return;
    }
    NODE *t=p;
    printf("\nList:");
    while(t) 
    {
        printf("%d ",t->data);
        t=t->next;
    }
}
void bubble_sort_list(NODE *p)
{
    int n=0;
    NODE *t=p;
    while (t)
    {
        n++;
        t=t->next;
    }
    NODE *a,*b;
    for(int i=0;i<n-1;++i)
    {
        a=p;
        b=p->next;
        for(int j=0;j<n-i-1;++j)
        {
            if(a->data > b->data)
            {
                int t=a->data;
                a->data=b->data;
                b->data=t;
            }
            a=b;
            b=b->next;
        }

    }
    
}
int main()
{
    insert(&start,20);
     insert(&start,2);
      insert(&start,30);
      
       insert(&start,4);
        insert(&start,50);
         insert(&start,6);
         display(start);
    bubble_sort_list(start);
    display(start);
    destroy(start);
    return 0;

}
