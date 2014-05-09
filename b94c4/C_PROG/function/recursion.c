#include<stdio.h>
int cnt=0;
main()
{
//int cnt=0;
cnt++;
printf("hello\n");
if(cnt<=5)
main();
printf("welcome\n");
return;
}
