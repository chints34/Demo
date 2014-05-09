#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main(int argc,char **p)
{
struct st{
	  int roll;
	  float mark;
	  char name[20];

	  }v[2];
FILE *fp,*fp1;
int i,in=0;
fp=fopen(p[1],"w+");
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
//fseek(fp,0,0);

//for(i=0;i<2;i++)
//{
//fscanf(fp,"%d %f %s",&v[i].roll,&v[i].mark,v[i].name);
//printf("%d %f %s\n",v[i].roll,v[i].mark,v[i].name);
}
//char str[2][80],ch;
//char temp[80];
//fseek(fp,0,0);
//while(fgets(str[in],80,fp))
//{
//in++;


//}
//for(i=0;i<in;i++)
//printf("%s",str[i]);
//fclose(fp);
int r;
printf("delete the record\n");
printf("r>using roll no.\nn>using name\n");
scanf("%d",&r);
fp1=fopen("temp.c","wb");
fseek(fp,0,0);
while(fread(&v,sizeof(v),1,fp)==1)
{
if(strcmp(v.roll,r)!=0)
fwrite(&v,sizeof(v),1,fp1);


}
fclose(fp);
fclose(fp1);
remove(p[1]);
rename("temp.c",p[1]);
}
}
