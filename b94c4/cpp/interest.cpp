#include<iostream>
using namespace std;
void simplerate(int,int=1,int=3);
main()
{
int p,t,r;
cout<<"enter the money\n";
cin>>p;
//cout<<"enter the time\n";
//cin>>t;
//cout<<"enter the rate\n";
//cin>>r;
simplerate(p);
}
void simplerate(int a,int b,int c)
{
int interest;
interest=(a*b*c)/100;
cout<<interest;
}
