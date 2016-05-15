#include<bits/stdc++.h>
using namespace std;
// In this program we are returning a(private variable) by reference and hence we are able to modify it in main()
class A{
int a;
public:
int & func(){
return a;
}
void display(){
cout<<a;
}

};
//
int main(){
A a;
a.func()=10;
a.display();
return 0;
}
