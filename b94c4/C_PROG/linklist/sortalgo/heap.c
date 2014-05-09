#include<stdio.h>
#define leftchild(i) (2*i)+1
void sort(int *,int);
void sift(int *,int,int);
main()
{
int a[7]={55,22,88,11,99,44,33},i;
printf("unsorted array\n");
for(i=0;i<7;i++)
printf("%d\n",a[i]);
sort(a,7);
printf("sorted array\n");
for(i=0;i<7;i++)
printf("%d\n",a[i]);
}
void sort(int a[],int n)
{
int i,t;
for(i=(n/2)-1;i>=0;i--)

sift(a,i,n);

for(i=n-1;i>0;i--)
{
t=a[0];
a[0]=a[i];
a[i]=t;
sift(a,0,i);
}
}

void sift(int a[],int i,int n)
{
int child,temp;
for(temp=a[i];leftchild(i)<n;i=child)
{
child=leftchild(i);
if((child!=n-1)&&(a[child+1]>a[child]))
child++;
if(a[child]>temp)
a[i]=a[child];
else
break;

}
a[i]=temp;

}
