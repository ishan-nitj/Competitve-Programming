#include<bits/stdc++.h>
using namespace std;

class point {
int x;int y;int z;
public:
void get(){
cin>>x>>y>>z;
}
void operator++(){
x++;
y++;
z++;
}

void show(){
cout<<x<<y<<z;
}
friend void operator++(point&);
};

void operator++(point &p){// pass by reference necessary
p.x++;
p.y++;
p.z++;
}

int main(){
point p;
p.get();
++p;//only ++p works both with friend and member func. p++ doesnt work with both.(in case of prefix)
// we can also use function like calling notation p.operator++() for member function and operator++(point) for friend function
p.show();
return 0;
}
