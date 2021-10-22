//WAP to convert an infix expression into its equivalent prefix notation. 
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
        printf("\nStack underflow");
        return '$';
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
int is_operand(char ch)
{
	return ((ch >= 'a' && ch <= 'z') ||(ch >= 'A' && ch <= 'Z'));
}
int is_operator(char t)
{
     if(t=='+'||t=='-'||t=='*'||t=='/'||t=='^'||t=='%')
    return 1;
    else 
    {
        return 0;
    }
}
int prec(char t)
{

	switch (t)
	{
	case '+':
	case '-':
    case '%':
		return 1;
	 
	case '*':
	case '/':
		return 2;
	 
	case '^':
		return 3;
	}
	return -1;
	
}
char* infix_to_postfix(char *q)
{
    
    
    char *p=(char*)calloc(30,sizeof(char));
    strcat(q,")");
    push(&start1,'(');
    int c=0;
    
    for(int i=0;i<strlen(q);++i)
    {
        
            if(is_operand(q[i]))
            {
                p[c++]=q[i];
                
            }
            else if(q[i]=='(')
            {
                push(&start1,'(');
                
            }
            else if(is_operator(q[i]))
            {
                while(prec(start1->data)>=prec(q[i]))
                {
                    if(start1->data=='(')
                    {
                        break;
                    }
                    p[c++]=pop(&start1);
                    
                }
                if(!(prec(start1->data)>=prec(q[i])))
                {
                    push(&start1, q[i]);
                    
                }
            }
            else if(q[i]==')')
            {
                while(start1->data!='(')
                {
                    p[c++]=pop(&start1);
                    
                }
                if(start1->data=='(')
                pop(&start1);
            }
            
        
        
    }
    return p;
    
}
void infix_to_prefix(char *r)
{
    printf("\ninfix:%s",r);
    char *st=(char*)calloc(30,sizeof(char));
    int c=0;
    for(int i=strlen(r)-1;i>=0;i--)
    {
        st[c++]=r[i];
    }
    
    st=infix_to_postfix(st);

     c=0;
    for(int i=strlen(st)-1;i>=0;i--)
    {
        r[c++]=st[i];
    }
    printf("\nPrefix:%s",r);
    free(st);
}
int main()
{
    char *q=(char*)malloc(sizeof(char)*30);
    strcpy(q,"a+b*c");
    infix_to_prefix(q);
    free(q);
    destroy(&start1);
    return 0;
}