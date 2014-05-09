
#include<stdio.h>
#include<stdlib.h>

typedef struct dll
{	
	struct dll *back;
	int data;
	char name[10];
	struct dll *next;
}DLL;

void print(DLL *ptr)
{
	while(ptr)
	{
		printf("%d %s\n",ptr->data,ptr->name);
		ptr=ptr->next;
	}
}


void add(DLL **ptr2head)
{
	DLL *nu;
	nu=malloc(sizeof(DLL));
	printf("enter data: ");
	scanf("%d",&(nu->data));
	printf("enter name: ");
	scanf("%s",&(nu->name));
	if(*ptr2head==0)
	{
		nu->back=0;
		nu->next=0;
		*ptr2head =nu;
	}
	else
	{//link nu to the existing list
		if(nu->data < (*ptr2head)->data)
		{//link nu as a 1st node in
///existing list
			nu->back=0;
			nu->next=(*ptr2head);
			(*ptr2head)->back= nu;
			(*ptr2head)=nu;

		}
		else
		{
		//link nu to existing list not as 1st node
//but elsewhere
			DLL *temp=(*ptr2head);
while(temp->next && (temp->next->data< nu->data))
			temp=temp->next;


		nu->back=  temp;
		nu->next=   temp->next;
	if(temp->next)
	    temp->next->back = nu;
		temp->next= nu;

		}
	}//else

	return;
}//add


void delete(DLL **ptr)
{
	int n;
	DLL *temp=*ptr;
		
	if(*ptr==0)
	{
	printf("LIST EMPTY..\n");
		return;
	}

	printf("enter data to del: ");
	scanf("%d",&n);
	if(n==temp->data)
	{//deletion of 1st node
		(*ptr)=temp->next;
		(*ptr)->back = 0;
		free(temp);

	}
	else
	{
while(temp && ( temp->data != n))
		temp=temp->next;

	if(temp==0)
	{
		printf("data not found\n");
		return;
	}
	temp->back->next =temp->next;
	if(temp->next) 
	 temp->next->back = temp->back;
		free(temp);
	
	}

}
main()
{
	DLL *head=0;
	char choice;
	while(1)
	{
		printf("\na: add a record\n");
		printf("d:delete a record\n");
		printf("p: print \n");
		printf("e:exit\n");
		printf("enter a choice from above: ");
		scanf(" %c",&choice);
		switch(choice)
		{
			case 'a': add(&head);
				 break;
			case 'd':delete(&head);
				break;
			case 'p': print(head);
				break;
			case 'e':
				 exit(0);
			default: printf("invalid entry.\n");
		}

	}//while
}
