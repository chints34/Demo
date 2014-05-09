#include<stdio.h>
#include<string.h>
main()
{
char str[10][20];
char max[10],min[10];
int i,cnt,pos;
for(i=0;i<10;i++)
{
printf("enter the string[%d]\n",i);
scanf("%s",str[i]);

}
strcpy(max,str[0]);
strcpy(min,str[0]);
for(i=0;i<10;i++)
{
if(strlen(max)<strlen(str[i]))
{
strcpy(max,str[i]);
cnt=i;
}
if(strlen(min)>strlen(str[i]))
{
strcpy(min,str[i]);
pos=i;
}

}
printf("max string=%s at %d\nmin string=%s at %d\n",max,cnt,min,pos);
}

