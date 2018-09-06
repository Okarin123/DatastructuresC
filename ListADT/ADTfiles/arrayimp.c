#include<stdio.h> 
#include<string.h>

struct stud
	{
	char name[20], dept[10];
	float CGPA;
	};


int ins(struct stud arr[10], int n)

	{
	int pos; 
	
	printf("\nEnter insertion position: ");
	scanf("%d", &pos); 

	if ((pos>n)||(pos<0))
		{
		printf("\nEnter apt. position! "); 
		return n; 
		}

	int i=n-1; 
	
	while (i>=pos)
		{
		arr[i+1]=arr[i]; 
		i--;
		}

	
	printf("\nEnter the student's name: "); 
	scanf("%s", arr[pos].name);

	printf("\nEnter department: "); 
	scanf("%s", arr[pos].dept);

	printf("\nEnter CGPA: "); 
	scanf("%f", &arr[pos].CGPA);

	printf("\nInsertion successful! ");	
	return n+1; 

	}

int del(struct stud arr[10], int n)

	{
	char searchname[20];
	int i=0;
	
	printf("\nEnter the name of student whose record has to be deleted: "); 
	scanf("%s", searchname); 

	for (i=0; i<n; i++)
		if (strcmp(arr[i].name, searchname)==0)
			break; 

	if (i==n)
		{
		printf("\nRecord not found!");
		return n;
		}

	while (i<n-1)
		{
		arr[i]=arr[i+1]; 
		i++;
		}

	printf("\nDeletion successful!"); 
	return n-1;

	}	

void printarray(struct stud arr[10], int n)

	{
	int i=0;

	for (i=0; i<n; i++)
		{
		printf("\n\nStudent name: "); 
		puts(arr[i].name);

		printf("\nDepartment: "); 
		puts(arr[i].dept);

		printf("\nCGPA: %f", arr[i].CGPA); 
		}
	}

void main()

	{
	struct stud E[10];
	int number=0, ch=1, choice=0;

	while (ch==1)
		
		{

		printf("\nEnter the student's name: "); 
		scanf("%s", E[number].name);

		printf("\nEnter department: "); 
		scanf("%s", E[number].dept);

		printf("\nEnter CGPA: "); 
		scanf("%f", &E[number].CGPA);

		printf("\nDo you want to enter more records? (1/0): "); 
		scanf("%d", &ch);

		number++;
	
		}

	while (choice!=4)

		{

		printf("\nEnter the choice: \n1. To insert   2. To delete   3. To print   4. Exit:  "); 
		scanf("%d", &choice); 

		switch (choice)

			{
	
			case 1: 

				number=ins(E, number); 
				break; 

			case 2: 
		
				number=del(E, number); 
				break; 

			case 3:

				printarray(E, number); 
				break; 

			
			case 4: 

				break; 

			default:

				printf("\nEnter apt. choice!"); 
			}
		}
	}


 

 

	
	







