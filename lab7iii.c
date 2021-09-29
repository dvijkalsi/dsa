/*WAP to convert an infix expression into its equivalent postfix notation*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node NODE;
struct node
{
    char data;
    NODE *next;
};NODE *start1;
void push(NODE **s,char d)
{
    if((*s)==NULL)
    {
        (*s)=(NODE*)malloc(sizeof (NODE));
        (*s)->data=d;
        (*s)->next=NULL;
    }
    else
    {
        NODE *new=(NODE*)malloc(sizeof (NODE));
        new->next=(*s);
        new->data=d;
        (*s)=new;
    }
}
char pop(NODE **s)
{
    if((*s)==NULL)
    {
        printf("\nStack underflow");return '\0' ;
    }
    char t=(*s)->data;
    NODE *temp=(*s);
    (*s)=(*s)->next;
    free(temp);
    return t;
}
void display(NODE **s)
{
    if((*s)==NULL)
    {
        printf("\nEmpty stack");
        return ;
    }
    printf("\n");
    NODE *temp=(*s);
    while (temp)
    {
        printf("%c ",temp->data);
        temp=temp->next;
    }
    
}
void destroy(NODE **s)
{
    NODE *temp=(*s);
    if((*s)==NULL)
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
int check_bracket(char *p,int psize)
{    
    
    int flag=1;
    for(int i=0;i<psize;++i)
    {
        if(p[i]=='('||p[i]=='{'||p[i]=='[')
        {
            push(&start1,p[i]);
        }
        else if(start1!=NULL)
        {
            if((start1->data=='('&&p[i]==')')||(start1->data=='['&&p[i]==']')||(start1->data=='{'&&p[i]=='}'))
            {
                pop(&start1);       
            }
        }
        
        else if(p[i]==')'||p[i]==']'||p[i]=='}')
        {
            flag=0;break;
        }
    }
    
    if((start1!=NULL)||(flag))
    {
        return 0;
    }
    else 
    {
        return 1;
    }
}
int main()
{
    char p[]="[({()})]";
    int flag=check_bracket(p,strlen(p));
    printf("%d",flag);
    destroy(&start1);
    return 0;
}