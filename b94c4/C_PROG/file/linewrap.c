#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main(iny argc,char **p)
{
FILE *fp;
int size=0,in=0;
char (*str)[10];
fp=fopen(p[1],"r");
fseek(fp,0,2);
size=ftell();
size++;
rewind(fp);
while(fgets(str[in],80,fp));
in++;
str=calloc(in,10);            





}
