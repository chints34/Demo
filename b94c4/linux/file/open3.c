//open and read file at using fstat//
#include"headers.h"
main(int argc,char **c)
{
int fd;
char ch,*buf;
struct stat v;
fd=open(c[1],O_RDONLY);
if(fd==-1)
  {
   perror("open");
   return;

  }
else
fstat(fd,&v);
buf=sbrk(v.st_size+1);

read(fd,buf,v.st_size);
 printf("%s\n",buf);
 close(fd);

}
