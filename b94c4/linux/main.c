#include<stdio.h>
#include<dlfcn.h>
main()
{
void *handle;
int (*ptr)(int,int);

int i,j,k;
printf("enter two integer\n");
scanf("%d%d",&i,&j);
printf("enter 1:sum\nenter 2:mul\n");
scanf("%d",&k);


if(k==1)
{
handle=dlopen("./libc.so",RTLD_LAZY);
ptr=dlsym(handle,"sum");
if(ptr==NULL)
{
printf("%s\n",dlerror());
return;
}
k=(*ptr)(i,j);
printf("k=%d\n",k);
dlclose(handle);
}
else if(k==2)
{
printf("k=%d\n",k);
handle=dlopen("./libc.so",RTLD_LAZY);
ptr=dlsym(handle,"mul");
k=(*ptr)(i,j);
printf("k=%d\n",k);
dlclose(handle);


}
else
return;

}
