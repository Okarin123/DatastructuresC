#include<stdio.h> 
#include<ctype.h>

void push(char stack_arr[], int *top_ptr, char item)
	{
	stack_arr[++(*top_ptr)]= item;  
	}

char pop(char stack_arr[], int *top_ptr)
	{
	return stack_arr[(*top_ptr)--];
	}

int stack_priority (char operator)
	{
	 
	if (operator=='(')
		return 0; 

	else if (operator=='+' || operator =='-') 
		return 1; 

	else
		return 2; 
	}

char* Conversion (char input[])
	{
	char stack[10], item;
	char paranthesis_stack[10]; 

	static char postfix_res[20]; 
	int top=-1, post_index=0, i=0, j, paran_top=-1; 
	
	while (input[i]!='\0')
		{
		if (input[i]=='(') 
			push (paranthesis_stack, &paran_top, '(');

		if (input[i]==')')
			pop (paranthesis_stack, &paran_top); 

		//printf("Stack: ");

		//if (top==-1)
		//	printf("EMPTY!"); 

		//for (j=0; j<=top ; j++)
		//	printf("%c", stack[j]);		

		item = input[i];
		//printf("\nitem: %c\tTop: %d\n\n", item, top);

		if (isalpha(item)!=0)
			postfix_res[post_index++] = item; 

		else if (item=='(' || top==-1) 
			push (stack, &top, item); 

		else if (item=='+' || item=='*' || item=='/' || item=='-')
			{
			while ((stack_priority (item) <= stack_priority (stack[top])) && (top!=-1)) 
				postfix_res[post_index++]= pop (stack, &top); 

			push (stack, &top, item);  
			}

		else 
				{
				while (stack[top]!='(')
					postfix_res[post_index++] = pop (stack, &top);  

				top--;  
				}
   
		i++;			
		}

	if (paran_top!=-1) 
		{
		printf("\nParanthesis is not closed!\n");
		return NULL; 
		}  
			
	while (top!= -1)
		postfix_res[post_index++]= pop(stack, &top); 

	postfix_res[post_index] = '\0'; 

	return postfix_res; 
	}

void main()
	{
	char infix[20]; 
	char *Final_postfix;
	int i; 
	
	printf("\nEnter infix expression: ");
	scanf("%s", infix); 
	printf("\n");

	Final_postfix = Conversion(infix);

	if (Final_postfix==NULL)
		return; 

	printf("\nPostfix expression: "); 

	for (i=0; Final_postfix[i]!='\0' ; i++)
		printf("%c", Final_postfix[i]); 	

	printf("\n");  
	}


	
