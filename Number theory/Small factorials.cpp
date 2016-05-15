#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
#define ss(n) scanf("%s",n);

#define MOD 10000007

#define rep(i,n) for(i=0;i<n;i++)
#define loop(i,a,b) for(i=(a);i<=(b);i++)
#define mset(x,v) memset(x, v, sizeof(x))

void  func(ll k,vector<ll>&fact){
ll temp=0,x,i;
for( i=0;i<fact.size();i++)
 {x=(fact[i]*k+temp);
 fact[i]=x%10;
 temp=x/10;
    }
while(temp!=0){
 fact.push_back(temp%10);
 temp=temp/10;
 }
}

int main(){
ll t;sl(t);
while(t--){
ll n,temp=0,x,i;
sl(n);
vector<ll>fact;
for(i=1;i<=n;i++){
if(i==1){
fact.push_back(1);
continue;
}
func(i,fact);
}
for(int i=fact.size()-1;i>=0;i--){
cout<<fact[i];
}
cout<<endl;
}
}
