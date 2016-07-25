//This BFS assumes the graph is connected.To check for bipartiteness(dont know whether term exists!)use BFSmain.
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mag 100000
#define inf (ll)1e18
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

ll nodes,edges;
ll level[mag+1];
ll color[mag+1];
vector<ll>mp[mag+1];
bool vst[mag+1];

void BFS(ll start){
    queue<ll>q;
    q.push(start);
    vst[start]=1;
    level[start]=0;
    color[start]=0;
    while(!q.empty()){
        ll x=q.front() ;
        q.pop();
        for(auto it:mp[x]){
            if(!vst[it]){
                q.push(it);
                level[it]=level[x]+1;
                color[it]=(level[it]%2==0?0:1);
                vst[it]=1;
            }
        }
    }// while end
}

bool isbipartite(){
    ll i,j;
    for(i=1;i<=nodes;i++)
    {
        for(auto it:mp[i]){
            if(color[it]==color[i])
                return false;
        }
    }
    return true;
}

int main()
{
    cin>>nodes>>edges;
    while(edges--){
        ll x,y;cin>>x>>y;
        mp[x].pb(y);
        mp[y].pb(x);
    }
    BFS(1);
    cout<<(isbipartite());
    return 0;
}
