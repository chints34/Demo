#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
main(int argc,char **p)
{
int pid,signum;
   if(argc!=3)
    {
     printf("error:\n");
	return;
    }
pid=atoi(p[1]);
signum=atoi(p[2]);
if(kill(pid,signum)==-1)
{
perror("kill");
}
else
printf("sig:%d sent from %d to %d\n",signum,getpid(),pid);
}

