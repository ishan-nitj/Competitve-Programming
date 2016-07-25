//This code does not  assume that the graph is connected.
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define inf (ll)1e18
#define MOD 1000000007
#define print_array(a,n) for(i=0;i<n;i++) printf("%lld ",a[i]);
#define mset(x,v) memset(x, v, sizeof(x))
#define dbg1(x) cout<<#x<<" "<<x<<endl;
#define dbg2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define dbg3(x,y,z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define dbg4(x,y,z,k) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<" "<<#k<<" "<<k<<endl;
#define pb push_back
#define mag 10000

vector<ll>mp[mag+1];
ll nodes,edges;
ll vst[mag+1],depth[mag+1],low[mag+1],parent[mag+1],isAP[mag+1],childcount[mag+1];

void clear(){
    mset(vst,0);mset(depth,0);mset(low,0);mset(parent,0);mset(isAP,0);mset(childcount,0);
    mset(mp,0);
}

void dfs(ll x,ll d){
    vst[x]=1;
    depth[x]=d;
    low[x]=d;
    childcount[x]=0;
    for(auto it:mp[x]){
        if(!vst[it]){
            parent[it]=x;
            dfs(it,d+1);
            childcount[x]++;
            low[x]=min(low[x],low[it]);
            if(low[it]>=depth[x] && parent[x]!=-1)
                isAP[x]=1; 
            if(parent[x]==-1 && childcount[x]>1)
                isAP[x]=1;
        }
        else if(it!=parent[x])
            low[x]=min(low[x],depth[it]);
    }
}

void get_articulation_points(){
    mset(parent,-1);
    for(ll i=1;i<=nodes;i++){
        if(!vst[i])
            dfs(i,0);
    }
}

int main(){
    clear();
    cin>>nodes>>edges;
    while(edges--){
        ll x,y;cin>>x>>y;
        mp[x].pb(y);
        mp[y].pb(x);
    }
    get_articulation_points();
}
