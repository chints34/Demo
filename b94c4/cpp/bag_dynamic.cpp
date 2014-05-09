#include<iostream>
using namespace std;
class bag
{
private:
int *content;
int size;
public:
bag()
{}
bag(int a,int b)
{
cout<<"hello\n";
}
bag(int s);
void get();
void show();
};
 bag::bag(int s)
{
content=new int[s];
size=s;
}
void bag::get()
{
for(int i=0;i<size;i++)
{
cout<<"enter the element for content["<<i<<"]=";
cin>>content[i];
cout<<endl;
}
}
void bag::show()
{
for(int i=--size;i>=0;i--)
{
cout<<"element of content["<<i<<"]="<<content[i]<<"\n";
}
}
main()
{
int sb;
cout<<"what size  of bag u want\n";
cin>>sb;
//bag cus;
//cus=sb;

bag cus(sb);
cus.get();
cus.show();
}

