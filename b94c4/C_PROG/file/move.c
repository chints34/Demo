/*===move file===*/
#include<stdio.h>
main(int argc,char **p)
{
char ch,c;
FILE *sp,*dp;
if(argc!=3)
           {
             printf("error:enter valid data\n");
             return;
           }
sp=fopen(p[1],"r");
dp=fopen(p[2],"r");
if(dp!=NULL)
            {
              printf("warning:file is exist\nwill u continue enter y\n");
              scanf("%c",&c);
              if(c!='y')
              return;
             }
dp=fopen(p[2],"w");
while((ch=fgetc(sp))!=EOF)
fputc(ch,dp);
fclose(sp);
fclose(dp);
remove(p[1]);
}