#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
#define mag 100000000 //10^8
#define inf 1e18
#define enter printf("\n")
#define space printf(" ")
#define MOD 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define mset(x,v) memset(x, v, sizeof(x))
#define print_array(a,n) for(i=0;i<n;i++) cout<<a[i]<<" ";
#define var_val(x) cout<<#x<<" "<<x<<endl;
#define pb push_back
ll dp[50][1<<15];

vector<ll> primefactors(ll n){
ll i;
vector<ll>v;
for(i=2;i<=n;i++)
    if(n%i==0){
        v.pb(i);
    while(n%i==0)
        n=n/i;
    }
return v;
}

int main()
{
//freopen("IP.txt","r",stdin);
ll t,i;sl(t);
ll prime[15]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
unordered_map<ll,ll>mp;
for(i=0;i<15;i++)
    mp[prime[i]]=i;
while(t--){
mset(dp,0);
ll n,i,j;sl(n);
ll arr[n];
rep(i,n)
cin>>arr[i];

vector<ll>vtemp=primefactors(arr[n-1]);
vector<ll>v;
for(auto it:vtemp)
    v.pb(mp[it]);

for(i=0;i<(1<<15);i++){
    bool flag=1;
    for(auto it:v)
        if(!(i&(1<<it)))
            flag=0;
if(flag)
    dp[n-1][i]=1;
else
    dp[n-1][i]=0;
}

for(ll k=n-2;k>=0;k--){
vector<ll>vtemp=primefactors(arr[k]);
vector<ll>v;
for(auto it:vtemp)
    v.pb(mp[it]);

    for(i=0;i<(1<<15);i++){
    bool flag=1;
    for(auto it:v)
        if(!(i&(1<<it)))
            flag=0;
    if(flag){
        ll temp=i;
        for(auto it:v)
            temp&= ~(1 << it);
        dp[k][i]=max(dp[k+1][i],1+dp[k+1][temp]);
    }
    else
        dp[k][i]=dp[k+1][i];
    }

}
//for(i=0;i<(1<<5);i++){
//binary(i);cout<<"->"<<dp[n-1][i]<<endl;
//}
cout<<dp[0][(1<<15)-1]<<endl;


}////


}


