//open n reead using one call//
#include"headers.h"
main(int argc,char **c)
{
char *buf;
int fd,size,size1;
//struct stat v;
//if(stat(c[1],&v)==-1)
//return;
//else
size=lseek(fd,0,0);
size1=lseek(fd,0,2);
printf("%d\n",size1-size);
printf("%d\n",size);
buf=calloc(1,size+1);
//printf("%d\n",v.st_size);
//buf=calloc(1,v.st_size+1);
fd=open(c[1],O_RDONLY);
read(fd,buf,size);

printf("%s\n",buf);
close(fd);



}
