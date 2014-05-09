//open and read file at low level//
#include"headers.h"
main(int argc,char **c)
{
int fd;
char ch;
fd=open(c[1],O_RDONLY);
if(fd==-1)
  {
   perror("open");
   return;

  }
printf("fd=%d\n",fd);
while(read(fd,&ch,1)==1)
 printf("%c",ch);
 close(fd);

}
