#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main(int argc,char **p)
{
FILE *fp;
int size=0,line=0,word=0,i,chr;
char *str,ch;
if(argc!=2)
      {
        printf("error:\n");
          return;
      }
fp=fopen(p[1],"r");
if(fp==NULL)
           {
            printf("file does not exist\n");
            return;
           }
while(fgetc(fp)!=EOF)
size++;

fclose(fp);
size++;
str=calloc(1,size);
fp=fopen(p[1],"r");
for(i=0;i<size-1;i++)
                    {
                     str[i]=fgetc(fp);
                     if(str[i]=='\n')
                     line++;
                     }
fclose(fp);
while(str[0]==' ')
strcpy(str,str+1);
while(str[strlen(str)-1]==' ')
str[strlen(str)-1]='\0';
for(i=0;str[i];i++)
{
if(str[i]=='\n')
while(str[i+1]=='\n')
strcpy(str+i,str+i+1);
if(str[i]==' ')
while(str[i+1]==' ')
strcpy(str+i,str+i+1);
}
for(i=0;str[i];i++)
if(str[i]==' '||str[i]=='\n')
word++;
printf("%d %d %d\n",line,word,size-1);




}

