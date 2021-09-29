/*Write a menu driven program to perform the following operations of a stack using array by using suitable
 user defined functions for each case.
a) Check if the stack is empty b) Display the contents of stack c) Push d) Pop*/
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
struct stack
{
    int size;
    int top;
    int *s;
};
bool is_overflow(struct stack st)
{
    if(st.top==st.size-1)
    {
        printf("Stack Overflow\n");
        return false;
    }
    else
    {
        
        return true;
    }
}
bool is_underflow(struct stack st)
{
    if(st.top==-1)
    {
        printf("Stack Underflow\n");
        return false;
    }
    else 
    {
        return true;
    }
}
void create_stack(struct stack *st)
{
    printf("Enter size of stack: ");
    scanf("%d",&st->size);
    st->top=-1;
    st->s=(int *)malloc((st->size)*sizeof(int));
}

void push(struct stack *st, int x)
{
    if (is_overflow(*st))
    {    
        st->top++;
        st->s[st->top]=x;
    }
}

int pop(struct stack *st)
{
    int x=-1;
    if(is_underflow(*st))
    {
        x=st->s[st->top--];
        
    }
    return x;
}

void display_stack(struct stack st)
{
    int i;
    if(is_underflow(st))
    {
        for(i=st.top;i>=0;--i)
            printf("%d ",st.s[i]);
    }
}


int main() {
    struct stack st;
    create_stack(&st);
    int n;
    printf("\n1.push\n2.pop\n3.display\n4.exit\nEnter your choice:");
    scanf("%d",&n);
    while(n!=4)
    {
        switch(n)
        {
            case 1:
                printf("\nEnter value to be pushed:");
                int y;
                scanf("%d",&y);
                push(&st,y);
                break;
            case 2:
                printf("\n%d\n",pop(&st));
                break;
            case 3:
                display_stack(st);
                break;
            case 4:
                break;
            default:
                printf("\ninvalid choice");
                break;
        }
    printf("\n1.push\n2.pop\n3.display\n4.exit\nEnter your choice:");
    scanf("%d",&n);
    }
    free(st.s);
    return 0;
}