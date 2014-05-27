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
char buf[11]={0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99};
write(fd,buf,11);

close(fd);
return 0;
}
