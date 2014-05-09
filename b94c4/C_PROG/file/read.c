/****read the data****/
#include<stdio.h>
main(int argc,char **argv)
{
char ch;
FILE *fp;
if(argc>2)
{
printf("wrong input:\n");
return;

}
fp=fopen(argv[1],"r");
if(fp==NULL)
{
printf("error:file doesent exist\n");
return;
}
while((ch=fgetc(fp))!=EOF)
printf("%c",ch);
fclose(fp);
}
