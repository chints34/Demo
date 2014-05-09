#include"headers.h"
main(int argc,char **argv)
{
int sfd,cfd;
struct sockaddr_in saddr,caddr;
sfd=socket(AF_INET,SOCK_DGRAM,0);
puts("server socket created\n");

saddr.sin_family=PF_INET;
saddr.sin_port=htons(atoi(argv[1]));
saddr.sin_addr.s_addr=inet_addr("0.0.0.0");
puts("binding....\n");
bind(sfd,(struct sockaddr *)&saddr,sizeof(saddr));
puts("bind success");
puts("listening...\n");
listen(sfd,2);
puts("listen success\n");


while(1)
{
while(1)
{
int clen=sizeof(caddr);
char buff[100],c;
recvfrom(sfd,buff,100,0,(struct sockaddr *)&caddr,&clen);
printf("data at server : %s\n",buff);
int i=0,j=strlen(buff)-1;
for(i=0;i<j;i++,j--)
{
c=buff[i];
buff[i]=buff[j];
buff[j]=c;

}
printf("reversed at server :%s\n",buff);
puts("sending to client...\n");
sendto(sfd,buff,strlen(buff)+1,0,(struct sockaddr *)&caddr,clen);
puts("sent\n");

}
}
}




