//Note that this code further requires optimizations for SPOJ.
//Ishan Bansal
//handle:ishan.nitj at codeforces ,ishan_nitj at codechef
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lll __int128
#define mag 1000000
#define inf 1000000000000000000
#define MOD 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define mset(x,v) memset(x, v, sizeof(x))
#define print_array(a,n) for(i=0;i<n;i++) printf("%lld ",a[i]);
#define dbg1(x) cout<<#x<<" "<<x<<endl;
#define dbg2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define dbg3(x,y,z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define dbg4(x,y,z,k) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<" "<<#k<<" "<<k<<endl;
#define pb push_back
#define fe first
#define se second

ll dp[20][1<<20];
ll arr[20][20];
ll n;
ll count_one(ll n){
	ll count=0;
	while(n){
		n=n&(n-1);
		count++;
	}
	return count;
}

ll func(ll idx,ll mask){
if(dp[idx][mask]!=-1)
return dp[idx][mask];
ll ans=0;
if(count_one(mask)==1){
	ll curr=(log2(mask));
	if(arr[idx][curr]==1 )
		ans= 1;
}
else{
for(ll k=0;k<n;k++){
	if(arr[idx][k]==1 && mask&(1<<k))
		ans+=func(idx-1,mask&~(1<<k));
}
}//else end
dp[idx][mask]=ans;
return ans;
}

int main(){
std::ios::sync_with_stdio(false);
cin.tie(0);
	ll c;cin>>c;
	while(c--){
		mset(dp,-1);
		ll i,j,k;cin>>n;
		rep(i,n)
			rep(j,n)
			cin>>arr[i][j];
	cout<<func(n-1,(1<<n)-1)<<endl;
	}
}

