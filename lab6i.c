/*WAP to create a linked list that represents a polynomial expression with single variable 
(i.e. 5x7-3x5+x2+9) and display the polynomial by using user defined functions for creation and display.*/

#include<stdio.h>
#include<stdlib.h>
typedef struct node NODE;
struct node {
    int coeff;
    int exp;
    struct node *next;
} *start=NULL;
void add_node()
{

    
        NODE *new=(NODE*)malloc(sizeof(NODE));
        new->next=NULL;
        printf("\nEnter coeff,exp:");
        scanf("%d%d",&new->coeff,&new->exp);
        NODE* x=start;NODE* p;
        while(x)
        {
            if((new->exp)>(x->coeff))
            {
                p->next=new;
                new->next=x;
            }
            p=x;
            x=x->next;
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
void display(NODE *s)
{
    if(s==start)
    {
        printf("%d(X^%d)",s->coeff,s->exp);
        s=s->next;
    }
    
    
        while(s)
        {   if(s->coeff<0)
            {
                printf("%d(X^%d)",s->coeff,s->exp);
            }
            else
            {
                printf("+%d(X^%d)",s->coeff,s->exp);
            }
            
            s=s->next;
        }
    
}
int main()
{
    printf("Enter number of terms");
    int n;
    scanf("%d",&n);
    NODE *temp;
    if(n>0)
    {
        start=(NODE*)malloc(sizeof(NODE));
        start->next=NULL;
        printf("\nEnter coeff,exp:");
        scanf("%d%d",&start->coeff,&start->exp);
        
    }  
    temp=start;
    for(int i=2;i<=n;++i)
    {
        add_node(temp);
        temp=temp->next;
    }
    temp=start;
    display(temp);
    destroy();
    return 0;
    
}