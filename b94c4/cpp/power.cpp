#include<iostream>
using namespace std;
void power(int a,int b=2)
{
int i=0;
int t=1;
for(i=0;i<b;i++)
{
t=t*a; 
}
cout<<"output="<<t<<endl;

}
main()
{
int bv,pv;
char ch;
cout<<"enter the base value\n";
cin>>bv;
cout<<"would u like to enter the power\nprees 'y'or'Y'for yes\n";
cin>>ch;
if(ch=='y'||ch=='Y')
{
cout<<"enter the power\n";
cin>>pv;
power(bv,pv);

}
else
power(bv);


}
