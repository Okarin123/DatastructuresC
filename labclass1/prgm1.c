#include<stdio.h> 

struct emp
	{
	int id;
	char name[20], dept[10];
	};


int Linearsearch (struct emp *ptr, int n)
	
	{
	int tempid, i=0;

	printf("Enter id of employee whose details have to be searched: "); 
	scanf("%d", &tempid); 

	while (i<n)
		{
		
		if ((tempid)==((ptr+i)->id))
			{
			printf("\nEmployee details found at index position %d", i); 
			printf("\nEmployee name: ");
			puts((ptr+i)->name);
			printf("\nEmployee department: "); 
			puts((ptr+i)->dept);
			
			return 1; 
			break;
			
			}
		i++;
		
		}

	return 0;

	}

void main()

	{
	struct emp E[10];
	int r, i=0, ch=1;

	while (ch==1)
		
		{
		printf("\nEnter the employee id: ");
		scanf("%d", &E[i].id); 

		printf("\nEnter the employee name: "); 
		scanf("%s", E[i].name);

		printf("\nEnter department: "); 
		scanf("%s", E[i].dept);

		printf("Do you want to enter more records? (1/0): "); 
		scanf("%d", &ch);

		i++;
	
		}

	r=Linearsearch(E, i); 

	if (r!=1)
		printf("\nEmployee ID does not exist!");

	}


 

 

	
	







