#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main(int argc,char **argv)
{
FILE *fp,*ftemp;
char *p,c,*ptr,temp[50]={0},temp1[200],ch,*temp2;
bzero(temp,20);
char s1[20]="#include<";
int i,j,size=0;

fp=fopen(argv[1],"r");
while(c=fgetc(fp)!=EOF)
c++;
c++;
p=calloc(1,c);
rewind(fp);
i=0;
while((c=fgetc(fp))!=EOF)
{
p[i]=c;
i++;
}
fclose(fp);
printf("%s",p);
ptr=p;
while(ptr=strstr(ptr,s1))
{
for(i=9,j=0;ptr[i]!='>';i++,j++)
  {
   temp[j]=ptr[i];
  }
ptr++;

}
printf("1..>%s\n",temp);
strcpy(temp1,"/usr/include/");
printf("%s\n",temp1);
strcat(temp1,temp);
printf("%s\n",temp1);
ftemp=fopen(temp1,"r");
while((ch=fgetc(ftemp))!=EOF)
{
	size++;
}
	temp2=calloc(1,++size);
rewind(ftemp);
i=0;
while((ch=fgetc(ftemp))!=EOF)
{
temp2[i]=ch;
i++;
}
rewind(ftemp);
fp1=fopen("nu.c","w");
while((ch=fgetc(ftemp)!=NULL)
fputc(ch,fp1);
rewind(fp);
//while((ch=fgetc(fp)!=EOF)

}
