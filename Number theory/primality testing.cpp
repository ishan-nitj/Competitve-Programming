//
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)

#define enter printf("\n")
#define space printf(" ")
#define MOD 10000007

#define rep(i,n) for(i=0;i<n;i++)
#define loop(i,a,b) for(i=(a);i<=(b);i++)
#define mset(x,v) memset(x, v, sizeof(x))

bool isprime(ll n){
if(n<=1)// all negative numbers 0 and 1 are not prime
return false;
ll i;
for(i=2;i<=sqrt(n);i++){// <=sqrt(n)
if(n%i==0)
return false;
}
return true;
}

int main(){
cout<<isprime(1000000009);

return 0;
}
