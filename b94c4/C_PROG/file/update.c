#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main(int argc,char **p)
{
struct st{
	   int roll;
		float mark;
	    char name[20];
	 }v[2];
FILE *fp;
int i,j;
fp=fopen(p[1],"w");
for(i=0;i<2;i++)
{
printf("enter the roll:\n");
scanf("%d",&v[i].roll);
printf("enter the mark:\n");
scanf("%f",&v[i].mark);
printf("enter the name:\n");
scanf("%s",v[i].name);
fprintf(fp,"%d %f %s\n",v[i].roll,v[i].mark,v[i].name);
}
fclose(fp);
////////////////////////////////////////////////
fp=fopen(p[1],"r");
char (*str)[100];
char temp[100];
str=calloc(1,100);
int in=0;
while(fgets(str[in],100,fp))
{
in++;
str=realloc(str,100*(in+1));
}

fclose(fp);
////////////////////////////////////
int roll;
printf("enter the roll no:\n");
scanf("%d",&roll);
str=realloc(str,300);
for(i=0;i<in;i++)
{
while(str=strchr(str[i],roll)!=NULL)
scanf("%d%f%s",&v[i].roll,&v[i].mark,v[i].name);
str++;
}
//for(i=0;i<in;i++)
//printf("%s",str[i]);
//////////////////////////////////
fp=fopen(p[1],"w");
for(i=0;i<in;i++)
fputs(str[i],fp);
fclose(fp);


}

