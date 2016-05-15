// important
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
#define mag 100
#define inf 1e18
#define enter printf("\n")
#define space printf(" ")
#define MOD 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define mset(x,v) memset(x, v, sizeof(x))
#define print_array(a,n) for(i=0;i<n;i++) cout<<a[i]<<" ";
#define var_val(x) cout<<#x<<" "<<x<<endl;
#define vl vector<ll>
#define pb push_back

ll dp[mag][mag];
string s;
ll lps(ll i,ll j){
//cout<<i<<j<<endl;
ll ans;
if(dp[i][j]!=-1)
    return dp[i][j];
if(i==j)
     ans=1;
else if(j==i+1 && s[j]==s[i])
    ans= 3;
else if(j==i+1 && s[j]!=s[i])
    ans= 2;
else {
if(s[i]==s[j])
    ans=1 +(lps(i+1,j)+lps(i,j-1));
else
    ans= (lps(i+1,j)+lps(i,j-1))-lps(i+1,j-1);
}
dp[i][j]=ans;
return ans;
}

int main(){
//freopen("IP.txt","r",stdin);

ll t;sl(t);
while(t--){
mset(dp,-1);
cin>>s;
cout<<lps(0,s.size()-1);
enter;
}
}


