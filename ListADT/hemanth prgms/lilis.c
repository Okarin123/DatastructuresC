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

void modify(stud *head,char name[])
{
    stud *ptr=head;
    while((strcmp(ptr->name,name))!=0)
        ptr=ptr->next;
    printf("\nEnter new name ");
    scanf("%s",ptr->name);
    ptr->subject=NULL;
    free(ptr->subject);
    ptr->subject=(sub*)malloc(sizeof(sub));
    sub *ns=ptr->subject;
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

int searchsub(stud *head,char sname[])
{
    int c=0;
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

                printf("\n\n\tSTUDENT %d",c+1);
                displays(temp);
                c++;
            }
        }
    }
    return c;
}

void searchname(stud *head,char sname[])
{
    stud *ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
        if(strcmp(ptr->name,sname)==0)
            displays(ptr);
    }

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
            printf("\nEnter name to modify ");
            char nn[30];
            scanf("%s",nn);
            modify(head,nn);
        }
        else if(c==10)
        {
            printf("\nEnter name to search ");
            char nn[30];
            scanf("%s",nn);
            searchname(head,nn);

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

