#include<stdio.h> 

typedef struct student
	{
	char name[32];
	
	struct student *next;
	}stud;

int isempty(stud *head);
stud* createstud();
void top(stud *head);
void insertfirst(stud *head, char string[32]);
void deletefirst(stud *head);




