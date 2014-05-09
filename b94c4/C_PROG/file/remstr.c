#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main(int argc,char **p)
{
FILE *fp;
char *str,ch,*str2;
int i,size=0;
fp=fopen(p[1],"r");
if(fp==NULL)
{
printf("file not exist:\n");
return;

}
while(fgetc(fp)!=EOF)
size++;
size++;
fclose(fp);
str=calloc(1,size);
fp=fopen(p[1],"r");
for(i=0;i<size-1;i++)
str[i]=fgetc(fp);
fclose(fp);
str2=str;

while(str2=strstr(str2,p[2]))
{
strcpy(str2,str2+strlen(p[2]));
str2++;
}
fp=fopen(p[1],"w");
for(i=0;str[i];i++)
{
ch=str[i];
fputc(ch,fp);
}
fclose(fp);
}
