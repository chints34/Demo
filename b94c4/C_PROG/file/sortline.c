#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main(int argc,char **p)
{
FILE *fp;
char ch,(*str)[80],*temp[80];
int line=0,i;

fp=fopen(p[1],"r");
if(fp==NULL)
{printf("error");
return;}
while((ch=fgetc(fp))!=EOF)
if(ch=='\n')
line++;
