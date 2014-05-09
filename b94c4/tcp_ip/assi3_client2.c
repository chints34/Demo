#include"headers.h"

main(int nf,char **argv)
{
        int csocket=socket(AF_INET,SOCK_STREAM,0);
        char name[20];

        struct sockaddr_in saddr;

        if(csocket<0)
        {
                perror("socket");
                exit(0);
        }
        printf("socket is created\n");


        saddr.sin_family=PF_INET;

        saddr.sin_port=htons(atoi(argv[1]));
        saddr.sin_addr.s_addr=inet_addr("127.0.0.1");

        if(connect(csocket,(struct sockaddr *)&saddr,sizeof(saddr))<0)
        {
                perror("connect");
                return 0;
        }
        printf("connection is done .....\n");


        char buff[100];
        while(1)
        {


                bzero(buff,100);
 printf("cl1 waiting for data .....\n");
                if(read(csocket,buff,100)<=0)
                {
                        printf("ser can not send data\n");
                }
                if(strcmp(buff,"exit")==0)
                        break;
                printf("client recv:%s\n",buff);

                printf("enter the data :");
                scanf(" %[^\n]s",buff);
                send(csocket,buff,100,0);

                if(strcmp(buff,"bye")==0)
                        break;

                printf("client recive data :%s \n",buff);
        }

        printf("client exit \n");
        close(csocket);
}


