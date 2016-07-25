#include <bits/stdc++.h>
using namespace std;
#define dbg1(x) cout<<#x<<" "<<x<<endl;
#define dbg2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define dbg3(x,y,z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define dbg4(x,y,z,k) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<" "<<#k<<" "<<k<<endl;
#define pb emplace_back
#define fe first
#define se second
#define ll long long
#define mag 50000
#define inf 1000000000000000000
#define MOD 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define mset(x,v) memset(x, v, sizeof(x))
#define print_array(a,n) for(i=0;i<n;i++) printf("%lld ",a[i]);

vector<ll>mp[mag+1];
ll vst[mag+1];
vector<ll>child[mag+1];
ll level[mag+1];//level starts with 0
vector<ll>lev[mag+1];//max level for tree with n nodes is n-1//it contains nodes at each level.
ll maxlevel;
//ll dp[50001][501];

void dfs(ll x){//store children of each node
	vst[x]=1;
	for(auto it:mp[x]){
		if(!vst[it]){
			dfs(it);
			child[x].pb(it);
		}
	}
}

void bfs(ll start){//to calculate level of each node
	mset(vst,0);
	queue<ll>q;
	q.push(start);
	vst[start]=1;
	level[start]=0;
	lev[0].pb(start);
	while(!q.empty()){
		ll x=q.front() ;
		q.pop();
		for(auto it:mp[x]){
			if(!vst[it]){
				q.push(it);
				level[it]=level[x]+1;
				maxlevel=max(maxlevel,level[it]);
				lev[level[it]].pb(it);
				vst[it]=1;
			}
		}// for end
	}// while end
}

void iterdp(){
ll i,j;
for(i=maxlevel;i>=0;i--){
	for(auto it:lev[i]){
		if(mp[it].size()==0){//leaf node


		}
		else{//not leaf node
		
		}

	}//inner loop


}//outer loop

}

int main(){
	ll n,k;cin>>n>>k;
	ll i;
	for(i=1;i<n;i++){
		ll x,y;cin>>x>>y;
		mp[x].pb(y);mp[y].pb(x);
	}
	dfs(1);bfs(1);
}
