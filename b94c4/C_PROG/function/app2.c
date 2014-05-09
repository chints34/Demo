#include<stdio.h>
#include<string.h>
void delete(char (*ptr)[2][10],int n1,int n2)
{
//int row,i,j;
//printf("enter the row number\n");
//scanf("%d",&row);
//for(i=0;i<2;i++)
//for(j=0;j<10;j++)

strcpy(ptr[0][0][0],"...................");
strcpy(ptr[0][0][1],"...................");

//printf("null%s",ptr[row]);

}
void menu(void)
{
printf("menu\n");
printf("p:print the all string\ni:input string\na:add the string\nd:delete the string\nm:modify the string\ne:exit\n");
}
void input(char (*ptr)[2][20],int n1,int n2)
{
int i,j;
for(i=0;i<n1;i++)
for(j=0;j<n2;j++)
{
if(j==0)
{
printf("enter the state [%d][%d] ",i,j);
scanf("%s",ptr[i][j]);
}
if(j==1)
{
printf("enter the capital [%d][%d] ",i,j);
scanf("%s",ptr[i][j]);
}
}
}
void print(char (*ptr)[2][20],int n1,int n2)
{
int i,j;
for(i=0;i<n1;i++,printf("\n"))
for(j=0;j<n2;j++)
{if(j==0)
printf("%d>%s ",i,ptr[i][j]);
else if(j==1)
printf("%s",ptr[i][j]);
}
}
main()
{
char str[5][2][20],ch;
printf("menu\n");
printf("p:print the all string\ni:input string\na:add the string\nd:delete the string\nm:modify the string\ne:exit\n");
scanf("%c",&ch);
while(ch!='e')
{
if(ch=='i')
{input(str,5,2);
menu();}
else if(ch=='p')
{print(str,5,2);
menu();}
else if(ch=='d')
{
delete(str,5,2);
print(str,5,2);
menu();
}
printf("enter choise\n");
scanf(" %c",&ch);
}
printf("===end====");
}
