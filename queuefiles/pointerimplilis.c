#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct subject
	{
	char subname[30];
	struct subject *next;
	}sub;

typedef struct student
	{
	char name[32];
	sub *subject;
	struct student *next;
	}stud;

int isempty(stud *head)

	{
	    if(head==NULL)
	        return 1;
	    else
	        return 0;
	}

sub* createsub()
	{
	
	sub *ns=(sub*)malloc(sizeof(sub));
	
	printf("\nEnter Name of the subject ");
	scanf("%s",ns->subname);

	ns->next=NULL;
	return ns;
	}

stud* createstud()
	{
	stud *nn=(stud*)malloc(sizeof(stud));
    
	printf("\nEnter Name of the student ");
        scanf("%s",nn->name);
 
	nn->next=NULL;
	nn->subject=(sub*)malloc(sizeof(sub));
	sub *ns=nn->subject;

	int c=0;
    
	while(1)
		{
    
		printf("\n1.New sub\n2.Stop ");
	        scanf("%d",&c);
    
		if(c==2)
		        break;

		else
			{	
        		ns->next=createsub();
        		ns=ns->next;
			}
		    }
       	return nn;
	}

void display(stud *head)
	{

        stud *temp=head;
        int c=1;

	while(temp->next!=NULL)

		{
	        printf("\n\tSTUDENT %d",c);
		c++;
    
                temp=temp->next;
                sub *subjects=temp->subject;

		printf("\n\nName= %s",temp->name);
                printf("\nSubjects= ");
    
		while(subjects->next!=NULL)
		    {
			subjects=subjects->next;
		        printf("%s\t",subjects->subname);

    		    }
    printf("\n");
    }

}

void insertfirst(stud *head)
{
    stud *nn=createstud();
    nn->next=head->next;
    head->next=nn;
}

void insertlast(stud *head)
{
    stud *nn=createstud();
    stud *ptr=head;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    nn->next=NULL;
    ptr->next=nn;
}

void insert(stud *head,char studname[])
{
    stud *ptr=head;
    stud *nn=createstud();
    while(strcmp(ptr->name,studname)!=0)
        ptr=ptr->next;
    nn->next=ptr->next;
    ptr->next=nn;
}

void deletefirst(stud *head)
{
    if(isempty(head))
        printf("\nLIST EMPTY");
    else
    {
        stud *temp=head->next;
        head->next=temp->next;
        free(temp);
    }
}

void deletelast(stud *head)
{
        if(isempty(head))
        printf("\nLIST EMPTY");
    else
    {
    stud *ptr=head,*preptr;
    while(ptr->next!=NULL)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=ptr->next;
    free(ptr);
    }
}

void delpos(stud *head,int pos)
{
    int i=0;
    stud *ptr=head,*preptr;
    while(ptr->next!=NULL && i!=pos)
    {   preptr=ptr;
        ptr=ptr->next;
	i++;
    }
    preptr->next=ptr->next;
    free(ptr);

}

void displays(stud* ptr)
{
    printf("\n\nName= %s",ptr->name);
    printf("\nSubjects= ");
    sub *temp=ptr->subject;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        printf("%s, ",temp->subname);

    }
}


