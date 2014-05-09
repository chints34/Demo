#include<stdio.h>
main()
{
int i=300;
char c='A';
double f=1.0;
int *ip=&i;
char *cp=&c;
double *dp=&f;
printf("%d %c %lf",i,c,f);
printf("\n");
printf("%d %c %lf",++(*ip),++(*cp),++(*dp));
}
