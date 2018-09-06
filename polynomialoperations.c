#include<stdio.h> 
#include<stdlib.h>

typedef struct Node 
	{
	int coeff;
	int exp; 
	struct Node *next; 
	} Nd;

Nd* new_node(int coefficient, int exponent) 
	{

	Nd *ptr= (Nd*)malloc(sizeof(Nd));
	ptr->coeff=coefficient;
	ptr->exp=exponent;

	return ptr; 
	}

void add_node (Nd *head, int coefficient, int exponent)
	{
	Nd* new_term= new_node(coefficient, exponent);
	Nd* temp= head;

	while (temp->next!=NULL)
		temp=temp->next; 

	new_term->next=temp->next;
	temp->next= new_term; 
	}

Nd * create_poly()
	{
	int choice, exponent, coefficient;

	printf("\nEnter exponent: ");
	scanf("%d", &exponent); 

	printf("\nEnter coefficient: ");
	scanf("%d", &coefficient); 
					
	Nd* head= new_node(coefficient, exponent); 
	head->next=NULL;	
	
	Nd* ptr;

	do 
		{
		printf("\n1.Add terms\t2.Stop: ");
		scanf("%d", &choice);
		
		ptr=head;

		switch(choice)
			{
			case 1:
				printf("\nEnter exponent: ");
				scanf("%d", &exponent); 
				
				while (ptr!=NULL)
					{
					if (ptr->exp==exponent)
						break; 
					
					ptr=ptr->next;
					}
	
				if (ptr==NULL)
					{
					printf("\nEnter coefficient: ");
					scanf("%d", &coefficient); 

					add_node(head, coefficient, exponent);
					}

				else
					{
					printf("\nEnter coefficient: ");
					scanf("%d", &coefficient); 

					ptr->coeff+= coefficient;
					}
					
	
				break; 

			case 2:
				break; 

			default:
				printf("\nEnter apt. term!");
			}
		
		} while (choice!=2);
	return head;
	}

Nd* sum(Nd *head1, Nd *head2)
	{

	Nd *result; 
	Nd *ptr1=head1, *ptr2=head2;

	int first=0;  // Signifies adding nodes at result_head position
	int sum_coeff; 

	while(ptr1 != NULL && ptr2 != NULL)
	{
		if(ptr1 -> exp == ptr2 -> exp)
			{
			sum_coeff = ptr1 -> coeff + ptr2 -> coeff;
			
			if (first==1)
				add_node(result, sum_coeff, ptr1 -> exp);

			else 
				{
				result = (Nd*)malloc(sizeof(Nd));
				result->exp= ptr1->exp;
				result->coeff= sum_coeff; 
				result->next=NULL;

				first=1; 				
				}
			
			ptr1 = ptr1 -> next;
			ptr2 = ptr2 -> next;
			}
		
		else if(ptr1 -> exp > ptr2 -> exp)
			{

			if (first==1)
				add_node(result, ptr1->coeff, ptr1 -> exp);

			else 
				{
				result = (Nd*)malloc(sizeof(Nd));
				result->exp= ptr1->exp;
				result->coeff= ptr1->coeff; 
				result->next=NULL;

				first=1; 				
				}
			
			ptr1 = ptr1 -> next;
			}

		else if(ptr1 -> exp < ptr2 -> exp)
			{

			if (first==1)
				add_node(result, ptr2->coeff, ptr2 -> exp);

			else 
				{
				result = (Nd*)malloc(sizeof(Nd));
				result->exp= ptr2->exp;
				result->coeff= ptr2->coeff; 
				result->next=NULL;

				first=1; 				
				}
			
			ptr2 = ptr2 -> next;
			}
	}
	
	if(ptr1 == NULL)
		{
		
		while(ptr2 != NULL)
			{
			if (first==1)
				add_node(result, ptr2->coeff, ptr2 -> exp);

			else 
				{
				result = (Nd*)malloc(sizeof(Nd));
				result->exp= ptr2->exp;
				result->coeff= ptr2->coeff; 
				result->next=NULL;

				first=1; 				
				}
			
			
			ptr2 = ptr2 -> next;
			}
		}
		
	if(ptr2 == NULL)
		{
		
		while(ptr1!= NULL)
			{
			if (first==1)
				add_node(result, ptr1->coeff, ptr1 -> exp);

			else 
				{
				result = (Nd*)malloc(sizeof(Nd));
				result->exp= ptr1->exp;
				result->coeff= ptr1->coeff; 
				result->next=NULL;

				first=1; 				
				}
			
			ptr1 = ptr1 -> next;
			}
		}

	return result; 
	}

Nd* difference (Nd *head1, Nd *head2) 
	{
	Nd *ptr= head2;

	while(ptr!=NULL)
		{
		ptr->coeff = -1*(ptr->coeff); 
		ptr = ptr -> next;
		}

	Nd *result= sum (head1, head2);  
	return result; 
	}

Nd* mul_polynomial(Nd *head1, Nd* head2)
	{
	int exponent, coefficient; 

	Nd* search; 
	Nd* ptr1= head1;
	Nd* ptr2= head2; 

	Nd *result= (Nd*)malloc(sizeof(Nd));
		
	result->exp= (ptr1->exp)+(ptr2->exp); 
	result->coeff= (ptr1->coeff)*(ptr2->coeff);

	ptr2= ptr2->next; 

	while (ptr2!=NULL)
		{
			
		search= result; 
	
		exponent= (ptr1->exp) + (ptr2->exp); 
		coefficient= (ptr1->coeff) * (ptr2->coeff);
	
		while (search!=NULL)
			{
			if (search->exp==exponent)
				break; 
						
			search=search->next;
			}
	
		if (search==NULL)
			add_node(result, coefficient, exponent);
			
		else
			search->coeff+= coefficient;

		ptr2= ptr2->next; 
		}

	ptr1= ptr1->next; 

	while (ptr1!=NULL)
		{	

		ptr2= head2; 

		while (ptr2!=NULL)
			{

			search= result; 
	
			exponent= ptr1->exp + ptr2->exp; 
			coefficient= ptr1->coeff * ptr2->coeff;
	
			while (search!=NULL)
				{
				if (search->exp==exponent)
					break; 
						
				search=search->next;
				}
	
			if (search==NULL)
				add_node(result, coefficient, exponent);
			
			else
				search->coeff+= coefficient;

			ptr2= ptr2->next; 
			}

		ptr1= ptr1->next; 
		}
	
	return result; 
	}

void display(Nd *start)
	{
	Nd *ptr= start;
	printf("\n");	

	while(ptr->next!=NULL)
		{
		printf("%dx^%d + ", ptr->coeff, ptr->exp);
		ptr = ptr -> next;
		}

	printf("%dx^%d\n", ptr->coeff, ptr->exp);
		
	}

void main()
	{

	printf("\nEnter polynomial 1: ");
	Nd *poly1_head= create_poly();
	printf("Entered polynomial is: "); 
	display(poly1_head);	

	printf("\nEnter polynomial 2: ");	
	Nd *poly2_head= create_poly(); 
	printf("Entered polynomial is: "); 
	display(poly2_head);
	
	Nd *resultsum_head = sum(poly1_head, poly2_head); 
	printf("\n\nSum is: "); 
	display(resultsum_head);
	
	/*Nd *resultmul_head= difference(poly1_head, poly2_head);
	printf("\n\nProduct is: "); 
	display(resultmul_head);*/

	Nd *resultdiff_head= difference(poly1_head, poly2_head);
	printf("\n\nDifference is: "); 
	display(resultdiff_head);

	}
				
					
				




