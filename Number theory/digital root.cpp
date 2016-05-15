#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
#define enter printf("\n")
#define space printf(" ")
#define MOD 1000000007
#define mag 10000000
#define rep(i,n) for(i=0;i<n;i++)
#define loop(i,a,b) for(i=(a);i<=(b);i++)
#define mset(x,v) memset(x, v, sizeof(x))

ll func(ll n){
ll sum=0;
while(n){
sum+=(n%10);
n/=10;
}
if(sum>9)
sum=func(sum);
return sum;
}

ll solve(ll n){
if(n%9==0)
return 9;
else
return(n%9);
}

int main(){
ll i;
for(i=1;i<=1000;i++)
cout<<i<<" "<<func(i)<<" "<<solve(i)<<endl;
}

