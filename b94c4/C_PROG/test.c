#include<stdio.h>
#include<unistd.h>
main()
{
printf("p1:%d %d",getpid(),getppid());
while(1);

}
