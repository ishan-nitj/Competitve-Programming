//Ishan Bansal
//handle:ishan.nitj at codeforces ,ishan_nitj at codechef
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lll __int128
#define pl(a) printf("%lld",a)
#define sl(a) scanf("%lld",&a)
#define ps printf("%s",a)
#define ss scanf("%s",&a)
#define mag 1000000
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
ll dp[11][1<<11];

ll n;
ll arr[11][11];
ll func(ll no,ll mask){
	//dbg2(no,mask);
	if(dp[no][mask]!=-1)
		return dp[no][mask];
	ll ans=0,j;
	if(no==0){
		for(j=0;j<n;j++)
			if(mask&(1<<j)){
				ans=arr[0][j];
			}
	}
	else{
		vector<ll>v;
		for(j=0;j<n;j++)
			if(mask&(1<<j))
				v.pb(arr[no][j]+func(no-1,mask&~(1<<j)));
		ans=(*max_element(v.begin(),v.end()));}
	dp[no][mask]=ans;
	return ans;
}

int main(){
	ll t;sl(t);
	while(t--){
		mset(dp,-1);
		n=11;//n is the no of players
		ll i,j,k;
		rep(i,n)
			rep(j,n){
				sl(arr[i][j]);
				if(arr[i][j]==0)
					arr[i][j]=-inf;
			}
		//cout<<func(1,5);
		pl(func(n-1,(1<<(n))-1));
		printf("\n");
	}
	return 0;
}
