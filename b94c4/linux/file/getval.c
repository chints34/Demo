#include"headers.h"
main(int argc,char **c)
{
int id,index,semval;
index=atoi(c[1]);
id=semget(1,3,IPC_CREAT|0660);
semval=semctl(id,index,GETVAL);
printf("pid:%d  id:%d\n",getpid(),id);
printf("index:%d semval:%d\n",index,semval);
}
