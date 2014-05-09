#include"headers.h"
main()
{
int id;
id=semget(12,1,IPC_CREAT|0644);
//if(id==-1)
perror("semget");
printf("pid:%d semid:%d \n",getpid(),id);
struct sembuf v;
printf("about to pend on sem\n");
v.sem_num=0;
v.sem_op=0;//types of sync
//v.sem_flg=0;//no flags chosen
semop(id,&v,1);
semctl(id,0,SETVAL,1);
//semop may be blocked or continue depends on
//the number of v
//the semop will blocked if val is not 0
//sleep(10);
printf("in critical region\n");
printf("after semop\n");

semctl(id,0,SETVAL,0);


}
