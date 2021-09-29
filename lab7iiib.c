//WAP to convert an infix expression into its equivalent postfix notation
#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	struct Stack
	{
		int top_006;
		unsigned capacity_006;
		int* array;
	};
	struct Stack* createmystack( unsigned capacity_006 )
	{
		struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
		if (!stack)
			return NULL;
	 
		stack->top_006 = -1;
		stack->capacity_006 = capacity_006;
	 
		stack->array = (int*) malloc(stack->capacity_006 * sizeof(int));
	 
		return stack;
	}
	int isEmpty(struct Stack* stack)
	{
		return stack->top_006 == -1 ;
	}
	char peek(struct Stack* stack)
	{
		return stack->array[stack->top_006];
	}
	char pop(struct Stack* stack)
	{
		if (!isEmpty(stack))
			return stack->array[stack->top_006--] ;
		return '$';
	}
	void push(struct Stack* stack, char op)
	{
		stack->array[++stack->top_006] = op;
	}
	int isOperand(char ch)
	{
		return (ch >= 'a' && ch <= 'z') ||
			   (ch >= 'A' && ch <= 'Z');
	}
	int Prec(char ch)
	{
		switch (ch)
		{
		case '+':
		case '-':
			return 1;
	 
		case '*':
		case '/':
			return 2;
	 
		case '^':
			return 3;
		}
		return -1;
	}
	int infixtopostfix(char* exp)
	{
		int i, k;
		struct Stack* stack = createmystack(strlen(exp));
		if(!stack) 
			return -1 ;
	 
		for (i = 0, k = -1; exp[i]; ++i)
		{
			if (isOperand(exp[i]))
				exp[++k] = exp[i];
			else if (exp[i] == '(')
				push(stack, exp[i]);
			else if (exp[i] == ')')
			{
				while (!isEmpty(stack) && peek(stack) != '(')
					exp[++k] = pop(stack);
				if (!isEmpty(stack) && peek(stack) != '(')
					return -1;           
				else
					pop(stack);
			}
			else 
			{
				while (!isEmpty(stack) &&
					 Prec(exp[i]) <= Prec(peek(stack)))
					exp[++k] = pop(stack);
				push(stack, exp[i]);
			}
	 
		}
		while (!isEmpty(stack))
			exp[++k] = pop(stack );
	 
		exp[++k] = '\0';
		printf( "%s", exp );
	}
	int main()
	{
		char exp_006[] = "a+(b*c-(d/e^f)*g)*h";
		infixtopostfix(exp_006);
		return 0;
	}