#include<iostream>
using namespace std;
// Note the order of declaring classes
class A{
int tp;
public:
void display(){
cout<<tp;
}
friend class B;// important
};

class B{
int no;int price;
public:
void get(){
cin>>no>>price;
}
operator A(){
A a;
a.tp=no*price;
return a;
}
};

int main(){
A a;B b;
b.get();
a=b;// casting operator will be member func. of the second class
a.display();
}
