#include<stdio.h>
void input(char (*ptr)[2][10],int n1,int n2)
{
int i,j;
for(i=0;i<n1;i++)
for(j=0;j<n2;j++)
{
printf("enter the string str[%d][%d]\n",i,j);
scanf("%s",ptr[i][j]);

}
}
void print(char (*ptr)[2][10],int n1,int n2)
{
int i,j;
for(i=0;i<n1;i++)
for(j=0;j<n2;j++)
printf("%s\n",ptr[i][j]);

}
main()
{
char str[3][2][10];

input(str,3,2);
print(str,3,2);
}
