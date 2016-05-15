//O(n^2)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e18
#define MOD 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define mset(x,v) memset(x, v, sizeof(x))
#define print_array(a,n) for(i=0;i<n;i++) cout<<a[i]<<" ";
#define var_val(x) cout<<#x<<" "<<x<<endl;
#define pb push_back
#define fe first
#define se second
ll arr[123456],dp[123456];

int main(){
ll t;cin>>t;
while(t--){
ll n,i;cin>>n;
mset(dp,0);mset(arr,0);
rep(i,n)
cin>>arr[i];
dp[0]=1;
for(i=1;i<n;i++){
    dp[i]=1;
    for(ll j=i-1;j>=0;j--){
        if(arr[j]<arr[i])
            dp[i]=max(dp[i],1+dp[j]);
    }
}
ll ans=*max_element(dp,dp+n);
cout<<ans<<endl;
vector<ll>v;
for(i=n-1;i>=0;i--){
  if(dp[i]==ans){
        v.pb(arr[i]);
        ans--;}
}
sort(v.begin(),v.end());
print_array(v,v.size());
cout<<endl;
}//test case end
}
// 1 2 1 3 2 4 4 5 6

