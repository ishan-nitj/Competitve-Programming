#include<bits/stdc++.h>
using namespace std;

class point {
int x;int y;int z;
public:
void show(){
cout<<x<<y<<z;
}

istream& operator>>(istream &i){
i>>x;i>>y;i>>z;return i;
}
friend istream& operator>>(istream & i,point &);
};

istream& operator>>(istream & i,point &p){
i>>p.x;i>>p.y;i>>p.z;
return i;
}


int main(){
point p1,p2,p3;
p3>>(p2>>cin);// Cascading using member function. use of (), must
cin>>p1>>p2;//Cascading using friend function
p2.show();
p3.show();
return 0;
}
