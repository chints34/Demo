#include"headers.h"
void save(void)
{
extern st *head;
st *temp;
temp=head;
FILE *fp;
fp=fopen("datafile","w");
while(temp)
     {
	fwrite(temp,sizeof(st),1,fp);
	temp=temp->link;
     }
fclose(fp);
printf("====saved====\n");



}
