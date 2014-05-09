#include<iostream>
using namespace std;
int x=30;
main()
{
/*int x=10;
cout<<x<<"\n";
//cout<<::x<<"\n";
{
int x=20;
cout<<x<<"\n";
//cout<<::x<<"\n";
*/
int x=10;
cout<<"sum="<<x+::x<<"\n";
cout<<"sub="<<x-::x<<"\n";
cout<<"mul="<<x*::x<<"\n";
cout<<"div="<<::x/x<<"\n";


}
