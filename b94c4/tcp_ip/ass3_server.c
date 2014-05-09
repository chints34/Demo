#include"headers.h"

main(int argc,char **argv)
 {
 int sfd;
 int fd1,fd2;

puts("opening fifo...\n");
fd1=open("fifo1",O_RDWR);
fd2=open("fifo2",O_RDWR);
puts("fifo opened\n");

struct sockaddr_in saddr;
        if(argc!=2)
          {
            puts("server_executable port_number\n");
            exit(0);
          }

puts("creating server socket\n");
        sfd=socket(AF_INET,SOCK_STREAM,0);
          if(sfd<0)
            {
                perror("socket");
                  exit(0);
            }
puts("server socket created successfully\n");

saddr.sin_family=AF_INET;
saddr.sin_addr.s_addr=inet_addr("0.0.0.0");
saddr.sin_port=htons(atoi(argv[1]));
memset(saddr.sin_zero,0,8);

puts("binding\n");
        socklen_t slen=sizeof(saddr);
        if(bind(sfd,(const struct sockaddr *)&saddr,slen)<0)
                                                                                                                                                     1,1           Top          {
          perror("bind\n");
          exit(0);
         }
puts("binding successfully\n");

puts("prepairing connection queue\n");
          if(listen(sfd,2)<0)
            {
             perror("listen");
             exit(0);
            }
puts("listen success\n");

        struct sockaddr_in caddr;
        int cfd;
        socklen_t clen=sizeof(caddr);
        char buff[100];
while(1)
{

puts("server waiting for connection from client...\n");
   cfd=accept(sfd,(struct sockaddr*)&caddr,&clen);
        if(cfd<0)
         {
          perror("accept");
          exit(0);
         }
puts("accepted\n");

if(fork()==0)
{

puts("server accepted connection from client\n");
   char *ip=(char *)inet_ntoa(caddr.sin_addr);
       unsigned short portNo=ntohs(caddr.sin_port);

printf("whose Ip is %s\n",ip);
printf("port No is %d\n",portNo);
printf("using descriptor %d\n",cfd);

     if(fork()==0)
     {

        while(1)
        {
        char buff[100];
        bzero(buff,100);
        printf("server is waiting for message from client...\n");

        if(recv(cfd,buff,100,0)<=0)
         {
          printf("client %d exited abnormally\n",(cfd-5));
          close(cfd);
          exit(0);
         }
         write(fd1,buff,20);
       printf("server received from client %d: %s\n",(cfd-5),buff);

        if(strcmp(buff,"exit")==0)
         {
          printf("closing connection with client %s\n",ip);
          printf("port No: %d\n",portNo);
          close(cfd);
          close(sfd);
          exit(0);
         }
        }//end of while
      }//end of fork

  else
      {
          while(1)
           {

           bzero(buff,100);

           read(fd2,buff,20);
           if(send(cfd,buff,strlen(buff)+1,0)<=0)
            {
              perror("send");
              close(cfd);
              break;
            }
          printf("sent client: %d %s\n",(cfd-5),buff);
           }
      }
}//end of fork



else
{

puts("server waiting for connection from client...\n");
   cfd=accept(sfd,(struct sockaddr*)&caddr,&clen);
        if(cfd<0)
         {
          perror("accept");
          exit(0);
         }

    if(fork()==0)
    {

                            puts("server accepted connection from client\n");

       char *ip=(char *)inet_ntoa(caddr.sin_addr);
       unsigned short portNo=ntohs(caddr.sin_port);
       printf("whose Ip is %s\n",ip);
       printf("port No is%d\n",portNo);
       printf("using descriptor %d\n",cfd);

      if(fork()==0)
      {

        while(1)
        {

        bzero(buff,100);
        printf("server is waiting for message from client...\n");

        if(recv(cfd,buff,100,0)<=0)
         {
          printf("client %d exited abnormally\n",(cfd-5));
          close(cfd);
          exit(0);
        }
        write(fd2,buff,20);
       printf("server received from client%d:%s\n",(cfd-5),buff);

       if(strcmp(buff,"exit")==0)
         {
          printf("closing connection with client %s\n",ip);
          printf("port No: %d\n",portNo);
          close(cfd);
          close(sfd);
          exit(0);
         }
       }
                      }//end of fork


    else
    {
        while(1)
        {
            bzero(buff,100);

          read(fd1,buff,20);
          if(send(cfd,buff,strlen(buff)+1,0)<=0)
           {
           perror("send");
           close(cfd);
           break;
           }
          printf("sent client:%d %s\n",(cfd-5),buff);
        }

    } //end of else

}

else
{

}

}

}

     while(1);
        close(sfd);
}


