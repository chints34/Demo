#include<stdio.h>
#include<stdlib.h>
main(int argc,char **p)
{
struct st{
	  int roll;
	  float mark;
	  char name[20];

	  }v;
FILE *fp;
fp=fopen(p[1],"w+");
printf("enter the roll:\n");
scanf("%d",&v.roll);
printf("enter the mark:\n");
scanf("%f",&v.mark);
printf("enter the name:\n");
scanf("%s",v.name);
fprintf(fp,"%d %f %s",v.roll,v.mark,v.name);
fseek(fp,0,0);


fscanf(fp,"%d %f %s",&v.roll,&v.mark,v.name);
printf("%d %f %s\n",v.roll,v.mark,v.name);
fclose(fp);



}
