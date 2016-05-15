#include<bits/stdc++.h>
using namespace std;

class point {
int x;int y;int z;
public:
void get(){
cin>>x>>y>>z;
}

void show(){
cout<<x<<y<<z;
}
};

// void operator ++(point &p,int)

int main(){
point p;
p.get();
p.show();
return 0;
}
