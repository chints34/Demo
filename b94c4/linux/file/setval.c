#include"headers.h"
main(int argc,char **c)
{
int id,index,semval;
index=atoi(c[1]);
semval=atoi(c[2]);
id=semget(1,3,IPC_CREAT|0660);
if(semctl(id,index,SETVAL,semval)==-1)
{
perror("semctl");
return;
}
else
printf("sucess\n");
printf("pid:%d  id:%d\n",getpid(),id);
printf("index:%d semval:%d\n",index,semval);
}
