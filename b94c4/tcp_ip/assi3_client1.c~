#include"headers.h"

void *print(void *p)
{
        int fd=*(int *)p;
        char buff[100];
                while(1)
                {
                        if(recv(fd,buff,100,0)>0)
                        {
                                printf("client:%s\n",buff);
			if(strcmp(buff,"bye")==0)
				exit(0);
                                bzero(buff,100);
                        }
                }

                return NULL;
}



main(int nf,char **argv)
{
        int csocket=socket(AF_INET,SOCK_STREAM,0);
        char name[20];
        pthread_t thr;
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);


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

        if(connect(csocket,(struct sockaddr *)&saddr,sizeof(saddr))==-1)
                {
                perror("connect");
                return 0;
        }
        printf("connection is done .....\n");
        pthread_create(&thr,&attr,print,&csocket);

        char buff[100];
        while(1)
        {

            //   /printf("enter the data :");
                scanf(" %[^\n]s",buff);
                send(csocket,buff,100,0);

                if(strcmp(buff,"bye")==0)
                        break;

                bzero(buff,100);


        }

        printf("client exit \n");
        close(csocket);
}

