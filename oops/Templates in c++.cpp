#include<bits/stdc++.h>
using namespace std;
template<class T,class U>
class point{
T x;U y;
void get(){
cin>>x>>y;
}
void print(){
cout<<x<<y;
}
};

template<class W>
void printanumber(W a){
cout<<a;
}

int main(){
point<int,double>p1;
printanumber(12.23);cout<<endl;
printanumber(12);
}
