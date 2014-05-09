/****write the data****/
#include<stdio.h>
main(int argc,char **argv)
{
char ch;
FILE *fp;
if(argc!=2)
{
printf("error:\n");
return;
}
fp=fopen(argv[1],"w");

printf("enter data(end with ctrl+d)\n");
while((ch=getchar())!=EOF)
fputc(ch,fp);
fclose(fp);
printf("\n====success====");
}
