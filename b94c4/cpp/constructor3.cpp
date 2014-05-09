//constructor overloading
//default constructor and parameter passing constructor
#include<iostream>
using namespace std;
class date
{
int d,m,y;
public:
date()
{
cout<<"enter the value\n";
cin>>d>>m>>y;
}
date(int a,int b,int c)
{
d=a;
m=b;
y=c;
}

void showdate()
{
cout<<"date:"<<d<<"-"<<m<<"-"<<y<<endl;
}
};
main()
{
date tod;
tod.showdate();
date yday(12,11,2002);
yday.showdate();

}
