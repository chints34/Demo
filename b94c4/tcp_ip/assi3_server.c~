#include"headers.h"
main(int nf,char **argv)
{
        int ssocket=socket(AF_INET,SOCK_STREAM,0);
        struct sockaddr_in saddr,caddr,caddr1;
        int csocket,csocket2;
        int clen=sizeof(caddr);
        int clen1=sizeof(caddr1);
        char buff[100],buff1[100];
        int fir;
        int sec;

        bzero(buff,100);




        if(ssocket<0)
        {
                perror("socket");
                exit(0);
        }

        printf("socket is created \n");


        saddr.sin_family=PF_INET;
        saddr.sin_addr.s_addr=inet_addr("0.0.0.0");
        saddr.sin_port=htons(atoi(argv[1]));

        if(bind(ssocket,(struct sockaddr *)&saddr,sizeof(saddr))!=0)
        {
                perror("bind");
                return 0;
        }
        printf("bind is done\n");
                                  listen(ssocket,2);
        printf("server waiting for client req....\n");
        csocket=accept(ssocket,(struct sockaddr *)&caddr,&clen);


        int id1=shmget(atoi(argv[2]),120,IPC_CREAT|IPC_EXCL|0666);
        int id2=shmget(atoi(argv[3]),120,IPC_CREAT|IPC_EXCL|0666);

        printf("%d %d \n",id1,id2);

        char *p1=shmat(id1,NULL,0);
        char *p2=shmat(id2,NULL,0);

        printf("%p %p \n",p1,p2);
        /*---------------------------------------------------------------------------------------*/
        if(fork()==0)
        {
                while(1)
                {
                        if((fir=recv(csocket,buff,100,MSG_DONTWAIT))==0)
                        {
                                printf("client is remove\n");
                                bzero(buff,100);
                                write(csocket2,"bye",100);
				break;
                        }

                        if(strlen(buff)>0)
                             strcpy(p1,buff);


                        if(p2[0]!='\0')
                        {

                                if(strcmp(p2,"bye")==0)
                                {
                                        write(csocket,"bye",100);
                                        break;
                                }
                                else
                                write(csocket,p2,100);
                                memset(p2,0,100);
                       }
                       bzero(buff,100);
                }
              exit(0);

        }

        

        csocket2=accept(ssocket,(struct sockaddr *)&caddr1,&clen1);
        printf("don for second req.....\n");

        bzero(buff1,100);
        while(1)
        {


                        if((sec=recv(csocket2,buff1,100,MSG_DONTWAIT))==0)
                        {
                                printf("client is remove\n");
				
                                        write(csocket2,"bye",100);
				break;
                        }


                        if(strlen(buff1)>0)
                                strcpy(p2,buff1);



                        if(p1[0]!='\0')                                                         
 			{
                                if(strcmp(p1,"bye")==0)
                                {
                                        write(csocket2,"bye",100);
                                        break ;
                                }
                                else
                                write(csocket2,p1,100);
                                memset(p1,0,100);
                        }
                        bzero(buff1,100);

         }

	sleep(4);
        return 0;

}

