#include"headers.h"

main(int argc,char **argv)
  {
   	int fd;
	struct sockaddr_in addr;
	if(argc!=2)
         {
          puts("client_executable server_ip wellknown_port\n");
          exit(0);
         }
 	 puts("creating client socket\n");
	fd=socket(AF_INET,SOCK_STREAM,0);
        if(fd<0)
         {
          perror("socket");
          exit(0);
         }
        puts("client socket created sucessfully\n");
       	
	addr.sin_family=AF_INET;
        addr.sin_addr.s_addr=inet_addr("192.168.101.138");
        addr.sin_port=htons(atoi(argv[1]));
        puts("connecting with server...\n");
        
	socklen_t len=sizeof(addr);
       if(connect(fd,(const struct sockaddr*)&addr,len)<0)
         {
          perror("connect");
          exit(0);
         }
       puts("connected with server\n");
       
	puts("Enter message to send\n");
       char buf[100];
     
     
          if(fork()==0)
          {
           while(1)
           {
	puts("Enter EXIT to close connection with server\n");
       gets(buf);
       puts("sending...\n");
         if(send(fd,buf,strlen(buf)+1,0)<=0)
           {
              perror("send");
              close(fd);
              exit(0);
      	   }
       	printf("client1 sent:%s\n ",buf);
        if(strcmp(buf,"exit")==0)
          {
           close(fd);
           break;
          }
          }
          }
             else
              {
              while(1)
              {

        bzero(buf,100);
        printf("client1 waiting or receiving...\n");
        if(recv(fd,buf,100,0)<=0)
          {
            puts("server terminated abnormally");
            close(fd);
            exit(0);
            //break;
          }
        printf("client received: %s\n",buf);
        if(strcmp(buf,"exit")==0)
          {
            close(fd);
            break;
          }
         }
         }
      	puts("Exiting client1\n");
        close(fd);
    }

 
