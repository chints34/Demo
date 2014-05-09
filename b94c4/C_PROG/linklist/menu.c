#include<stdio.h>
#include"headers.h"

  struct student *head=0;
main()
{
getdata();
char choice;
printf("menu:\n");
while(1)
{
printf("a:add new record:\n");
printf("p:print the data:\n");
printf("d:delete existing record:\n");
printf("e:exit:\n");
printf("s:save the record:\n");
printf("enter ur choise:\n");
scanf(" %c",&choise);
switch(choise)
{


case 'a':add();
        break;
case 'p':print();
	break;
case 'd':del();
	 break;
case 's':save();
	 break;
case 'e':return;
default:
printf("invalid choise\n");

}
}


}

