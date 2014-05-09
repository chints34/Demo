#include"headers.h"

main(int nf,char **argv)
{
	int csocket=socket(AF_INET,SOCK_DGRAM,0);
	
	struct sockaddr_in saddr,caddr;	
		
	if(csocket<0)
	{
		perror("socket");
		exit(0);
	}
	printf("socket is created\n");
	
		
	saddr.sin_family=PF_INET;
	
	saddr.sin_port=htons(atoi(argv[1]));
	saddr.sin_addr.s_addr=inet_addr("127.0.0.1");









	char buff[100];
	while(1)
{
		
		printf("enter the string :");
		scanf(" %[^\n]s",buff);
		int len=sizeof(saddr);		
		sendto(csocket, buff, strlen(buff)+1,0,(struct sockaddr *)&saddr,len);
		
		
		printf("client send:%s\n",buff);
		if(strcmp(buff,"bye")==0)
			break;

		bzero(buff,100);
		len=sizeof(caddr);		
		if(recvfrom(csocket,buff,100,0,(struct sockaddr *)&caddr,&len)<=0)
		{
			printf("ser can not send data\n");
		}
		if(strcmp(buff,"exit")==0)
			break;
		
		printf("client recive string :%s\n",buff);
	}

	printf("client exit \n");
	close(csocket);
}








