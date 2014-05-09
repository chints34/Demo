#include"headers.h"
main(int nf,char **argv)
{
	int fd=socket(AF_INET,SOCK_STREAM,0);
	
	struct sockaddr_in addr;	
		
	if(fd<0)
	{
		perror("socket");
		exit(0);
	}
    
    
	printf("socket is created\n");
	
		
	addr.sin_family=AF_INET;
	
	addr.sin_port=htons(atoi(argv[1]));
	addr.sin_addr.s_addr=inet_addr("127.0.0.1");

if(connect(fd,(struct sockaddr *)&addr,sizeof(addr))<0)
{
perror("connect");
exit(0);
}
puts("connected\n");







	char buff[100];
	while(1)
{
		
		printf("enter the data :");
		scanf(" %[^\n]s",buff);
		int len=sizeof(addr);		
		send(fd, buff, strlen(buff)+1,0);
		
		
		printf("client send:%s\n",buff);
		if(strcmp(buff,"bye")==0)
			break;

		bzero(buff,100);
		len=sizeof(addr);		
		if(recv(fd,buff,100,0)<0)
		{
			printf("ser can not send data\n");
		}
		if(strcmp(buff,"exit")==0)
			break;
		
		printf("client recive data :%s\n",buff);
	}

	printf("client exit \n");
	close(fd);
}








