#include"headers.h"
void del(void)
{
     extern st *head;
     st *temp=head,*prev;
    int r;
    printf("enter the roll to delete:\n");
    scanf("%d",&r);
         if(r==head->roll)
	   {
	     head=head->link;
	     free(temp);

           }
         else
	    {
	     while(temp&&(temp->roll)!=r)
		{
		  prev=temp;
		  temp=temp->link;
                 }
             if(temp==NULL)
		{
		 printf("node not present:\n");
		 return;
                }
		prev->link=temp->link;
		free(temp);
            }

}
