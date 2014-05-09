#include<iostream>
using namespace std;
void total(int a,int b,int c,int d)
{
int tot;
tot=a+b+c+d;
cout<<"total="<<tot;
}

void total(int a,int b,int c)
{
int tot;
tot=a+b+c;
cout<<"total="<<tot;
}



main()
{
int math,sci,phy,en;
cout<<"enter the marks for subject\n";
cin>>math>>sci>>phy;
total(math,sci,phy);
//total(math,sci,phy,en);


}
