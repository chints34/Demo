#include<iostream>
using namespace std;
class complex
{
private:
int ip,rp;
public:
complex()
{
cout<<"enter ip and rp\n";
cin>>rp>>ip;
}
complex(int x,int y)
{
rp=x;
ip=y;

}
void show()
{
cout<<"complex number is:"<<rp<<"+i"<<ip<<endl;
}
};
main()
{
complex fc;
fc.show();
complex sc(2,3);
sc.show();
}
