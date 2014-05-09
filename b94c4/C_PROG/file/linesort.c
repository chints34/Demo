/*...........sort tyhe file using strlength.........*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int strln(char *p)
{
char s[80];
strcpy(s,p);
while(s[0]==' ')
strcpy(s,s+1);
return strlen(s);


}
main(int argc,char **p)
{
char (*str)[80],temp[80];
str=malloc(80);
int i,in=0,j;
FILE *fp;
if(fp==NULL)
{
printf("error:");
return;
}
fp=fopen(p[1],"r");
while(fgets(str[in],80,fp))
{
in++;

str=realloc(str,80*(in+1));
}

fclose(fp);
for(i=0;i<in-1;i++)
{
for(j=i+1;j<in;j++)
{
if(strln(str[i])<strln(str[j]))
{
strcpy(temp,str[i]);
strcpy(str[i],str[j]);
strcpy(str[j],temp);

}

}

}

fp=fopen(p[1],"w");
for(i=0;i<in;i++)
if(strln(str[i])>1)
fputs(str[i],fp);
fclose(fp);


}
