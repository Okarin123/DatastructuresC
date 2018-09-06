#include<stdio.h> 

typedef struct student
	{
	char name[32];
	
	struct student *next;
	}stud;

int isempty(stud *head);
stud* createstud();
void display(stud *head);
void enqueue(stud *head, char string[32]);
void dequeue(stud *head);




