#include<iostream>
using namespace std;
class A{
int a;
public:
A(){
a=10;
}
~A(){// Destructor (Note that we cant just write ~A();
// Destructor cant take any arguement.
// The destructor is called when the object gets out of scope.
}
};


int main() {
A a;
return 0;
}
