/*....sort the line in  file....*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main(int argc,char **p)
{
FILE *fp;
char *str[80];
fp=fopen(p[1],"r");
if(fp==NULL)
{
printf("error:usage..:./a.out<file.c>");
return;

}
while((ch=fgetc(fp))!=EOF)
{
if(ch=='\n')
line++;
}
rewind(fp);






}
 
