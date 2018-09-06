#include<stdio.h> 
#include<string.h>

typedef struct student_t
	{
	char name[32];
	subject_t *subject; 
	student_t *next;
	};

typedef struct subject_t
	{
	char name[30];
	subject_t *nextsub;
	}; 

student_t* create_student(char *studname, student_t *stu_head)  // To create student
	{
	int check_name=0;
	student_t Newstudent, temp;
	
	Newstudent=(*student_t)malloc(sizeof(student_t));
		
	while(check_name!=1)	
		{
		check_name=1;
		temp=head->next;

		while (temp->next!=NULL)
			{
			if (strcmp(temp->name, *studname)==0)
				{
				printf("\nStudents' names must not be same! Enter name again: ");
				check_name=0;
				scanf("%s", studname); 
				break;
				}
			
			temp=temp->next;
			}
		}	

	strcpy(Newstudent->name,studname);
	
	return Newstudent;
	}

int create_subject(char *subjectname, subject_t *sub_head)
	{
	int check_name=0;
	subject_t Newsubject, temp; 
	
	Newsubject=(*subject_t)malloc(sizeof(subject_t));
		
	while(check_name!=1)	
		{
		check_name=1;
		temp=sub_head->next;

		while (temp->next!=NULL)
			{
			if (strcmp(temp->name, *subjectname)==0)
				{
				printf("\nSubjects' names must not be same! Enter name again: ");
				check_name=0;
				scanf("%s", subjectname); 
				break;
				}
			
			temp=temp->next;
			}
		}	

	strcpy(Newsubject->name,subjectname);

	temp=head; 

	while(temp->next!=NULL)
		temp=temp->next;

	Newstudent->next=temp->next;
	temp->next=Newstudent;

	return 1;
	}

void Insert_first (student_t *stu_head) 
	{
	char stu_name[32]; 
	student_t *ptr, temp;

	temp=stu_head;

	printf("\nEnter student's name: ");
	scanf("%s", stu_name);
	
	ptr= create_student(stu_name, stu_head);
	ptr->next=temp->next; 
	temp->next=ptr;
	}

void Insert_atpos (student_t *stu_head, int pos)
	{
	char stu_name[32]; 
	student_t *ptr, temp;

	temp=stu_head->next;

	printf("\nEnter student's name: ");
	scanf("%s", stu_name);
	
	ptr= create_student(stu_name, stu_head);
	
	for (i=1; i<pos; i++)
		{
		if (temp->next==NULL)
			{
			printf("\ninsertion not possible at given position!");
			return; 
			}

		temp=temp->next;
		}

	ptr->next=temp->next;
	temp->next=ptr;
	}

void Insert_last (student_t *stu_head)
	{
	char stu_name[32]; 
	student_t *ptr, temp;

	temp=stu_head;

	printf("\nEnter student's name: ");
	scanf("%s", stu_name);
	
	ptr= create_student(stu_name, stu_head);
	
	while (temp->next!=NULL)
		temp=temp->next; 

	ptr->next=temp->next; 
	temp->next=ptr; 
	}

void display_subjects(student_t *stu_head)
	{
	student_t *ptr=stu_head;

	if (ptr->next==NULL)
		return;

	ptr=ptr->next;

	while (ptr->next!=NULL)
		{
		subject_t *temp=ptr->subject->nextsub; 

		while (temp->nextsub!=NULL)
			{
			printf("\nSubject name: "); 
			puts(temp->name); 
			temp=temp->nextsub;
			}
		}
	}









	
	
		
	

	

	
	

	
			

		

			
