#include<bits/stdc++.h>
using namespace std;
class A{
int a[10];
public:
int& operator[](int x){
return a[x];
}
void display(int x){
cout<<a[x];
}
};
//
int main(){
A a;
a[8]=91;
a.display(8);
return 0;
}
// We can also overload [] when we have array of objects.

