/*command line input  for sum of integer****/
#include<stdio.h>
main(int argc,char *argv[])
{
int i,a,sum=0;
printf("argc=%d\n",argc);
for(i=1;i<argc;i++)
{
printf("argv[%d]=%s\n",i,argv[i]);
}
for(i=1;argv[i];i++)
{
a=atoi(argv[i]);
sum=sum+a;
}
printf("%d\n",sum);
}

