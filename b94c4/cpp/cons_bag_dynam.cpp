#include<iostream>
using namespace std;
class bag
{
private:
int *content;
int itmcnt;
public:
bag(static int size)
{
content=new bag[size];
itmcnt=0;
}
/*bag(int gi)
{
content[0]=gi;
itmcnt=1;
}
bag(int gi1,int gi2)
{
content[0]=gi1;
content[1]=gi2;
itmcnt=2;

}*/
void put(int pi)
{

content[itmcnt]=pi;
itmcnt++;
if(itmcnt>size)
{
cout<<"limit is over\n";
break;
}
}
void dump()
{
for(int i=--itmcnt;i>=0;i--)
cout<<"content["<<i<<"]="<<content[i]<<endl;
}

};
main()
{
char ch;
cout<<"a:normal user\n"<<"b:regular user\n"<<"c:vip user\n";
cin>>ch;
  if(ch=='a')
  {
int s;
cout<<"what size of bag u want\n";
cin>>s;
     bag nc(s);
     int pit;
     while(1)
       {
           cout<<"enter the item\n";
           cin>>pit;
           if(pit==0)
            break;
             nc.put(pit);
        }
    nc.dump();
  }
/*else if(ch=='b')
  {

    bag rc(100);
    int pit;
      while(1)
         {
           cout<<"enter the item\n";
		cin>>pit;
		if(pit==0)
		break;
		rc.put(pit);
	}
	rc.dump();
  }
else if(ch=='c')
	{
	  bag vipc(100,200);
	  int pit;
	  while(1)
		{   
		  cout<<"enter the item\n";
		  cin>>pit;
		  if(pit==0)
		  break;
		  vipc.put(pit);
                 }
            vipc.dump();
        }*/
}
