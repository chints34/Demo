#include"headers.h"
main(int argc,char **c)
{
int fd;
fd=open(c[1],O_WRONLY);
write(fd,"include",7);


}
