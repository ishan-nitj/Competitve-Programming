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

ll memo[500],memo2[500];
ll memofib(ll n){// Memoized Version// Top down
ll f;
if(memo[n]!=-1)
return memo[n];
else if(n==0 || n==1)
f=1;
else
f=memofib(n-1)+memofib(n-2);
memo[n]=f;
return f;
}

ll bottomupfib(ll n){// Bottom up approach
ll i,f;
loop(i,0,n){
if (i==0 || i==1)
f=1;
else
f=memo2[i-1]+memo2[i-2];
memo2[i]=f;
}
return f;
}

int main(){//1 1 2 3 5 8
ios_base::sync_with_stdio(0);
mset(memo,-1);

return 0;
}

