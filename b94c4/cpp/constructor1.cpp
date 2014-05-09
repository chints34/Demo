//parameter passing  constructor
#include<iostream>
using namespace std;
class date
{
int d,m,y;
public:
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
date tod(27,12,2013);
tod.showdate();
date yday(26,12,2013);
yday.showdate();

}
