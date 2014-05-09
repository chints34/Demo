includee<stdio.h>
#include<unistd.h>
#include<stdlib.h>
main()
{
printf("%d\n",getpid());
printf("enter for close 2\n");
getchar();
close(2);
printf("enter for close 1\n");
getchar();
close(1);
printf("enter for close 0\n");
getchar();
close(0);
while(1);
}
