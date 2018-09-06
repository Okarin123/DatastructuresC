#include<stdio.h> 
#include<stdlib.h>

typedef struct Node 
	{
	int position; 
	struct Node *next; 
	} Nd;

Nd* new_node(int data) 
	{

	Nd *ptr= (Nd*)malloc(sizeof(Nd));
	ptr->position= data; 

	return ptr; 
	}
 
Nd* assign_positions(int total)
	{
	int i; 

	Nd* circle_ref= new_node(1);
	Nd* prev=circle_ref;
	
	for (i=2; i<=total; i++) 
		{
		prev->next= new_node(i); 
		prev=prev->next;  
		}

	prev->next= circle_ref; 

	return circle_ref; 
	}

int josephus_position(Nd *circle_ref, int skip)
	{
	int i;
	Nd *temp= circle_ref, *ptr_to_be_freed;
	

	while (temp->next!=temp)
		{
		for (i=0; i<skip-2; i++)
			temp=temp->next; 

		ptr_to_be_freed= temp->next; 
		printf("\nCriminal %d executed.", temp->next->position);
		
		temp->next=temp->next->next;
		temp=temp->next;

		free(ptr_to_be_freed);  
		}

	return temp->position; 
	}

void main()
	{
	int total_criminals, gap, safe_pos;
	Nd* head;

	printf("\nEnter the total number of criminals: ");
	scanf("%d", &total_criminals); 

	printf("\nEnter positions to be skipped: ");
	scanf("%d", &gap); 

	if (gap==1)
		printf("\n\nLast person standing: %d\n", total_criminals);	

	else
		{
		head= assign_positions(total_criminals);
		safe_pos= josephus_position(head, gap); 

		printf("\n\nLast person standing: %d\n", safe_pos);
		} 
	}
	
	

	

 
		
		
	
	

	
		
 
