#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main(int argc,char **p)
{
FILE *fp;
char ch,*ptr,*ptr1;
int i,size=0;
fp=fopen(p[1],"r");
if(fp==NULL)
{
printf("error");
return;
}
while(fgetc(fp)!=EOF)
size++;
fclose(fp);
size++;
ptr=calloc(1,size);
fp=fopen(p[1],"r");
for(i=0;i<size-1;i++)
ptr[i]=fgetc(fp);
ptr1=ptr;
fclose(fp);
while(ptr1=strstr(ptr1,p[2]))
{
memset(ptr1,'*',strlen(p[2]));
ptr1++;
}
fp=fopen(p[1],"w");
for(i=0;ptr[i];i++)
{
ch=ptr[i];
fputc(ch,fp);
}
fclose(fp);
}
