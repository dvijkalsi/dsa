/*2.Two brackets are considered to be a matched pair if the an opening bracket (i.e., (, [, or { ) 
occurs to the left of a closing bracket (i.e., ), ], or }) of the exact same type. There are three types of 
matched pairs of brackets: [], {}, and (). A matching pair of brackets is not balanced if the set of brackets
 it encloses are not matched. WAP to determine whether the input sequence of brackets is balanced or not.
  If a string is balanced, it print YES on a new line; otherwise, print NO on a new line. 
Example: Input: {[()]} and Output: YES
Input: {[(])} and Output: NO*/
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
int pop(NODE **s)
{
    if((*s)==NULL)
    {
        printf("\nStack underflow");return -999 ;
    }
    char t=(*s)->data;
    NODE *temp=(*s);
    (*s)=(*s)->next;
    free(temp);
    return 1;
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
int main()
{
    char p[]="[}]";
    int psize=strlen(p);
    printf("\n%d",psize);
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
    
    if((start1!=NULL)||(flag==0))
    {
        printf("NO");
    }
    else 
    {
        printf("YES");
    }
    
    destroy(&start1);
    return 0;
}