#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int isempty(stud *head)
	{
	    if(head->next==NULL)
	        return 1;
	    else
	        return 0;
	}

stud* createstud()
	{
	stud *nn=(stud*)malloc(sizeof(stud));
    
	return nn;
	}

void top(stud *head)
	{

	if(isempty(head))
		{
        	printf("\nLIST EMPTY");
		return; 
		}
		        
	stud *temp=head->next;

	printf("\n");
	puts(temp->name);
	}

void insertfirst(stud *head, char string[32])
{
    stud *nn=createstud();
    strcpy(nn->name, string);
    nn->next=head->next;
    head->next=nn;
}

void deletefirst(stud *head)
{
    if(isempty(head))
        printf("\nLIST EMPTY");
    else
    {
        stud *temp=head->next;
	
	printf("\nName popped: ");
	puts(temp->name);

        head->next=temp->next;
        free(temp);
    }
}

