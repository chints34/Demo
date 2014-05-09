//copy constructor with dynamic memory allocation
#include<iostream>
using namespace std;
class vector
{
private:
int *v;
int size;
public:
vector(int s);
vector(vector &po);
void get();
void show();

};
vector:: vector(int s)
{
v=new int[s];
size=s;
}
vector::vector(vector &po)
{
size=po.size;
v=new int[size];
for(int i=0;i<size;i++)
{
v[i]=po.v[i];
}

}
void vector::get()
{
for(int i=0;i<size;i++)
{
cout<<"enter value for v["<<i<<"] "<<"\n";
cin>>v[i];
}
}
void vector::show()
{
int sum=0;
for(int j=0;j<size;j++)
{
cout<<"element of v["<<j<<"]="<<v[j]<<endl;
sum=sum+v[j];
}
cout<<"summation of vector="<<sum<<endl;
}

main()
{
int wsv;
cout<<"what size of vector u want\n";
cin>>wsv;
vector vo(wsv);
vo.get();
vo.show();
//copy to the another objct
vector v2(vo);
v2.show();

}
