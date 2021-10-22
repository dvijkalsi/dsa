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
char pop(NODE **s)
{
    if((*s)==NULL)
    {
        printf("\nStack underflow");return '$';
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
int check_brackets(char *str)
{
    int len=strlen(str);
    for(int i=0;i<len;++i)
    {
        if(((str[i]=='(')||(str[i]=='['))||(str[i]=='{'))
        {
            push(&start1,str[i]);
        }
        else if((str[i]==')') && (start1->data=='('))
        {
            pop(&start1);
        }
        else if((str[i]=='}') && (start1->data=='{'))
        {
            pop(&start1);
        }
        else if((str[i]==']') && (start1->data=='['))
        {
            pop(&start1);
        }
        else if(((str[i]==')')||(str[i]==']'))||(str[i]=='}'))
        {
            printf("\nNO");
            return 0;
        }
        
    }
    if(start1!=NULL)
    {
        
        printf("\nNO");
        return 0;
    }
    else 
    {   
        
        printf("\nYES");
        return 1;
    }
}
int main()
{
    char str[]="{[()]}";
    check_brackets(str);
    destroy(&start1);
    char str2[]="{[(])}";
    check_brackets(str2);
    destroy(&start1);
    return 0;
}