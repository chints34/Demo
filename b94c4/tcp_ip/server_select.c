#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/time.h>
#include<sys/ioctl.h>
#include<unistd.h>
int main()
{
int server_sockfd, client_sockfd;
int server_len, client_len;
struct sockaddr_in server_addr, client_addr;
int result;
fd_set readfds, testfds;

server_sockfd = socket(AF_INET,SOCK_STREAM, 0);

server_addr.sin_family = AF_INET;
server_addr.sin_addr.s_addr=htonl(INADDR_ANY);
server_addr.sin_port = htons(12456);
server_len = sizeof(server_addr);

bind(server_sockfd, (struct sockaddr *)&server_addr, server_len);

listen(server_sockfd, 5);

FD_ZERO(&readfds);
FD_SET(server_sockfd, &readfds);

while(1)
{
char ch[128];
int fd;
int nread;

testfds = readfds;

printf("server waiting  %d\n",FD_SETSIZE);

result = select(1024, &testfds, (fd_set *)0, (fd_set *)0,(struct timeval *)0);

if(result < 1)
{
perror("server5");
exit(1);
}

for(fd=0; fd < FD_SETSIZE; fd++)
{
if(FD_ISSET(fd, &testfds))
{
if(fd == server_sockfd) 
{
client_len = sizeof(client_addr);
client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_addr, &client_len);
FD_SET(client_sockfd, &readfds);
printf("adding client on fd %d\n", client_sockfd);
}
else
{
ioctl(fd, FIONREAD, &nread);

if(nread == 0)
{
close(fd);
FD_CLR(fd, &readfds);
printf("removing client on fd %d\n",fd);
}
else
{
read(fd, ch, sizeof(ch));
printf("Data from client fd %d is %s \n",fd,ch);
sleep(5);
printf("serving client on fd %d\n",fd);
write(fd,ch,sizeof(ch));
}

}
}
}
}
}
