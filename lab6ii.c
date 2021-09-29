/*Write a program to add and multiply two polynomials with single variable with a new function for addition and 
multiplication operations.*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node NODE;
struct node {
    int coeff;
    int exp;
    struct node *next;
} *start1=NULL,*start2=NULL,*start3=NULL;
void add_node(NODE *s)
{

    
        NODE *new=(NODE*)malloc(sizeof(NODE));
        new->next=NULL;
        printf("\nEnter coeff,exp:");
        scanf("%d%d",&new->coeff,&new->exp);
        s->next=new;
    
}
void destroy1()
{
    if (!start1) return;

    NODE *ds = start1;
    while (ds != NULL)
    {
        NODE *victim = ds;
        ds = ds->next;
        free (victim);
    }
}
void destroy2()
{
    if (!start2) return;

    NODE *ds = start2;
    while (ds != NULL)
    {
        NODE *victim = ds;
        ds = ds->next;
        free (victim);
    }
}
void destroy3()
{
    if (!start3) return;

    NODE *ds = start3;
    while (ds != NULL)
    {
        NODE *victim = ds;
        ds = ds->next;
        free (victim);
    }
}
void display1(NODE *s)
{
    if(s==start1)
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
void display2(NODE *s)
{
    if(s==start2)
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
void display3(NODE *s)
{
    if(s==start3)
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
void sum(NODE *s1, int n1, NODE *s2, int n2)
{
    for(int i=1;i<=n1;++i)
    {
        for(int j=1;j<=n2;++j)
        {
            if((s1->exp)==(s2->exp))
            {
                s1->coeff+=s2->coeff;
            }
            s2=s2->next;
        }
        s1=s1->next;
        s2=start2;
    }
}
void multiply(NODE *s1,int n1, NODE *s2, int n2)
{
    start3=(NODE*)malloc(sizeof(NODE));
    int n3=0;
    NODE *s3=start3;

    for(int i=1;i<=n1;++i)
    {
        for(int j=1;j<=n2;++j)
        {
            NODE *new=(NODE*)malloc(sizeof(NODE));
            new->next=NULL; 
            s3->next=new;
            
            int coeff$=(s1->coeff)*(s2->coeff);
            int exp$=(s1->exp)+(s2->exp);
            s3->coeff=coeff$;
            s3->exp=exp$;
            n3++;s3=s3->next;s2=s2->next;
        }
        s1=s1->next;
        s2=start2;
    }
    s3=start3;NODE* s3$=start3;
    for(int i=1;i<=n3;i++)
    {
        for(int j=1;j<=n3;j++)
        {
            
            if((s3->exp)==(s3$->exp))
            {   NODE *x=start3;
                while(x->next!=s3$)
                {
                    x=x->next;
                }
                s3->coeff+=s3$->coeff;
                x->next=s3$->next;
                free(s3$);
                s3$=x->next;
            }
            else 
            {
                s3$=s3$->next;
            }
        }
        s3=s3->next;
        s3$=start3;
    }
}

int main()
{
    printf("Enter number of terms in 1:");
    int n;
    scanf("%d",&n);
    NODE *temp1;
    if(n>0)
    {
        start1=(NODE*)malloc(sizeof(NODE));
        start1->next=NULL;
        printf("\nEnter coeff,exp:");
        scanf("%d%d",&start1->coeff,&start1->exp);
        
    }  
    temp1=start1;
    for(int i=2;i<=n;++i)
    {
        add_node(temp1);
        temp1=temp1->next;
    }
    temp1=start1;
    display1(temp1);


    
    printf("\nEnter number of terms in 2:");
    int n2;
    scanf("%d",&n2);
    NODE *temp2;
    if(n2>0)
    {
        start2=(NODE*)malloc(sizeof(NODE));
        start2->next=NULL;
        printf("\nEnter coeff,exp:");
        scanf("%d%d",&start2->coeff,&start2->exp);
        
    }  
    temp2=start2;
    for(int i=2;i<=n2;++i)
    {
        add_node(temp2);
        temp2=temp2->next;
    }
    temp2=start2;
    display2(temp2);
    //sum(start1,n,start2,n2);
   // printf("\nSUMMED:\n");
   // display1(start1);
    multiply(start1,n,start2,n2);
    printf("\nMULTIPLIED:");
    display3(start3);
    destroy2();
    destroy1();
    destroy3();
    return 0;
    
}

