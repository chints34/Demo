#include<stdio.h>
#include<stdlib.h>
main(int  argc,char **p)
{
FILE *fp;
char *linebuf[5];
fp=fopen(p[1],"r");
if(fp==NULL)
{
printf("error");
return;
}
while(fgets(linebuf,5,fp))
{printf("%s",linebuf);
getchar();}
fclose(fp);
}
