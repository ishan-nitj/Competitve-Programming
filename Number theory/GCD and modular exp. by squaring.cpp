#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
#define ss(n) scanf("%s",n);
#define MOD 7
#define rep(i,n) for(i=0;i<n;i++)
#define loop(i,a,b) for(i=(a);i<=(b);i++)
#define mset(x,v) memset(x, v, sizeof(x))

ll gcd(ll a,ll b){
ll temp;
//if(a<b){
//temp=a;a=b;b=temp;
//}
while(b!=0){
temp=a;
a=b;
b=temp%b;
}
return a;
}

ll modexp(ll x,ll y,ll n){// This can also be done using recursive approach
ll ld,temp,ans=1;
ld =y%2;
y=y/2;
temp=x%n;
if(ld==1)
ans=temp;
while(y!=0){
ld =y%2;
y=y/2;
temp=(temp*temp)%n;
if(ld==1){
ans=(ans*temp)%n;
}
}
return ans;
}

ll mmi(ll x,ll y){/////////imp
////first check whether this is applicable or not
return (modexp(x,y-2,y));
}

ll div1(ll x,ll y){
return ( (x%MOD)*(mmi(y,MOD)%MOD) )%MOD;
}

ll pro(ll x,ll y){
return ((x%MOD)*(y%MOD))%MOD;
}
int main(){
cout<<pro(3,4);
}
