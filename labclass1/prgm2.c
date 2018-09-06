#include<stdio.h> 

struct emp
	{
	int id;
	char name[20], dept[10];
	};


int Binarysearch (struct emp *ptr, int n, int s)
	
	{

	int first=0, last=n-1, mid;	

	while (first<=last)

		{

		mid=(first+last)/2;

		if ((ptr+mid)->id==s)
		
			{
			printf("\n\nEmployee record found!");
			printf("\n\	nEmployee name: ");
			puts((ptr+mid)->name);
			printf("\nEmployee department: "); 
			puts((ptr+mid)->dept);
			
			return 1;
			break; 
			}
	
		else if (s>(ptr+mid)->id)
			first=mid+1; 
			
		else
			last=mid-1; 
		
		}
	return 0; 
	
	}

void main()

	{
	struct emp E[10], T;
	int r, n=0, ch=1, j, tempid, i;

	while (ch==1)
		
		{
		printf("\nEnter the employee id: ");
		scanf("%d", &E[n].id); 

		printf("\nEnter the employee name: "); 
		scanf("%s", E[n].name);

		printf("\nEnter department: "); 
		scanf("%s", E[n].dept);

		printf("Do you want to enter more records? (1/0): "); 
		scanf("%d", &ch);

		n++;
	
		}
	
	for (i=0; i<n; i++)			//Sorting of records based on id
		for (j=0; j<n-i-1; j++)
			if (E[j].id>E[j+1].id)
				{
				T= E[j];
				E[j]=E[j+1];
				E[j+1]=E[j];
				}

	printf("\nEnter the id of employee whose record has to be searched: "); 
 	scanf("%d", &tempid); 

	r=Binarysearch(E, n, tempid); 

	if (r!=1)
		printf("\nEmployee ID does not exist!");

	}


 

 

	
	







