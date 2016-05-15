#include<bits/stdc++.h>
using namespace std;

class point {
int x;int y;int z;
public:
void get(){
cin>>x>>y>>z;
}
void operator-(){
x=-x;y=-x;z=-z;
}

void show(){
cout<<x<<y<<z;
}
friend void operator-(point&);
};

void operator-(point &p){// call by reference necessary
p.x=-p.x;
p.y=-p.y;
p.z=-p.z;
}

int main(){
point p;
p.get();
-p;//-p works both with friend and member func. p- doesnt work with both.
// we can also use function like calling notation p.operator-() for member function and operator-(p) for friend function
p.show();
return 0;
}
