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
ll dp[1001][1001];

int main(){
string s1,s2;cin>>s1>>s2;
ll n1=s1.size();ll n2=s2.size(),i,j;
mset(dp,0);
rep(i,n2){
if(s1[0]==s2[i])
dp[0][i]=1;
}
rep(i,n1){
if(s2[0]==s1[i])
dp[i][0]=1;
}
for(i=1;i<n1;i++)
    for(j=1;j<n2;j++)
        if(s1[i]==s2[j])
            dp[i][j]=dp[i-1][j-1]+1;
ll ans=0;
ll i1,j1;
for(i=0;i<n1;i++)
    for(j=0;j<n2;j++){
        if(dp[i][j]>ans){
            ans=dp[i][j];
            i1=i;j1=j;}
        }
cout<<ans<<endl;
if(ans>0)
cout<<s1.substr(i1-ans+1,ans);
}

// 1 2 1 3 2 4 4 5 6

