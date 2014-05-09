#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
main(int argc,char **p)
{
if(fork())
{
int sum;

wait(&sum);
sum>>=8;
printf("sum:%d\n",sum);


}
else
{
int i,j,sum;
i=atoi(p[1]);
j=atoi(p[2]);
sum=i+j;
//printf("sum:%d\n",sum);
exit(sum);


}

}
