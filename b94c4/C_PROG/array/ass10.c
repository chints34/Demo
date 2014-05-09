#include<stdio.h>
#include<string.h>
main()
{
char str[100],*ptr;
int i;
puts("enterstring:");
gets(str);
for(i=0;str[i];i++)
{
while(ptr=strchr(str+i+1,str[i]))
strcpy(ptr,ptr+1);

}
printf("string=%s\n",str);

}
