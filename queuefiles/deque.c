#include<stdio.h> 

typedef struct queue {
	
	int size;
	int capacity; 
	int front, rear; 
	int *array; 

} Deque; 

void delete_front (Dequeue *Q) 
	{
	int item; 

	if (Q->front==-1)
		{
		printf("\nUnderflow!");  
		return; 		
		}

	else 
		{
		item = Q->array[Q->front]; 

		if (Q->front==Q->rear) 
			make_empty (Q); 

		else if (Q->front==Q->capacity-1) 
			Q->front=0; 

		else 
			Q->front++; 

		printf("\nThe item deleted: %d", item); 
		}
	}

void delete_rear (Deque *Q) 
	{
	int item; 

	if (Q->front==-1) 
		{
		printf("\nUnderflow!");  
		return; 		
		}

	else 
		{
		item = Q->array[Q->rear]; 

		if (Q->front==Q->rear) 
			make_empty (Q); 

		else if (Q->rear==0) 
			Q->rear=Q->capacity-1; 

		else 
			Q->rear--; 

		printf("\nThe item deleted: %d", item); 
		}
	}

void enqueue_rear (Dequeue *Q, int item) 
	{

	if (((Q->front==0)&&(Q->rear==Q->capacity-1))||(Q->front==Q->rear+1)) 
		printf("\nOverflow!"); 

	else 
		{
		if (Q->front==-1) 
			Q->front=Q->rear=0; 

		else if (Q->rear==Q->capacity-1) 
			Q->rear=0; 

		else 
			Q->rear++; 

		Q->array[Q->rear]=item; 
		}
	}

		
	

	  

		  

	
