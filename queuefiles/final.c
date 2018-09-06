# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "head.h"
#include"impliment.c"

void main()
{   
    int choice;
    char data[32];

    stud *stack;
    stack=(stud*)malloc(sizeof(stud));
    stack->next=NULL;

    do	
    {
        printf("\nEnter choice- 1.Push\t2.Pop\t3.Display top\t4.To exit: ");
        scanf("%d",&choice);
	
	switch (choice)
		{
		case 1:
			printf("\nEnter name: ");
			scanf("%s",data);
               		insertfirst(stack,data);
   			break;

        	case 2:
        	        deletefirst(stack);
			break; 

		case 3: 
		        top(stack);
        		break;
        
		case 4: 
			break;

		default: 
			printf("\nEnter apt. choice!");
		}

    } while (choice!=4);
}

