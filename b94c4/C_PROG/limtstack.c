#include<stdio.h>
#include<stdlib.h>
#include<sys/resource.h>
void f()
{
char a[100000];
printf("in f:");

}
main()
{
struct rlimit v;
  if(getrlimit(RLIMIT_CPU,&v)==-1)
    {
     perror("getrlimit");
      return;
    }
  printf("%u\n",(unsigned int)v.rlim_cur);
  printf("%u\n",(unsigned int)v.rlim_max);


}
