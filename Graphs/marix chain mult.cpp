#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e18
#define mag 100000
#define MOD 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define mset(x,v) memset(x, v, sizeof(x))
#define print_array(a,n) for(i=0;i<n;i++) cout<<a[i]<<" ";
#define var_val(x) cout<<#x<<" "<<x<<endl;
#define pb push_back
#define fe first
#define se second
ll a[mag],b[mag];
ll dp[1000][1000];
ll func(ll x,ll y){
if(dp[x][y]!=-1)
    return dp[x][y];
ll ans=inf;
if(y==x+1)
    ans= (a[x]*b[x]*b[y]);
else if(y==x)
    ans= 0;
else{
        for(ll i=x;i<y;i++)
            ans=min(ans,func(x,i)+func(i+1,y)+a[x]*b[i]*b[y]);
}
dp[x][y]=ans;
return ans;
}

int main()
{
ll t;cin>>t;
while(t--){
mset(dp,-1);
ll n,i;cin>>n;
rep(i,n)
cin>>a[i]>>b[i];
cout<<func(0,n-1)<<endl;
// not possible
}

}


