////valid for only positive numbers
//Ishan Bansal
//handle:ishan.nitj at codeforces ,ishan_nitj at codechef
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1000000000000000000
#define MOD 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define print_array(a,n) for(i=0;i<n;i++) printf("%lld ",a[i]);
#define mset(x,v) memset(x, v, sizeof(x))
#define dbg1(x) cout<<#x<<" "<<x<<endl;
#define dbg2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define dbg3(x,y,z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define dbg4(x,y,z,k) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<" "<<#k<<" "<<k<<endl;
#define pb push_back
#define fe first
#define se second
#define mag 12
#define maxidx 501
#define maxsum 250001
ll sum;
vector<ll>arr;

ll dp[maxsum][maxidx];

ll f(ll rsum,ll idx){
//dbg2(rsum,idx);
if(dp[rsum][idx]!=0)
return dp[rsum][idx];
ll ans;
if(idx==0){
ans=rsum;
}
else{
ll r1=f(rsum+arr[idx],idx-1);
ll r2=f(rsum,idx-1);
if(abs(sum-2*r1)<abs(sum-2*r2))
ans=r1;
else
ans=r2;
}
return ans;
dp[rsum][idx]=ans;
}

ll fmain(){//valid for only positive numbers
mset(dp,0);
sum=0;
for(ll i=1;i<=arr.size()-1;i++)
sum+=arr[i];
return abs(sum-2*f(0,arr.size()));
}

int main(){
std::ios::sync_with_stdio(false);
cin.tie(0);
//freopen("OP.txt","r",stdin);
//freopen("IP.txt","w",stdout);
ll n;cin>>n;
ll i;
arr.pb(19);//garbage
for(i=1;i<=n;i++){
ll tmp;cin>>tmp;
arr.pb(tmp);
}
cout<<fmain();
} 


