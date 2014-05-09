#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main(int argc,char **p)
{
struct st{
	   int roll;
		float mark;
	    char name[20];
	 }v,str[50],temp;
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
//fp=fopen(p[1],"rb");
//char (*str)[100];
//char temp[100];
//str=calloc(1,100);
int in=0;
//for(i=0;i<2;i++)
while(fread(&v,sizeof(v),1,fp)==1)
{
str[in]=v;
in++;
}
//for(i=0;i<in;i++)
//printf("%s",str[i]);

//fclose(fp);
////////////////////////////////////
for(i=0;i<in;i++)
{
for(j=0;j<in-1-i;j++)
{
if(strcmp(str[j].name,str[j+1].name)>0)
{
temp=str[j];
str[j]=str[j+1];
str[j+1]=temp;
}
}
}
for(i=0;i<in;i++)
printf("%d %f %s\n",str[i].name,str[i].mark,str[i].name);
//////////////////////////////////
//fp=fopen(p[1],"w");
//for(i=0;i<in;i++)
//fputs(str[i],fp);
//fclose(fp);


}

