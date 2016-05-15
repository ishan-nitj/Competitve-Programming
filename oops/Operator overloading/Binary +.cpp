#include<bits/stdc++.h>
using namespace std;

class point {
int x;int y;int z;
public:
void get(){
cin>>x>>y>>z;
}
point operator+(point p2){
point p3;
p3.x=x+p2.x;
p3.y=y+p2.y;
p3.z=z+p2.z;
return p3;
}

void show(){
cout<<x<<y<<z;
}
friend point operator+(point ,point);
};

point operator+(point p1,point p2){
point p3;
p3.x=p1.x+p2.x;
p3.y=p1.y+p2.y;
p3.z=p1.z+p2.z;
return p3;
}

int main(){
point p1,p2,p3;
p1.get();
p2.get();
p3=p1+p2;// In case of member func, the left object is the calling object and right object is passses as parameter to the
// member function
// In case of friend function both the objects are passed as parameters.
// We can also use the usual function calling notation.
p3.show();
return 0;
}

// We can also have cases when one of parameters is not of object type. // like it can an integer//
