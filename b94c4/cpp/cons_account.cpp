#include<iostream>
using namespace std;
class account
{
int acno,bal;
public:
account() //declare as a constructor
{
cout<<"enter the data\n";
cin>>acno>>bal;
}
void show()
{
cout<<"account no:"<<acno<<"  bal:"<<bal<<endl;
}
};
main()
{
account myac;
myac.show();
account mybac;
mybac.show();
}
