#include"headers.h"
main(int argc,char **argv)
{
int sfd,cfd;
struct sockaddr_in saddr,caddr;
sfd=socket(AF_INET,SOCK_STREAM,0);
if(sfd<0)
{
perror("socket");
exit(0);
}

saddr.sin_family=AF_INET;
saddr.sin_port=htons(atoi(argv[1]));
saddr.sin_addr.s_addr=inet_addr("0.0.0.0");

if(bind(sfd,(struct sockaddr *)&saddr,sizeof(saddr))<0)
{
perror("bind");
exit(0);
}
puts("bind success\n");
if(listen(sfd,1)<0)
{
perror("listen");
exit(0);
}
puts("listen success\n");

while(1)
{
puts("server waiting for client request...\n");
socklen_t clen=sizeof(caddr);
cfd=accept(sfd,(struct sockaddr *)&caddr,&clen);
if(cfd<0)
{
perror("accept");
exit(0);
}
puts("accepted\n");
while(1)
{
char buff[100];
if(recv(cfd,buff,100,0)<=0)
{
perror("recv");
exit(0);
}
printf("data at server : %s\n",buff);
char cmd[100];
bzero(cmd,100);
strcpy(cmd,"echo ");
strcat(cmd,buff);
strcat(cmd," |bc");
printf("%s\n",cmd);
FILE *fp=popen(cmd,"r");
fgets(cmd,100,fp);
fclose(fp);
printf("%s\n",cmd);
send(cfd,cmd,strlen(cmd)+1,0);



}
}
close(cfd);
}




