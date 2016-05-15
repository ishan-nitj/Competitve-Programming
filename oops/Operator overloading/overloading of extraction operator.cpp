#include<bits/stdc++.h>
using namespace std;

class point {
int x;int y;int z;
public:
void operator>>(istream & i){// pass by reference
i>>x;i>>y;i>>z;
}

void show(){
cout<<x<<y<<z;
}
friend void operator>>(istream&,point&);
};

void operator>>(istream & i,point &p){// Both cin and p have to be passed by reference
i>>p.x;i>>p.y;i>>p.z;
}

int main(){
point p1,p2,p3;
p3>>cin;// Why we cant use cin>>p3 in case of member functions.
cin>>p3;//We can use both cin>>p3 and p3>>cin in case of friend function// Just change the order of parameters passing
// WE CAN also use the usual function calling notation.
p3.show();
return 0;
}

