#include<stdio.h>
#include<string.h>
void menu(void)
{
printf("menu\n");
printf("a>add string\n");
printf("d>remove string\n");
printf("p>print\n");
printf("s>sort the array\n");
printf("r>reverse string\n");
printf("m>modify\n");
printf("e>exit\n");
}
void sort(char (*p)[10],int r)
{
int i,j;
char temp[10];
for(i=0;i<r;i++)
for(j=i+1;j<r;j++)
{
if(strcmp(p[i],p[j])>0)
{
strcpy(temp,p[i]);
strcpy(p[i],p[j]);
strcpy(p[j],temp);

}
}

}
void rev(char (*p)[10],int r)
{
int i,j;
char temp[10];
for(i=0,j=9;i<j;i++,j--)
{
strcpy(temp,p[i]);
strcpy(p[i],p[j]);
strcpy(p[j],temp);
}
}
void print(char (*p)[10],int r)
{
int i;
for(i=0;i<r;i++)
printf("%d>%s\n",i,p[i]);

}
void rem(char (*p)[10],int r)
{
int i,row;
printf("enter the row\n");
scanf("%d",&row);
strcpy(p[row],".........");

//for(i=0;i<r;i++)
//printf("%d>%s\n",i,p[i]);


}
void add(char (*p)[10],int r)
{
int row,i,j;
printf("enter the row\n");
scanf("%d",&row);
printf("enter the string:");
scanf("%s",p[row]);
}
void dot(char (*p)[10],int n)
{
int i,j;
for(i=0;i<10;i++,printf("\n"))
{
strcpy(p[i],".........");
printf("%d>%s",i,p[i]);
}
}
main()
{
char str[10][10];
char *p,ch;
printf("menu\n");
printf("a>add string\n");
printf("d>remove string\n");
printf("p>print\n");
printf("s>sort the array\n");
printf("r>reverse string\n");
printf("m>modify\n");
printf("e>exit\n");
dot(str,10);
scanf("%c",&ch);
while(ch!='e')
{
if(ch=='a')
{
add(str,10);
menu();
}
else if(ch=='p')
{
print(str,10);
menu();
}
else if(ch=='d')
{
rem(str,10);
menu();
}
else if(ch=='r')
{
rev(str,10);
menu();
}
else if(ch=='s')
{
sort(str,10);
menu();
}
printf("enter choise\n");
scanf(" %c",&ch);
}
printf(".... thank u using our app......\n");
}




