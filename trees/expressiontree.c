#include<stdio.h> 
#include<ctype.h> 
#include<stdlib.h>

typedef struct TreeNode {

	char item; 
	struct TreeNode *left; 
	struct TreeNode *right; 
	
	} node; 

void push (node  *stack[], int *top_ptr, node *ptr) 
	{	
	stack[++(*top_ptr)] = ptr;  
	}

node *pop (node *stack[], int *top_ptr) 
	{
	return stack[(*top_ptr)--]; 	
	}

node* newnode()
	{
	node *ptr = (node*)malloc(sizeof(node)); 
	return ptr; 
	}

node *construct_tree (char postfix[])   
	{
	int i=0, top=-1; 
	node *curr, *popped_item1, *popped_item2, *root;  
	node *stack[20]; 

	while (postfix[i]!='\0')
		{
		curr = newnode(); 
		curr->item = postfix[i]; 

		if (isalpha(curr->item)!=0) 
			push (stack, &top, curr); 

		else 
			{
			popped_item1 = pop (stack, &top); 
			popped_item2 = pop (stack, &top); 

			curr->left = popped_item2; 
			curr->right = popped_item1; 

			push (stack, &top, curr);  			
			} 		  
		i++; 
		}

	root = stack[0]; 
	return root;  
	}

void Inorder_Print (node *root) 
	{
	if (root==NULL) 
		return; 

	else 
		{
		Inorder_Print (root->left); 
		printf("%c ", root->item);
 		Inorder_Print (root->right); 
		}
	} 

void Preorder_Print (node *root) 
	{
	if (root==NULL) 
		return; 

	else 
		{
		printf("%c ", root->item);
		Preorder_Print (root->left); 
 	 	Preorder_Print (root->right); 
		}
	} 

void Postorder_Print (node *root) 
	{
	if (root==NULL) 
		return; 

	else 
		{
		Postorder_Print (root->left); 
 	 	Postorder_Print (root->right); 
		printf("%c ", root->item);		
		}
	} 

void main ()
	{
	char postfix[10]; 
	node *root;  
	
	printf("\nEnter the postfix string: ");
	scanf("%s", postfix); 

	root = construct_tree (postfix); 

	printf("\nInorder: "); 
	Inorder_Print (root); 

	printf("\nPreorder: "); 
	Preorder_Print (root);

	printf("\nPostorder: "); 
	Postorder_Print (root); 
 
	printf("\n");  
	}
