#include"headers.h"
main(int argc,char **argv)
{
char datastring[20],timestring[20];
struct timeb t1,t2;
struct tm *tmptr;
int i,j;
while(1)
    {
     ftime(&t1);
     tmptr=localtime(&(t1.time));
     strftime(datastring,20,"%F",tmptr);
     strftime(timestring,20,"%T",tmptr);
     printf("%s %s:%d\n",datastring,timestring,t1.millitm);
     usleep(10000);
     system("clear");

}

}
