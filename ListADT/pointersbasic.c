#include<stdio.h> 
#include<stdlib.h>
#include<string.h> 

struct sub // Subject details- Linked list
	{
	char sname[30]; 
	struct sub *next; 
	};

struct student // Student details
	{
	int rollno; 
	struct sub headnode; 
	}; 

void createsubjectnode (struct sub *ptr)

	{
	struct sub *temp;
	temp=ptr; 

	while (temp->next!=NULL)
		temp=temp->next; // Traversing

	struct sub *newsubject= (struct sub*)malloc(sizeof(struct sub)); // Creating new subject's details

	printf("\nEnter the course's code: ");
	scanf("%s",newsubject->sname);	// Error when accepting string input

	newsubject->next=temp->next;
	temp->next=newsubject;	

	}

void printstudentdetails(struct sub *ptr)

	{
	struct sub *temp;
	temp=ptr->next; 

	while (temp!=NULL)

		{
		printf("\nCourse's name: ");
		puts(temp->sname);

		temp=temp->next;
		}
	
	}

void main()

	{
	struct student S[10];
	int n=0, ch=1, subchoice=1, i;

	while (ch==1)

		{
		printf("\nStudent number %d: ", n+1); 
		
		printf("\nEnter the roll number: ");   
		scanf("%d", &S[n].rollno);

		S[n].headnode.next=NULL; // pointing headnode to NULL 

		while (subchoice==1)
		
			{
			createsubjectnode(&S[n].headnode); // Passing address of headnode

			printf("\nDo you want to add courses?: "); 
			scanf("%d", &subchoice);
			}

		n++;
		subchoice=1;

		printf("\nDo you want to add more student records?: "); 
		scanf("%d", &ch);
		}

	printf("\n\nDetails of students and their courses: "); // Printing details 

	for (i=0; i<n; i++)
		
		{
		printf("\n\nStudent %d", i+1);
		
		printf("\nRoll number: %d", S[i].rollno);
		printstudentdetails(&S[i].headnode);
		}
	
	}			

		
	