void modify(stud *ptr)
{
    int choice, check=0;
    char modified_sub[30];
    sub *sub_ptr; 

    displays(ptr);
    printf("\nDo you wish to:\n1.Modify Name\t2.Modify Subject\t3.Delete Subject- ");
    scanf("%d", &choice); 

    switch(choice)
	{

	case 1: 
		printf("\nEnter new name ");
		scanf("%s",ptr->name);
		break; 

	case 2: 
		printf("\nEnter subject to be modified: ");
		scanf("%s", modified_sub); 

		sub_ptr= ptr->subject; 

		while (sub_ptr->next!=NULL)
		        {
           	        sub_ptr=sub_ptr->next;
        	
			if(strcmp(sub_ptr->subname,modified_sub)==0)
        			{
				printf("\nEnter new subject name: ");
				scanf("%s", sub_ptr->subname);
				printf("\nModification Successful!");	
				check=1;    	
                                }
			}

		if (check==0)
			printf("\nModification Unsuccessful!");
		break;

	case 3: 
		printf("\nEnter subject to be deleted: ");
		scanf("%s", modified_sub); 

		sub_ptr= ptr->subject; 
		sub_ptr= sub_ptr->next;

		if (strcmp(sub_ptr->subname, modified_sub)==0)
			{
			ptr->subject= sub_ptr->next; 
			free(sub_ptr);
			printf("\nDeletion Successful!");
			check=1; 
			}

		else
			{

			while (sub_ptr->next!=NULL)
				{
				if (strcmp(sub_ptr->next->subname, modified_sub)==0)
					{
					sub_ptr->next=sub_ptr->next->next;
					free(sub_ptr->next);
					printf("\nDeletion successful!");
					check=1;
					}

				sub_ptr=sub_ptr->next;
				}
			}
	
		if (check==0)
			printf("\nDeletion Unsuccessful!");
		break;

	default: 
		printf("\nEnter apt. choice!");
	
	}
}

int searchsub(stud *head,char sname[])
{
    int total_num=0;
    printf("\nStudents enrolled for %s :",sname);
    stud *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        sub *ptr=temp->subject;
        while((ptr->next!=NULL))
        {
            ptr=ptr->next;
            if(strcmp(ptr->subname,sname)==0)
            {

                printf("\n\n\tSTUDENT %d",total_num+1);
                displays(temp);
                total_num++;
            }
        }
    }
    return total_num;
}

stud* searchname(stud *head,char sname[])
{
    stud *ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
        if(strcmp(ptr->name,sname)==0)
            return ptr; 
    }

    return NULL;
}

void main()
{
    stud *head=(stud*)malloc(sizeof(stud));
    head->next=NULL;
    while(1)
    {
        printf("\n\n1.Create\n2.Insert First\n3.Insert Last\n4.Insert after\n5.Delete First\n6.Delete Last\n7.Delete\n8.Display\n9.Modify\n10.Search by name\n11.Search by subject\n12.Count subject\nTo exit press 0");

	printf("\nEnter choice: ");
        int c;
        scanf("%d",&c);
        if(c==1)
        {
            int n,i;
            printf("\nEnter no. of students ");
            scanf("%d",&n);
            for(i=0;i<n;i++)
                insertlast(head);
        }
        else if(c==2)
            insertfirst(head);
        else if(c==3)
            insertlast(head);
        else if(c==4)
        {
            printf("\nEnter name after which to insert ");
            char nn[30];
            scanf("%s",nn);
            insert(head,nn);
        }
        else if(c==5)
            deletefirst(head);
        else if(c==6)
            deletelast(head);
        else if(c==7)
        {
            printf("\nEnter the position to delete to delete ");
            int n;
            scanf("%d",&n);
            delpos(head,n);
        }
        else if(c==8)
            display(head);
        else if(c==9)
        {
	    stud *can_modify; 
	
	    char nn[30];
	    printf("\nEnter student's name to be modified: ");	
            scanf("%s",nn);
            can_modify= searchname(head,nn);

	    if (can_modify==NULL)
		printf("\nStudent record not found!");

	    else
		modify(can_modify); 
	}
        
	else if(c==10)
        {
	    stud *found;
 	
            printf("\nEnter name to search ");
            char nn[30];
            scanf("%s",nn);
            found= searchname(head,nn);

	    if (found==NULL)
		printf("\nStudent record not found!");

	    else 
		displays(found);
        }
        else if(c==11)
        {
            printf("\nEnter subject to search ");
            char nn[30];
            scanf("%s",nn);
            searchsub(head,nn);

        }

        else if(c==12)
        {
            printf("\nEnter subject to search ");
            char nn[30];
            scanf("%s",nn);
            int c=searchsub(head,nn);
            printf("\nNumber of students enrolled= %d",c);

        }
        else
            break;


    }

}

