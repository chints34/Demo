#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main(int argc,char **p)
{
FILE *fp,*fp1;
char (*str)[80],temp[80];
int i,j,k;
fp=fopen(p[1],"r");
str=calloc(1,80);
i=0;
while(fgets(str[i],80,fp)!=NULL)
{
i++;
str=realloc(str,80*(i+1));
}
strcpy(temp,p[1]);
j=0;
while(temp[j]!='.')
j++;
memset(temp+j+1,'i',1);
fp1=fopen(temp,"w");
for(j=0;j<i;j++)
for(k=0;str[j][k]!='\0';k++)
if(!((str[j][k]=='/')&&(str[j][k+1]=='/')))
fputc(str[j][k],fp1);
else
break;
fclose(fp1);
fclose(fp);
}


