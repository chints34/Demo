#include"headers.h"
void add(void)
{
extern st *head;
st *temp;
st *nu;
nu=malloc(sizeof(st));
printf("enter the roll:\n");
scanf("%d",&nu->roll);
printf("enter the marks:\n");
scanf("%f",&nu->marks);
printf("enter the name:\n");
scanf("%s",nu->name);

                       if(head==NULL)
                                     {
                                        head=nu;
                                        nu->link=0;
                                     }
                        else
                                    {
					temp=head;
                                        while(temp->link!=NULL)
				        {
					temp=temp->link;
				       
				       	}
					temp->link=nu;
					nu->link=NULL;
                                     }
}
