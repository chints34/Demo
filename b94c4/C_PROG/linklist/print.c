#include"headers.h"
//extern st *head;
void print()
{
extern st *head;
st *temp;
temp=head;
while(temp)
{
printf("%d %f %s\n",temp->roll,temp->marks,temp->name);
temp=temp->link;


}



}
