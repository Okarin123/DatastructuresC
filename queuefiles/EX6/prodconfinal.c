#include<stdio.h> 
#include<string.h>

void make_empty (int *front, int *rear) 
	{
	*front = *rear = -1; 
	} 

char* consume (char container[10][20], int *front, int *rear, int *size) 
	{
	static char item[10];
	printf("\n");  

	if (*front==-1)
		return NULL; 		
		
	else 
		{
		strcpy(item, container[*front]); 

		if (*front==*rear) 
			make_empty (front, rear); 

		else if (*front==*size-1) 
			*front=0; 

		else 
			(*front)++; 
		}

	return item;
	}

void produce (char container[10][20], char item[20], int *front, int *rear, int *size)  
	{

	if (((*front == 0)&&(*rear== *size-1))||(*front==*rear+1)) 
		printf("\nContainer full!"); 

	else 
		{
		if (*front==-1) 
			*front = *rear = 0; 

		else if (*rear==*size-1) 
			*rear = 0; 

		else 
			(*rear)++;

		strcpy (container[*rear], item);  
		}
	}

void show_items (char container[10][20], int *front, int *rear, int *size)
	{
	int i; 

	if (*front==-1) 
		{
		printf("\nContainer empty!");
		return;
		}

	else 
		{
		int item_number = 0; 
		printf("\n"); 

		if (*front <= *rear) 
			for (i=*front; i<=*rear; i++)
				printf("%d) %s\n", ++item_number, container[i]); 
			
		else 
			{
			for (i=*front; i<=*size; i++)
				printf("%d) %s\n", ++item_number, container[i]); 
			
			for (i=0; i<=*rear; i++)
				printf("%d) %s\n", ++item_number, container[i]); 
			}			
		}
	}

void main () 
	{
	int front, rear, size; 
	int choice = 0;
	char item[20], container[10][20];
	char *deleted;   

	front = rear = -1;  
	size = 10; 
	
	while (choice!=4) 
		{
		printf("\nEnter choice\n1.Produce\t2.Consume\t3.Display Container items\t4.Exit : ");
		scanf("%d", &choice); 	

		switch (choice) 
			{
			case 1: 
				printf("\nEnter grocery item: "); 
				scanf("%s", item); 
				produce (container, item, &front, &rear, &size); 
				break;

			case 2: 
				deleted = consume (container, &front, &rear, &size); 

				if (deleted != NULL)
					printf("%s consumed.", deleted);
				else 
					printf("\nContainer empty!"); 
				break; 

			case 3: 
				show_items (container, &front, &rear, &size); 
				break; 

			case 4:
				break;
			} 
		} 
	} 		
	

	  

		  

	
