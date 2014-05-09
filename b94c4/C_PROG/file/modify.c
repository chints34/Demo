#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{

struct student
		{ int roll;
		  float marks;
		  char name[20];
		};
int i,n,r;
printf("enter the number of record need:\n");
scanf("%d",&n);
struct student st,temp;
FILE *fp;
fp=fopen("st.data","w");
for(i=0;i<n;i++)
   {
      printf("enter the roll:\n");
      scanf("%d",&st.roll);
      printf("enter the marks:\n");
      scanf("%f",&st.marks);
      printf("enter the name:\n");
      scanf("%s",st.name);
 //     fwrite(&st,sizeof(st),1,fp);
      fprintf(fp,"%d %f %s\n",st.roll,st.marks,st.name);

    }
fclose(fp);
char name[20];
long size=sizeof(st);
int flag=0;
printf("enter the name for delete:\n");
scanf(" %[^\n]s",name);
//scanf("%s",name);
fp=fopen("st.data","r+");
while(fscanf(fp,"%d %f %s",&st.roll,&st.marks,st.name))
//while(fread(&st,sizeof(st),1,fp)==1)
{
   if(strcmp(st.name,name)==0)
     {
	printf("enter new record:\n");
      printf("enter the roll:\n");
      scanf("%d",&st.roll);
      printf("enter the marks:\n");
      scanf("%f",&st.marks);
      printf("enter the name:\n");
      scanf("%s",st.name);
      fseek(fp,-size,1);
 //     fwrite(&st,sizeof(st),1,fp);
      printf("modified data: %d %f %s\n",st.roll,st.marks,st.name);
      fprintf(fp,"%d %f %s\n",st.roll,st.marks,st.name);
 flag=1;    
 break;	
     }
}
if(flag==1)
printf("record modify sucsessfully\n");
else
printf("not modify\n");
}

