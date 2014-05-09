#include<stdio.h>
main()
{
int a[3] [3]={{11,22,33},{44,55,66},{77,88,99}};
printf("%d\n",sizeof(a));
printf("%d\n",sizeof(a[0]));
printf("%d\n",sizeof(a[0][0]));
int row,colm,i,j;
row=sizeof(a)/sizeof(a[0]);
colm=sizeof(a[0])/sizeof(a[0][0]);
for(i=0;i<row;i++)
for(j=0;j<colm;j++)
printf("a[%d][%d]=%d\n",i,j,a[i][j]);
printf("%u\n",a);
printf("%u\n",a+1);
printf("%u\n",*a+1);
printf("%u\n",a[1]+1);
}
