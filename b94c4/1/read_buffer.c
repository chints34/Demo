#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
int fd=-1;
fd=open("/dev/hello",O_RDWR);
if(fd<0)
{
perror("open");
return;
}
char buf[12]={0};
printf("reading data...\n");


read(fd,buf,12);
if(fd<0)
{
perror("read");
return;
}
int i=0;
for(i=0;i<9;i++)
printf("%.2x  \n",buf[i]);

close(fd);


return 0;
}
