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

Nd* find_rear(Nd *head)
	{
	Nd *ptr= head; 

	while (ptr->next!=head)
		ptr=ptr->next; 

	return ptr;	
	}

void insert_first(Nd *head, int data)
	{
	Nd* ptr= new_node(data);
	Nd* rear;  
	
	if (head==NULL) //No data
		{
		ptr->next=ptr;
		head= ptr; 
		}

	else
		{
		rear= find_rear(head);
		ptr->next= head; 
		rear->next= ptr;
		head= ptr; 
		}

	return head;
	}


		
		
		
