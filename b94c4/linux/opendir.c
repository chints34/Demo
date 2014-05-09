#include"headers.h"
main(int argc,char**p)
{
  DIR *dp;
  struct dirent *ptr;
  dp=opendir(p[1]);
 if(argc!=2)
  {
   dp=opendir(getenv("pwd"));
  }
 else
  {
   while(ptr=readdir(dp))
       {
	printf("%s\n",ptr->d_name);
       }
   }
}
