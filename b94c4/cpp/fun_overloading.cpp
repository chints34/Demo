#include<iostream>
using namespace std;
//void add(int,int=10,int=10);
void swap(int,int);
main()
{
swap(10);


}

void swap(int x,int y)
{
int t;
t=x;
x=y;
y=t;
cout<<x<<" "<<y<<"\n";
/*
int t;
t=x+y+z;
cout<<t<<endl;*/
}


