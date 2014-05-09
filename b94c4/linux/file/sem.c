#include"headers.h"
main()
{
int id;
id=semget(1,3,IPC_CREAT|0660);
printf("pid:%d  id:%d\n",getpid(),id);

}
