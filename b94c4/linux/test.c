#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void isr(int n)
{
printf("ctrl+\\ is disabled");


}
main()
{
printf("%d\n",getpid());
signal(2,SIG_IGN);
signal(3,isr);
while(1);
}
