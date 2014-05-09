#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main(int argc,char **p)
{
FILE *fp;
int i=0,j,k,m;
char (*str)[80];
str=malloc(80);
fp=fopen(p[1],"r");
while(fgets(str[i],80,fp))
{

i++;

str=realloc(str,80*(i+1));

}
fclose(fp);
int n;
char temp[80];

for(k=0;k<i;k++)
{
while(str[k][0]==' ')

strcpy(str[k],str[k]+1);
strcpy(temp,str[k]);
n=79-strlen(str[k]);
memset(str[k],' ',n);
strcat(str[k],temp);

}

for(j=0;j<i;j++)
printf("%s",str[j]);
fp=fopen(p[1],"w");
fseek(fp,0,0);
for(m=0;m<i;m++)
fputs(str[m],fp);
fclose(fp);



}
