#include<iostream>
using namespace std;
#define squ(x) x*x;
inline void square(int a)
{
int t;
t=a*a;
cout<<t<<endl;

}
main()
{
int x=5,y=5,b;
b=squ(++x);
cout<<b<<endl;
square(++y);

}
