/*....replace the word in file....*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main(int argc,char **p)
{
FILE *fp;
char *buf,ch;
int i,size=0;
if(argc!=4)
{
printf("error:invalid");
return;
}
fp=fopen(p[3],"r");
if(fp==NULL)
{
printf("file not exist:\n");
return;

}
fseek(fp,0,2);
size=ftell(fp);
size++;
buf=calloc(1,size);
fseek(fp,0,0);
fread(buf,size-1,1,fp);
fclose(fp);

char *s1,*s2,*temp,*buf1;
int len1,len2;
s1=p[1];
s2=p[2];
len1=strlen(s1);
len2=strlen(s2);
temp=buf;

while(temp=strstr(temp,s1))
{
buf1=calloc(1,size);
strcpy(buf1,temp+len1);
size=size+(len2-len1);
buf=realloc(buf,size);
strcpy(temp,s2);
strcat(buf,buf1);
free(buf1);
temp+=len2;
}
fp=fopen(p[3],"r+");
fseek(fp,0,0);
fputs(buf,fp);
fclose(fp);
}
