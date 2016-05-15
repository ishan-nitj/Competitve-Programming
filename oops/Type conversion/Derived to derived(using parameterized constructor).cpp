#include<iostream>
using namespace std;
// Note the order of declaring classes.
class B{
int no;int price;
public:
void get(){
cin>>no>>price;
}
friend class A;// Important
};

class A{
int tp;
public:
void get(){
cin>>tp;
}
A(B b){
tp=b.no*b.price;
}
A(){// Default constructor also needed

}
void display(){
cout<<tp;
}
};

int main(){
A a;B b;
b.get();
a=b;// constructor created in class whose object is on LHS
a.display();
}
