/****size the data****/
#include<stdio.h>
main(int argc,char **argv)
{
char ch;
FILE *fp;
int cnt=0;
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
cnt++;
fclose(fp);
printf("%d",cnt);
}
