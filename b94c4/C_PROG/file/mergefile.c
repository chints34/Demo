#include<stdio.h>
#include<stdlib.h>
main(int argc,char **p)
{
FILE *fp,*fp1;
char str[100];
int i;
//printf("%d",argc);
fp=fopen(p[1],"a");
//if(fp==NULL)
//{
//perror("open");
//return;
//}

for(i=2;i<argc;i++)
{
fp1=fopen(p[i],"r");
//if(fp1==NULL)
//{
//perror("open");
//return;
/}
while((fgets(str,100,fp1))!=NULL)
{
fputs(str,fp);
}
fclose(fp1);
}

fclose(fp);

}
