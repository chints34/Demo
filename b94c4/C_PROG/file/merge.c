#include<stdio.h>
#include<stdlib.h>
main(int argc,char **p)
{
char (*str)[80],(*str1)[80];
str=calloc(1,80);
//str1=calloc(1,80);
int i,in=0;
FILE *fp1,*fp2,*fp3;
fp1=fopen(p[1],"a");
fp2=fopen(p[2],"r");
while(fgets(str[in],80,fp2)!=NULL)
{
in++;
str=realloc(str,80*(in+1));
}
for(i=0;i<in;i++)
fputs(str[i],fp1);
//fclose(fp2);
//free(str);
//int in=0;
fp3=fopen(p[3],"r");
str1=calloc(1,80);
while(fgets(str1[in],80,fp3)!=NULL)
{
in++;
str1=realloc(str1,80*(in+1));
}
for(i=0;i<in;i++)
fputs(str1[i],fp1);

fclose(fp1);
//fclose(fp3);


}
