#include"headers.h"
void getdata(void)
{
FILE *fp;
extern st *head;
st v,*temp,*nu;
fp=fopen("datafile","r");
if(fp==NULL)
{
printf("file is empty:\n");
return;
}
while(fread(&v,sizeof(v),1,fp))
{
nu=malloc(sizeof(st));
memcpy(nu,&v,sizeof(v));
nu->link=0;
if(head==NULL)
{
head=nu;
temp=nu;

}
else
{
temp->link=nu;
temp=nu;
}
}
fclose(fp);



}
