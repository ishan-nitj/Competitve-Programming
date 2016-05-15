//Fraction class in c++.
//ishan_nitj
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
#define enter printf("\n")
#define space printf(" ")
#define MOD 1000000007
#define mag 1000000
#define rep(i,n) for(i=0;i<n;i++)
#define loop(i,a,b) for(i=(a);i<=(b);i++)
#define mset(x,v) memset(x, v, sizeof(x))
#define parray(a,x,y) for(i=x;i<y;i++) {pl(a[i]); enter;}

ll gcd(ll a,ll b){
ll temp;
if(a<b){
temp=a;a=b;b=temp;
}
while(b!=0){
temp=a;
a=b;
b=temp%b;
}
return a;
}

//1) - sign always remains with num.
//2)If num=0 ,fraction is 0 1.
//3) Make sure that deno is not zero.

class fraction{
ll num,deno;
public:
fraction(ll x,ll y){
ll gcd_=gcd(abs(x),abs(y));
if(y<0)
{
y=-y;
x=-x;
}
num=x/gcd_;
deno=y/gcd_;
}
void show(){
cout<<num<<" "<<deno;
}
friend bool operator == (fraction ,fraction);
friend bool operator >= (fraction ,fraction);
friend bool operator <= (fraction ,fraction);
friend bool operator > (fraction ,fraction);
friend bool operator < (fraction ,fraction);
friend bool operator != (fraction ,fraction);
};


bool operator ==(fraction f1,fraction f2){
return(f1.num==f2.num && f1.deno==f2.deno);
}

bool operator >(fraction f1,fraction f2){
return(f1.num*f2.deno > f2.num==f1.deno);
}

bool operator >=(fraction f1,fraction f2){
return(f1.num*f2.deno >= f2.num==f1.deno);
}

bool operator <(fraction f1,fraction f2){
return(f1.num*f2.deno < f2.num==f1.deno);
}

bool operator <=(fraction f1,fraction f2){
return(f1.num*f2.deno <= f2.num==f1.deno);
}

bool operator !=(fraction f1,fraction f2){
return(f1.num!=f2.num ||  f1.deno==f2.deno);
}

fraction min(fraction f1,fraction f2){
if(f1<f2)
return f1;
else
return f2;
}

fraction max(fraction f1,fraction f2){
if(f1>f2)
return f1;
else
return f2;
}


int main(){


}
